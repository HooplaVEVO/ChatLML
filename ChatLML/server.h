#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Server {
public:
    std::string username;
    int server_fd;
    struct sockaddr_in server_address;
    int opt;
    int addrlen;

    Server(const std::string& user);
    ~Server();

    int init();
    void send_message(int new_socket, const std::string& message);
    std::string receive_message(int new_socket);
    void terminate();
};

#endif // SERVER_H
