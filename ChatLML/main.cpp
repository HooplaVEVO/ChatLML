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
void host_loop(std::string username);
void client_loop(std::string username);

int main() {
	std::string username = "";
	// Boot UI window
	// Initialize UI Object
	chatBox = new ChatBox(10, 10, 380, 200); //arbitrary numbers, we can change them later
	//Print welcome message in UI window
	printMessage("Welcome to ChatLML, an implementation of Pictochat in C++! Please enter your username: ") ; //changed from cout to printMesage
	//Enter username

	std::getline(std::cin, username);
	//If user decides to host:
	hostCallback(username);
	//Join -> client.h
	//Exit -> end program
	return 0;
	//return Fl::run();
}
//added functions:
void printMessage(const std::string &message){
	chatBox->appendMessage(message);
}

void hostCallback(const std::string &username){
	printMessage("Hosting as " + username);
host_loop(username);
}

void joinCallback(const std::string &username) {
    printMessage("Joining as " + username);
    // Start joining
    client_loop(username);
}


void host_loop(std::string username) {
	Server server;
	server.username = username;
	
} 


void client_loop(std::string username) {
	Client client;
	client.username = username;
	
} 





