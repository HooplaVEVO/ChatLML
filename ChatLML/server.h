#ifndef SERVER_T_H
#define SERVER_T_H

#include <string>
#include <netinet/in.h>

class Server {
public:
    std::string username;
    int server_fd;
    struct sockaddr_in server_address;
    int opt;
    int addrlen;

    Server(std::string);
    int init(); // Establishes TCP listener on port
    void send_message(std::string); // Sends message over established TCP connection
    std::string receive_message(); // Checks for message received over TCP connection
    void terminate(); // Ends TCP connection
};

#endif
