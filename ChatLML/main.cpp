#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "ChatBox.h"
#include "client.h"
#include "server.h"

ChatBox* chatBox;

// Forward declarations
void printMessage(const std::string& message);
static int host_loop(const std::string& username);
static int client_loop(const std::string& username, const std::string& IP);

int main() {
    std::string username = "";
    std::string input = "";
    std::string IP = "";
    
    // Initialize UI Object
    chatBox = new ChatBox(10, 10, 380, 200); // arbitrary numbers, we can change them later
    
    // Print welcome message in UI window
    printMessage("Welcome to ChatLML, an implementation of Pictochat in C++! Please enter your username: ");
    
    // Enter username
    std::getline(std::cin, username);
    
    // Ask user to host or join a room
    while(true) {
        printMessage("Would you like to host or join a chatroom?\n");
        std::getline(std::cin, input);
        
        if(input == "host") {
            printMessage("Creating chatroom...\n");
            if(host_loop(username) == 1)
                break;
        }
        else if(input == "join") {
            printMessage("Please enter the IP Address of the host: "); // Only local functionality for now.
            std::getline(std::cin, IP);
            if(client_loop(username, IP) == 1)
                break;
        }
        else if(input == "exit") {
            printMessage("Exiting the program...\n");
            break;
        }
        else {
            printMessage("Input not recognized.\n");
        }
    }
    
    delete chatBox; // Clean up the allocated memory
    return 0;
}

// Print message to the chat box
void printMessage(const std::string& message) {
    chatBox->appendMessage(message);
}

// Host loop function
static int host_loop(const std::string& username) {
    Server server;
    server.username = username;
    int commSocket = -1;
    std::string receive = "";
    std::string send = "";
    
    if (server.init() == 1) { // If socket creation failed
        printMessage("Server initialization failed.");
        return 1; // Indicate failure
    }
    
    printMessage("Waiting for client to connect...\n");
    
    while(true) { // Client connection loop.
        // If server detects client connection
        if ((commSocket = accept(server.server_fd, (struct sockaddr *)&server.address, (socklen_t*)&server.addrlen)) == 0) {
            printMessage("A client has joined!\n");
            break;
        }
    }
    
    while(true) { // Main chat loop
        // Receive and print message from other user
        receive = server.receive_message(commSocket);
        printMessage(receive);
        
        // Get user input
        std::getline(std::cin, send);
        
        if(send == "quit") { // If input == quit, exit chatroom
            printMessage("Exiting chatroom...\n");
            server.terminate();
            break;
        }
        
        server.send_message(send);
        printMessage(username + ": " + send + "\n"); // Prints user message for them to see.
    }
    
    return 0;
} 

// Client loop function
static int client_loop(const std::string& username, const std::string& IP) {
    Client client;
    client.username = username;
    std::string receive = "";
    std::string send = "";

    if (client.init(IP) == 1) { // If socket creation failed
        printMessage("Connection failed!\n");
        return 1; // Indicate failure
    }
    
    while(true) { // Main chat loop
        // Receive and print message from other user
        receive = client.receive_message();
        printMessage(receive);
        
        // Get user input
        std::getline(std::cin, send);
        
        if(send == "quit") { // If input == quit, exit chatroom
            printMessage("Exiting chatroom...\n");
            client.terminate();
            break;
        }
        
        client.send_message(send);
        printMessage(username + ": " + send + "\n"); // Prints user message for them to see.
    }
    
    return 0;
}
