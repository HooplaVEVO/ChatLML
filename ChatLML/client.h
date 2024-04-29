#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

class Client{
public:
    int sock;
    struct sockaddr_in server_address;
    std::string username;

    Client(std::string&);

    int init(std::string IP,int port);//Attempts to create a TCP connection

    void send_message(std::string message);//Will send message over TCP connection

    std::string recieve_message();//Will check for message recieved over TCP connection

    void terminate(); //Ends TCP listener
};





#endif