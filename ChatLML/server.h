#ifndef SERVER_T_H
#define SERVER_T_H

#include <string>
#include <iostream>
#include <sys/socket.h>

struct Server{
	string username;
	string IP;
	int port;
};

extern int init(string IP, int port);//Establishes TCP listener

extern int send_message(string message);//Sends message over established TCP connection

extern string recieve_message();//Checks for message recieved over TCP connection

extern int send_picture();//Sends a user-drawn picture

extern int receive_picture();//Checks for sent picture

extern int terminate();//Ends TCP connection

#endif