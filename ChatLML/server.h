#ifndef SERVER_T_H
#define SERVER_T_H

#include <cstring>
#include <iostream>
#include <sys/socket.h>

using namespace std;

class Server{
    public:
        std::string username;
        int server_fd;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);

        Server(std::string&);

        int init();//Establishes TCP listener on port

        void send_message(std::string);//Sends message over established TCP connection

        std::string receive_message();//Checks for message recieved over TCP connection

        void terminate();//Ends TCP connection
};

#endif