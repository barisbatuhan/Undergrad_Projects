A SHORT EXPLANATION:
----------------------------------
In this repository a windows form application is placed. In the application, there is 1 server and there can be any number of clients. Server controls the game options and clients are the ones that play the game. In the game, in each turn one client asks a question and sends the answer to the server and other clients answer to those questions. After the determined round number is finished, the game ends and the winner is announced.


DETAILED EXPLANATION:
----------------------------------
Server side is the part which controls the game since clients doesn't connect each other but the same server.
In order to start playing we need at least 2 people whom joined the server. Game starts with the people joined
before the "Start The Game" button is pressed. *You cannot join mid-game.*.

Server takes a port number to establish a server listening.
*After making server listen with a portnumber entered, changing the port
number will not effect.*

Game will not start if the "No of rounds" is not send. *You can change the number of rounds multiple times while 
game is not started.*

Player who is connected first starts te game by sending his question and answer after that game goes on till the
round cap is reached.

If a player disconnects during the game a message will be displayed. Game continues while there is rounds and at least 2
players left. 

Server waits for all of the answers to send clients if they are correct or not.

After the round ends the scoreboard will be shared.
After the game ends winner will be chosen based on the correct answers. * Disconnected players score will not be considered.*

Client side only needs to connect to server with a valid IP address,port number and unique name
before the game starts.

-Error Messages-

"Entered information is not correct..."
-Ip address, name or port number entered to connect by user is empty

"Duplicate name, please choose another name!"
-Name is already taken, try different name

"Client cannot able to find any server in given adress..."
-If user cannot connect to the server with enterd ip address or port number

"No valid question or answer is given!"
-If the asking user enters empty question or answer

"Question or answer cannot be delivered correctly!"
-Asking user cannot deliver question or answer of it to server

"No valid answer is given!"
-Empty answer is entered

"Answer cannot be delivered correctly!"
-Answering client's answer can not be delivered to server

"It is not your turn, please wait!"
-If user tries to send message during other user's turn to ask or answer
-If user tries to send a message before the game starts

"Cannot be reached to the server..."
-If user can not establish a connection to the desired server

"Error in message receiving!"
-If user can not recieve any message from the server

"Sorry, game is already started!"
-Game is already started wait for the next game.

"At least 2 player is needed to start!"
-Please wait for more people to join.

"Only 1 Player left. Game is finished!"
-At least 2 player required to play the game.

"Client is disconnected during question turn. Next player asks."
-A player disconnected at his/her question turn but the game continues.

"Number of rounds should not be empty or non-int character please try again."
-Number of rounds is not entered correctly.

"Number of rounds can't be changed during the game!"
-Game is already started. Must restart if you want to change the number of turns.

"Number of rounds is not specified!"
-Please enter a valid round number to start playing.
