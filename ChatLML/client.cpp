#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

namespace std;

#define PORT 8080

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    string message = ""; // Changed to char array
    string buffer = "";
    char username[16] = { 0 };

    cout << "Welcome to ChatLML, an implementation of Pictochat in C++. Please enter your username: " << endl;
    cin.getline(username, sizeof(username));//User sets username

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "10.24.43.44", &serv_addr.sin_addr) <= 0) {//Set IP here
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // Loop until connect to server
    while (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed. Retrying..." << std::endl;
        sleep(1); // Added delay for retrying
    }

    while (1) { // REPL Loop
        // Read message from server first
        valread = read(sock, buffer, 1024);
        std::cout << "Message from server: " << buffer << std::endl;

        // Read user input
        std::cout << "Enter message: ";
        std::cin.getline(message, sizeof(message));

        if (strcmp(message, "quit") == 0) { //Check for quit condition
            std::cout << "Exiting the program..." << std::endl;
            break;
        }

        // Send message to server
        send(sock, message, strlen(message), 0);
        std::cout << "Message sent to server" << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;
    return 0;
}
