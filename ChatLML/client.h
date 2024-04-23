#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

struct Client{
    int sock;
    struct sockaddr_in server_address;
    std::string username;
};

extern int init(string IP,int port);//Attempts to create a TCP connection

extern void send_message(string message);//Will send message over TCP connection

extern std::string recieve_message();//Will check for message recieved over TCP connection

//extern int send_picture(); //Send user-drawn picture over TCP connection

//extern int recieve_picture(); //Checks for user-drawn picture sent over TCP

extern void terminate(); //Ends TCP listener

#endif