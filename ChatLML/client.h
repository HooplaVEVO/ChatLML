#ifndef CLIENT_T_H
#define CLIENT_T_H

#include <string>
#include <iostream>
#include <sys/socket.h>

struct Client{
	string username;
	string IP;
	int port;
};

extern int init(string IP,int port);//Attempts to create a TCP connection

extern int send_message(string message);//Will send message over TCP connection

extern string recieve_message();//Will check for message recieved over TCP connection

extern int send_picture(); //Send user-drawn picture over TCP connection

extern int recieve_picture(); //Checks for user-drawn picture sent over TCP

extern void terminate(); //Ends TCP connection 

#endif