#define PORT 8080

#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"
#include "server.h"

Client::Client(std::string& user) : username(user), sock(-1) {
    server_address.sin_family = AF_INET;  // Setting up default values
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
}

    int Client::init(std::string IP) {
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        exit(EXIT_FAILURE);
    }

        // Initialize server address
        if (inet_pton(AF_INET, IP.c_str(), &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

      // Connect to server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}

void Client::send_message(const std::string& message) {
    std::string messageWithUsername = username + ": " + message;
    send(sock, messageWithUsername.c_str(), messageWithUsername.length(), 0);
}

    std::string Client::receive_message() {
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    return std::string(buffer);
}

void Client::terminate() {
    close(sock);
}
