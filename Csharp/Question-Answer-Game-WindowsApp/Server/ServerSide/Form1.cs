/*Multiplayer Quiz Game Step2
 *
 *  Server
 * 
 * Created by 
 * Baris Batuhan Topal, Arda Asik, Ibrahim Bugra Demir.
 */
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ServerSide
{
    public partial class Form1 : Form
    {
        //initialized server socket on inter network with tcp protocol.
        static Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        delegate void StringArgReturningVoidDelegate(string text);

        static List<Socket> clientSockets = new List<Socket>(); //initialized client list

        //Global variables
        static string question;
        static string answer;

        static int disconnectedClients = 0; //count for disconnected clients
        static int noOfRounds;    //no of rounds game will continue for
        static int turn = 0;      //number of rounds game have been played for so far

        static bool terminate = false;
        static bool gameStarted = false;
        static bool DisconnectedQ = false;

        static string[] names = new string[200];  //Holds names for easier name check.
        static int[] scores = new int[200];   //Holds scores of the clients.

        public Form1()
        {
            InitializeComponent();
        }

        // Button Functions 

        private void listenBtn_Click(object sender, EventArgs e)        //on listen button click
        {
            int portNum;

            if (portBox.Text != "")
            {
                portNum = int.Parse(portBox.Text); //Get the port from the server client.

                try
                {
                    // To make server listen
                    IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, portNum); //set ip as the local ip.
                    serverSocket.Bind(endPoint);        //bind the server socket and start listening.
                    serverSocket.Listen(3);
                    SetText("Server is listening...");
                    // Creates the accept thread
                    Thread acceptThread = new Thread(Accept);
                    acceptThread.Start();
                }
                catch
                {
                    SetText("There is a problem! Check the port number and try again!");
                }
            }

            else
            {
                SetText("The port number is not entered correctly!");
            }
        }

        // Thread Functions

        private void Accept()           //Accept function allows clients to connect.
        {
            while (!terminate) //if the server is not terminating and game not started
            {
                try
                {
                    Socket newClient = serverSocket.Accept();
                    if (!gameStarted)
                    {
                        string name = ReceiveMessage(newClient);    //recive the name of the client trying to connect.
                        bool duplicate = false;
                        for (int i = 0; i < clientSockets.Count(); i++)
                        {
                            if (name == names[i]) //If the name is taken before
                            {
                                duplicate = true;
                                SetText("Player with a duplicate name tried to connect!");
                                SendMessage(newClient, "Duplicate name, please choose another name!");
                            }
                        }

                        if (!duplicate)
                        {
                            clientSockets.Add(newClient);   //Add new client to the list.
                            SendMessage(newClient, "Connection to the server established...");
                            names[clientSockets.Count() - 1] = name;
                            string message = name + " named client is connected.";
                            SetText(message);
                            //PrintToAllClients("Enough number of players connected.");  //inform the clients that game is starting.
                        }   //If the name is taken inform the client to enter a new name.                        
                    }
                    else
                    {
                        SendMessage(newClient, "Sorry, game is already started!");
                        SetText("A client tried to connect after game is started.");
                    }
                }
                catch
                {
                    SetText("Problem occured in accept function...");
                }
            }
        }

        private void Answer(int j)
        {
            if (clientSockets[(turn + j) % clientSockets.Count()] != null) //if the client is not disconnected client
            {
                try
                {
                    AnswerProcess(clientSockets[(turn + j) % clientSockets.Count()], names[(turn + j) % clientSockets.Count()]);
                }
                catch
                {
                    SetText("Client is disconnected during answer turn!"); //error message if any player disconnected
                    clientSockets[(turn + j) % clientSockets.Count()] = null;
                    //names[(turn + j) % clientSockets.Count()] = "";
                    disconnectedClients++;
                    if (clientSockets.Count() - disconnectedClients == 1) //check for if there are only 1 player left or not
                    {
                        SetText("Only 1 Player left. Game is finished!");
                        PrintToAllClients("Only 1 Player left. Game is finished");
                        terminate = true;

                        for (int i = 0; i < clientSockets.Count(); i++)
                        { //announce the winner
                            if (clientSockets[i] != null)
                            {
                                SetText("Winner is:" + names[i]);
                                PrintToAllClients("Winner is:" + names[i]);
                            }
                        }
                    }
                }
            }
        }

        private void Game() //thread for game handling
        {
            while ((turn < noOfRounds) && !terminate) //while rounds not ended
            {
                DisconnectedQ = false;

                if (clientSockets[turn % clientSockets.Count()] == null) //checks if the player that should be asking now disconnected before or not
                    DisconnectedQ = true;

                if (!DisconnectedQ) //if not disconnected
                {
                    try
                    {
                        //giving the ask turn to the appropriate player
                        QuestionProcess(clientSockets[turn % clientSockets.Count()], names[turn % clientSockets.Count()], turn % clientSockets.Count());
                        SetText("Question is being taken by: " + names[turn % clientSockets.Count()]);     //print the info on the server.
                    }
                    catch
                    {
                        //If player disconnects
                        PrintToAllClients("Client is disconnected during question turn. Next player asks.");
                        SetText("A client is disconnected during question turn!");
                        clientSockets[turn % clientSockets.Count()] = null;
                        //names[turn % clientSockets.Count()] = "";
                        disconnectedClients++;
                        noOfRounds++;
                        DisconnectedQ = true;
                        if (clientSockets.Count() - disconnectedClients == 1) //checks if there are only 1 player left or not
                        {
                            SetText("Only 1 Player left. Game is finished!"); PrintToAllClients("Only 1 Player left. Game is finished"); terminate = true;
                            for (int i = 0; i < clientSockets.Count(); i++)
                            {
                                if (clientSockets[i] != null) //announces the winner 
                                {
                                    SetText("Winner is:" + names[i]);
                                    PrintToAllClients("Winner is:" + names[i]);
                                }
                            }
                        }
                    }
                    if (!DisconnectedQ) //calls other players to answer the question
                    {
                        Thread[] answerThread = new Thread[clientSockets.Count() - 1];
                        for (int i = 1; i < clientSockets.Count(); i++)
                        {
                            Thread.Sleep(1);
                            answerThread[i - 1] = new Thread(() => Answer(i));
                            answerThread[i - 1].Start();
                            Thread.Sleep(1);
                        }
                        Thread.Sleep(1);
                        for (int i = 0; i < answerThread.Length; i++)
                        {
                            Thread.Sleep(1);
                            answerThread[i].Join();
                            Thread.Sleep(1);
                        }
                    }
                }
                else
                {
                    //If this is the round any disconnected player supposed to ask question
                    noOfRounds++;
                    if (clientSockets.Count() - disconnectedClients == 1) //check for only 1 player left or not
                    {
                        SetText("Only 1 Player left. Game is finished!");
                        PrintToAllClients("Only 1 Player left. Game is finished"); terminate = true;
                        for (int i = 0; i < clientSockets.Count(); i++)
                        {
                            if (clientSockets[i] != null)
                            {
                                SetText("Winner is:" + names[i]);
                                PrintToAllClients("Winner is:" + names[i]);
                            }
                        }
                    }
                }
                turn++;

                if ((turn != noOfRounds) && !DisconnectedQ && !terminate)//If game is not over and continues, announce the scores at the end of the round
                {
                    for (int l = 0; l < clientSockets.Count(); l++)
                    {
                        if (clientSockets[l] != null)
                        {
                            SendMessage(clientSockets[l], "Scores are as follows:");
                            for (int i = 0; i < clientSockets.Count(); i++)
                            {
                                SendMessage(clientSockets[l], names[i] + ": " + scores[i] + " ");
                            }
                            SendMessage(clientSockets[l], "Waiting for new question...");
                        }
                    }
                }
            }

            if (!terminate) //If rounds are ended, announce the winner and print the scores
            {
                SetText("Rounds ended. Game is finished!"); PrintToAllClients("Rounds ended. Game is finished"); terminate = true;
                int winnerPlayer = 0;
                for (int i = 1; i < clientSockets.Count(); i++)
                {
                    if (scores[i] > scores[winnerPlayer])
                        winnerPlayer = i;
                }
                SetText("Winner is: " + names[winnerPlayer]); PrintToAllClients("Winner is: " + names[winnerPlayer]);
                for (int l = 0; l < clientSockets.Count(); l++)
                {
                    PrintToAllClients(names[l] + "'s score: " + scores[l]);
                }
            }
        }

        //thread to handle the question process
        private void QuestionProcess(Socket thisClient, string name, int placeOfClientSoc)
        {
            SendMessage(thisClient, "Please send your question and answer."); // Inform the client that server is waiting for the answer.
            question = ReceiveMessage(thisClient);              // Recieve the question.
            answer = ReceiveMessage(thisClient);                //Recieve the correct answer to the question.

            for (int i = 0; i < clientSockets.Count(); i++)  //this loop is simply for printing the other clients 
            {                                               //who is not answering that the player who has the turn is asking.
                if (i == placeOfClientSoc)
                {
                    try
                    {   //send an acknowledgment to question asker
                        SendMessage(clientSockets[i], "You asked:");
                        SendMessage(clientSockets[i], question);
                    }
                    catch { }
                    try
                    {
                        SendMessage(clientSockets[i], "Waiting for other players to answer...");
                    }
                    catch { }

                }

                else if (clientSockets[i] != null)
                {
                    //ask question to answering players
                    SendMessage(clientSockets[i], "Please answer the following question:"); //Send the other players the asked question.
                    SendMessage(clientSockets[i], question);
                }
            }

        }

        //thread to handle the answering process
        private void AnswerProcess(Socket thisClient, string name)
        {
            //recieve the answer
            string myAnswer = ReceiveMessage(thisClient);
            SetText("Answer is given by: " + name);

            string messageToSend = "";
            int k = -1;
            //checks if the answer given is correct or not
            if (myAnswer == answer)
            {
                messageToSend = "Client: " + name + " - correct!";  //if the answers are same Answering player is correct.

                for (int i = 0; i < clientSockets.Count(); i++)
                {
                    if (name == names[i])
                        k = i;
                }
                scores[k]++;
            }
            else messageToSend = "Client: " + name + " - wrong!"; //Else, player is answered wrong.  else if (myAnswer == " ") return;

            //sends the result to client
            SendMessage(thisClient, messageToSend); //Send the corresponding message to all the clients.  
            SendMessage(thisClient, "Waiting for round to end...");
        }

        private void SetText(string text)       //SetText function prints the given message to Server Flow.
        {
            try
            {
                // InvokeRequired required compares the thread ID of the
                // calling thread to the thread ID of the creating thread.
                // If these threads are different, it returns true.

                if (this.flowBox.InvokeRequired)
                {
                    StringArgReturningVoidDelegate d = new StringArgReturningVoidDelegate(SetText);
                    this.Invoke(d, new object[] { text });
                }
                else
                {
                    this.flowBox.AppendText(text + "\n");
                }
            }

            catch
            {
            }
        }

        private string ReceiveMessage(Socket thisClient)            //Recieve message gets the message from the given client.
        {
            //recieves the size of the message beforehand
            Byte[] sizeBuffer = new Byte[4];
            thisClient.Receive(sizeBuffer, 0, sizeBuffer.Length, 0);
            
            //converts it into integer
            int size = BitConverter.ToInt32(sizeBuffer, 0);
            string before = "";

            MemoryStream ms = new MemoryStream();
            Byte[] buffer;
            //creates a buffer array with the size recieved
            while (size > 0)
            {
                if (size < thisClient.ReceiveBufferSize) 
                    buffer = new Byte[size];
                else
                    buffer = new Byte[thisClient.ReceiveBufferSize];
                
                int rec = thisClient.Receive(buffer, 0, buffer.Length, 0);
                size -= rec;
                ms.Write(buffer, 0, buffer.Length);
            }
            ms.Close();
            
            Byte[] data = ms.ToArray();
            ms.Dispose();
            //turns the message into string and returns it
            before = Encoding.Default.GetString(data);
            //before = before.Substring(0, before.IndexOf('\0'));
            return before;
        }

        private void SendMessage(Socket thisClient, string message)                 //Send message sents message to the desired client.
        {
            try
            {
                if (thisClient != null)
                {   
                    //sends the size of the message first, then the message
                    Byte[] data = Encoding.Default.GetBytes(message);
                    thisClient.Send(BitConverter.GetBytes(data.Length), 0, 4, 0);
                    thisClient.Send(data);
                }
            }                                                                                   //the abrupt error we got when we close server before the clients.
            catch
            {
            }
        }

        //function to send a message to all clients
        private void PrintToAllClients(string message)                                          //Sends a message to the flow of both clients.
        {
            for (int i = 0; i < clientSockets.Count(); i++)
            {
                if (clientSockets[i] != null)
                {
                    SendMessage(clientSockets[i], message);
                }
            }
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            terminate = true;
            try
            {
                PrintToAllClients("Server is closed, please exit the game!");
                SetText("Server is closing...");
                serverSocket.Close();                                           //We send a message to all clients in case the server closes.
                Application.Exit();
                return;
            }
            catch
            {
                Application.Exit();
            }
        }

        //function to handle the send button to send the number of rounds
        private void roundButton_Click(object sender, EventArgs e)
        {
            try
            {
                //you can send it only before the game starts
                if (!gameStarted)
                {
                    noOfRounds = int.Parse(roundTextBox.Text);
                    SetText("Game will continue for " + noOfRounds + " rounds.");
                }
                //if game is started, give error message
                else SetText("Number of rounds can't be changed during the game!");
            }
            catch
            {
                SetText("Round number can't be empty or non integer!");
            }
        }

        private void startGameButton_Click(object sender, EventArgs e)
        {
            if (clientSockets.Count() > 1 && noOfRounds > 0)
            {
                gameStarted = true;
                SetText("Game is started.");
                PrintToAllClients("Game is started and it will continue for " + noOfRounds + " rounds.");
                Thread gameThread = new Thread(Game);
                gameThread.Start();
            }
            else if (clientSockets.Count() < 2) SetText("At least 2 player is needed to start!");
            else SetText("Number of rounds is not specified!");
        }

        private void roundTextBox_TextChanged(object sender, EventArgs e)
        {
        }

        private void portBox_TextChanged(object sender, EventArgs e)
        {
        }
    }
}