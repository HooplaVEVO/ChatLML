#include <iostream>
#include <stdio.h>
#include <string>
#include "client.h"
#include "server.h"
namespace std;

int main() {
	string username, message, buffer = "";
	//Boot UI window
	// Initialize UI Object
	//Print welcome message
	cout << "Welcome to ChatLML, an implementation of Pictochat in C++! Please enter your username: " << endl;
	//Enter username
	fgets(username, sizeof(username), stdin);
	//If user decides to host:
	server_t server;
	server.username = username;
	server.
	//Join -> client.h
	//Exit -> end program
	return 0;
}
