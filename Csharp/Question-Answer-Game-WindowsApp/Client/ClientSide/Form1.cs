/*Multiplayer Quiz Game Step2
 *
 *  Client
 * 
 * Created by 
 * Ibrahim Bugra Demir, Baris Batuhan Topal, Arda Asik.
 */
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClientSide
{
    public partial class Form1 : Form
    {
        //Initialized server socket with the TCP protocol on out inter network
        static Socket clientSoc = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        delegate void StringArgReturningVoidDelegate(string text);

        // Global Variables
        static bool connected = false; //true if client can connect to server
        static bool questionTurn = false; //true if it is our client's turn to ask
        static bool answerTurn = false; //true if it is our client's turn to answer


        public Form1()
        {
            InitializeComponent();
        }

        // Button Functions

        private void connectBtn_Click(object sender, EventArgs e)
        {
            if (connectBtn.Text == "Connect")
            {
                string serverIP = ipBox.Text; //server ip to connect
                string port = portBox.Text; //port number to connect
                string name = nameBox.Text; //name of the client 
                int portNum;

                //if all the necessary information can not be obtained, gives an error mesaage
                if (serverIP == "" || port == "" || nameBox.Text == "")
                    SetText("Entered information is not correct...");

                //else, if we obtained all the information
                else
                {
                    portNum = int.Parse(port);

                    try
                    {
                        clientSoc.Connect(serverIP, portNum); //tries to connect to server with information taken manually
                        SendMessage(name); //sends the name to the server
                        string message = ReceiveMessage(); //recieves message from server
                        message = message.Substring(0, message.Length);
                        SetText(message); //shows the message on the flow box
                        if (message == "Sorry, game is already started!")//If client tries to connect after game is started
                        {
                            clientSoc.Close();
                            clientSoc = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                        }
                        else if (message != "Duplicate name, please choose another name!")//if the name is not taken and game has not started yet
                        {
                            connected = true;
                            connectBtn.Text = "Disconnect";
                            //SetText("Connection to the server established...");
                            SetText("Please wait for server to start the game.");
                            Thread receiveThread = new Thread(Receive); //starts receiving from server for the game
                            receiveThread.Start();
                        }
                        else //if duplicate, closes the client and tries new one
                        {
                            clientSoc.Close();
                            clientSoc = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                        }

                    }
                    catch //if any problem occures during connection, this message is thrown
                    {
                        SetText("Client cannot able to find any server in given adress...");
                    }
                }
            }

            else //if disconnect button is pressed
            {
                clientSoc.Close();
                Application.Exit();
            }
        }

        //when we click to send button and try to send information to server
        private void sendBtn_Click(object sender, EventArgs e)
        {
            if (questionTurn) //if it is our client's turn to ask a question
            {
                string question = questionBox.Text;
                string answer = answerBox.Text;
                if (question == "" || answer == "") //if not valid
                {
                    SetText("No valid question or answer is given!");
                    return;
                }

                try //tries to send question and answer of it to the server
                {
                    SendMessage(question);
                    SendMessage(answer);
                    SetText("Question is sent.");
                }
                catch //if cannot send
                {
                    SetText("Question or answer cannot be delivered correctly!");
                }

                questionTurn = false; //changes the turn of asking to other client
            }

            else if (answerTurn) //if it is this client's turn to ask
            {
                string answer = answerBox.Text;
                if (answer == "") //if not valid answer
                {
                    SetText("No valid answer is given!");
                    return;
                }

                try //if valid, tries to send to server
                {
                    SendMessage(answer);
                    SetText("Answer is sent.");
                }
                catch
                {
                    SetText("Answer cannot be delivered correctly!");
                }

                answerTurn = false; //changes answering turn to other player
            }

            else //if try to ansser on other client's answer turn
            {
                SetText("It is not your turn, please wait!");
            }
        }

        // Threads

        private void Receive() //thread to recieve information from server
        {
            while (connected) //works id it is connected to server
            {
                try //splits the sentences with the end code # and processes them seperately
                { 
                    string receivedMessages = ReceiveMessage();
                    string[] allMessages = receivedMessages.Split('#');
                    int i = 0;
                    while (i < allMessages.Length)
                    {
                        string receivedMessage = allMessages[i];
                        if (receivedMessage != "" && receivedMessage != " ") //If the messages is not an empty line
                        {
                            if (connected) //writes it to the client flow box
                            {
                                SetText(receivedMessage);
                            }


                            //if server wants this client to ask question
                            if (receivedMessage.Contains("Please send"))
                            {
                                questionTurn = true;
                            }
                            //if server wants this client to answer to a question
                            else if (receivedMessage.Contains("Please answer"))
                            {
                                answerTurn = true;
                            }
                            //if server ends the game
                            else if (receivedMessage.Contains("Server is closed"))
                            {
                                connected = false;
                                questionTurn = false;
                                answerTurn = false;
                                clientSoc.Close();
                            }
                        }
                        i++;
                    }
                }
                catch
                {
                    //if any connection problem during the game
                    SetText("Cannot be reached to the server...");
                    connected = false;
                    clientSoc.Close();
                }
            }
        }

        // Text Arrrangers, Receivers and Senders

        private void SetText(string text) //appends text to the flow box simultaneously
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

        private string ReceiveMessage() //function to return the message from server
        {
            //recieves the size of the message first
            Byte[] sizeBuffer = new Byte[4];
            clientSoc.Receive(sizeBuffer, 0, sizeBuffer.Length, 0);

            int size = BitConverter.ToInt32(sizeBuffer, 0);
            string before = "";

            MemoryStream ms = new MemoryStream();
            Byte[] buffer;

            //creates a buffer array with the size sent beforehand
            while (size > 0)
            {
                if (size < clientSoc.ReceiveBufferSize)
                    buffer = new Byte[size];
                else
                    buffer = new Byte[clientSoc.ReceiveBufferSize];

                int rec = clientSoc.Receive(buffer, 0, buffer.Length, 0);
                size -= rec;
                ms.Write(buffer, 0, buffer.Length);
            }
            ms.Close();

            Byte[] data = ms.ToArray();
            ms.Dispose();

            //turns that message into string and returns it
            before = Encoding.Default.GetString(data);
            //before = before.Substring(0, before.IndexOf('\0'));
            return before;
        }

        //function to send a message to the server
        private void SendMessage(string message)
        {
            try //tries to send it 
            {
                //first sends the size of the message, then the message
                Byte[] data = Encoding.Default.GetBytes(message);
                clientSoc.Send(BitConverter.GetBytes(data.Length), 0, 4, 0);
                clientSoc.Send(data);
                          
            }
            catch //if cannot send, throws this error message
            {
                SetText("Error in sending message!");
            }
        }

        // On close button press

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            connected = false;
            clientSoc.Close();
            Application.Exit();
        }

        private void ipBox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}