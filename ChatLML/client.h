#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <netinet/in.h>

class Client {
public:
    int sock;
    struct sockaddr_in server_address;
    std::string username;

    Client(const std::string& user); // Changed from non-const to const reference

    int init(std::string IP); // Initialize connection to the server
    void send_message(const std::string& message); // Send a message over TCP connection
    std::string receive_message(); // Check for received message over TCP connection
    void terminate(); // Ends TCP connection
};

#endif // CLIENT_H
