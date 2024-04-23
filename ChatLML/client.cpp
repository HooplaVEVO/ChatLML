#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "client.h"

#define PORT 8080

struct Client {
    int sock;
    struct sockaddr_in server_address;
    std::string username;

    int init() {
        // Create socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            std::cerr << "Socket creation error" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Initialize server address
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
        if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
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

    void send_message(const char* message) {
        std::string messageWithUsername = username; // Add username to the message
        messageWithUsername += ": ";
        messageWithUsername += message;
        send(sock, messageWithUsername.c_str(), messageWithUsername.length(), 0);
    }

    std::string receive_message() {
        char buffer[1024] = { 0 };
        read(sock, buffer, 1024);
        return std::string(buffer);
    }

    void terminate() {
        close(sock);
    }
};