#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

class Client{

public:

int init(std::string IP,int port);//Attempts to create a TCP connection

void send_message(std::string message);//Will send message over TCP connection

std::string recieve_message();//Will check for message recieved over TCP connection

    int sock;
    struct sockaddr_in server_address;
    std::string username;
};

<<<<<<< HEAD

=======
extern int init(std::string IP);//Attempts to create a TCP connection

extern void send_message(std::string message);//Will send message over TCP connection

extern std::string receive_message();//Will check for message recieved over TCP connection
>>>>>>> 5c335656ccc7f003d8945cb69c6b5b1abad3e61b

//extern int send_picture(); //Send user-drawn picture over TCP connection

//extern int recieve_picture(); //Checks for user-drawn picture sent over TCP

extern void terminate(); //Ends TCP listener

#endif