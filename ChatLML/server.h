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

    Server(const std::string& user);

    int init(); // Establishes TCP listener on port
    void send_message(int new_socket, const std::string& message); // Sends message over established TCP connection
    std::string receive_message(int new_socket); // Checks for message received over TCP connection
    void terminate(); // Ends TCP connection
};

#endif
