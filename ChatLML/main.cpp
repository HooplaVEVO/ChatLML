#include <string>

#include "ChatBox.h"
#include "client.h"
#include "server.h"

// Forward declarations
void host_loop(ChatBox chatbox);
void client_loop(ChatBox chatbox);

int main() {
    ChatBox chatBox(800, 800, 1000, 800, "ChatLML");
    chatBox.show();
    //Must get the username input from FL window

    //Call host_loop or join_loop depending on FL window input
    return 0;
}

static void host_loop(ChatBox chatbox,std::string username){
    Server server(username);
    std::string rec = "";
    std::string send = "";
    std::string temp = "";
    if(server.init()!=0){ //Unsuccessful server initialization
        chatbox.addMessage("Chatroom creation failed");
        return;
    }
    else{
        chatbox.addMessage("Chatroom successfully initialized!");
    }
    while(true){//Chatroom Loop
        //Check for new message
        temp = server.receive_message();
        if(rec!=temp){
            rec = temp;
            chatbox.addMessage(rec);
        }
        //Need a method in chatbox which will tell main when send button is clicked and pass the input back
        //send =
        server.send_message(send);
        //If user presses quit button on window, return
        //On exit:
        server.terminate();
        return;
    }

}

static void join_loop(ChatBox chatbox,std::string username,std::string IP){
    Client client(username);
    std::string rec = "";
    std::string send = "";
    std::string temp = "";
    if(client.init(IP)!=0){ //Unsuccessful server initialization
        chatbox.addMessage("Chatroom join failed");
        return;
    }
    else{
        chatbox.addMessage("Chatroom successfully initialized!");
    }
    while(true){//Chatroom Loop
        //Check for new message
        temp = client.receive_message();
        if(rec!=temp){
            rec = temp;
            chatbox.addMessage(rec);
        }
        //Send message
        //Need a method in chatbox which will tell main when send button is clicked and pass the input back
        //send = chatbox.getSendInput or something or other
        client.send_message(send);
        //If user presses quit button on window:
        client.terminate();
        return;
    }
}






