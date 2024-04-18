#include <iostream>
#include <stdio.h>
#include <string>

#include "client.h"
#include "server.h"

int main() {
	std::string username = "";
	// Boot UI window
	// Initialize UI Object
	//Print welcome message in UI window
	cout << "Welcome to ChatLML, an implementation of Pictochat in C++! Please enter your username: " << endl;
	//Enter username
	fgets(username, sizeof(username), stdin);
	//If user decides to host:
	host_loop(username);
	//Join -> client.h
	//Exit -> end program
	return 0;
}

static int host_loop(std::string username) {
	Server server;
	server.username = username;
}

static int client_loop(std::string username) {
	Client client;
	client.username = username;
}
