#include <iostream>
#include <stdio.h>
#include <string>
#include "ChatBox.h"
#include "client.h"
#include "server.h"

ChatBox* chatBox;

//functions of use
void printMessage(const std::string& message);
void hostCallback(const std::string &username);
void joinCallback(const std::string &username);

//Currently the chatroom only supports local communication between two clients. I may add functionality for many
//clients and perhaps even private messaging within a public chatroom. -Myles

int main() {
	std::string username = "";
	std::string input = "";
	std::string IP = "";
	// Initialize UI Object
	chatBox = new ChatBox(10, 10, 380, 200); //arbitrary numbers, we can change them later
	//Print welcome message in UI window
	printMessage("Welcome to ChatLML, an implementation of Pictochat in C++! Please enter your username: ") ; //changed from cout to printMesage
	//Enter username
	std::getline(username, sizeof(username), stdin);
	//Ask user to host or join a room
	while(1){
		printMessage("Would you like to host or join a chatroom?\n");
		std::getline(input, sizeof(input), stdin);
		//If user decides to host:
		if(input == "host"){
			printMessage("Creating chatroom...\n")
			host_loop(username);
		}
		else if(input == "join"){
			printMessage("Please enter the IP Address of the host:");//Only local functionality for now.
			std::getline(IP, sizeof(IP), stdin);
			client_loop(username,IP);
		}
		else if(input == "exit"){
			printMessage("Exiting the program...\n");
			return 0;
		}
		else{
			printMessage("Input not recognized.\n");
		}
	}
	return 0;
}
//added functions:
void printMessage(const std::string& message){
	chatBox->appendMessage(message);
}

static int host_loop(const std::string username) {
	Server server;
	server.username = username;
	int commSocket = -1;
	std::string recieve = "";
	std::string send = "";
	
	if (server.init()==1){//If socket creation failed
		printMessage("Server initialization failed.");
		return 1;
	}
	printMessage("Waiting for client to connect...");
	while(1){//Client connection loop.
		//If server detects client connection
		if ((commSocket = accept(server.server_fd, (struct sockaddr *)&server.address,(socklen_t*)&server.addrlen)) == 0) {
            printMessage("A client has joined!");
            break;
        }
	}
	while(1){//Main chat loop
		//Recieve and print message from other user
		recieve = server.recieve_message(commSocket);
		printMessage(recieve);
		//Get user input
		send = std::getline(send, sizeof(send), stdin);
		if(send == "quit"){//If input == quit, exit chatroom
			printMessage("Exiting chatroom...");
			server.terminate();
			break;
		}
		server.send_message(send);
		printMessage(username+": "+send);//Prints user message for them to see.
	}
	return 0;
	
} 

//Loop of client joining chatroom. If there is a critical failure, the method returns 1. If all functions
//correctly, it ends the loop when the user is done and returns 0.
static int client_loop(const std::string username,const std::string IP) {
	Client client;
	client.username = username;
	std::string recieve = "";
	std::string send = "";

	if (client.init(IP)==1){//If socket creation failed
		printMessage("Connection failed!");
	}
	while(1){//Main chat loop
		//Recieve and print message from other user
		recieve = client.recieve_message();
		printMessage(recieve);
		//Get user input
		send = std::getline(send, sizeof(send), stdin);
		if(send == "quit"){//If input == quit, exit chatroom
			printMessage("Exiting chatroom...");
			client.terminate();
			break;
		}
		client.send_message(send);
		printMessage(username+": "+send);//Prints user message for them to see.
	}
	return 0;
} 
//return Fl::run(); What is this doing here?




