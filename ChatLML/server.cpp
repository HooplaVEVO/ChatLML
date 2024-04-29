//Server class which includes init, send_message, recieve_message and terminate functions. Will add picture functions later.
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server.h"

#define PORT 8080
#define MAX_CONNECTIONS 5

    Server::Server(std::string& user){
        Server->username=user;
    }

    int Server::init() {
     // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            std::cerr << "Socket creation failed" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
            std::cerr << "setsockopt failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr*)&address,
            sizeof(address)) < 0) {
            std::cerr << "Bind failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, MAX_CONNECTIONS) < 0) {
            std::cerr << "Listen failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        return 0;
    }

    void Server::send_message(int new_socket, std::string message) {
        std::string messageWithUsername = username; // Add username to the message
        messageWithUsername += ": ";
        messageWithUsername += message;
        send(new_socket, messageWithUsername.c_str(), messageWithUsername.length(), 0);
    }

    std::string Server::receive_message(int new_socket) {
        char buffer[1024] = { 0 };
        read(new_socket, buffer, 1024);
        return std::string(buffer);
    }

    void Server::terminate() {
        close(server_fd);
    }

