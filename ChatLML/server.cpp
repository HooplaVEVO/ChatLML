#include "server.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

Server::Server(const std::string& user) : username(user), server_fd(-1), opt(1), addrlen(sizeof(server_address)) {
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
}

int Server::init() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    // Using SO_REUSEADDR to reuse the socket address on restart
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        std::cerr << "setsockopt SO_REUSEADDR failed" << std::endl;
        return -1;
    }

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;
    return 0; // Only indicate successful initialization here
}

void Server::send_message(int new_socket, const std::string& message) {
    std::string messageWithUsername = username + ": " + message;
    send(new_socket, messageWithUsername.c_str(), messageWithUsername.length(), 0);
}

std::string Server::receive_message(int new_socket) {
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);
    return std::string(buffer);
}

void Server::terminate() {
    if (server_fd != -1) {
        close(server_fd);
    }
}

Server::~Server() {
    terminate();
}
