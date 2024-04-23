#ifndef SERVER_T_H
#define SERVER_T_H

#include <cstring>
#include <iostream>
#include <sys/socket.h>

using namespace std;

struct Server{
    std::string username;
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
};

//I plan to add a heartbeat function to check that all clients are still connected. I would like to make a feature which
//prints a message in the console everytime a user joins/leaves. This might be difficult so I am only going to focus on getting
//The server and client classes working for now.

extern int init(int port);//Establishes TCP listener on port

extern void send_message(string message);//Sends message over established TCP connection

extern std::string recieve_message();//Checks for message recieved over TCP connection

//extern int send_picture();//Sends a user-drawn picture

//extern int receive_picture();//Checks for sent picture

extern void terminate();//Ends TCP connection

#endif