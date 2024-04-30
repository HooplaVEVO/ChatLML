#include <string>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_PNG_Image.H>
#include "ChatBox.h"
#include "client.h"
#include "server.h"
#include "../../../../usr/local/Cellar/fltk/1.3.9/include/FL/Fl.H"

// Forward declarations
void host_loop(ChatBox chatbox);
void client_loop(ChatBox chatbox);

    int main() {

    ChatBox chatBox(800, 800, 1000, 800, "ChatLML");
    chatBox.show();
    return Fl::run();
    //Must get the username input from FL window

    //Call host_loop or join_loop depending on FL window input
    return 0;
}

static void host_loop(ChatBox& chatbox, const std::string& username) {
    Server server(username);
    int new_socket = server.init();
    if (new_socket < 0) {
        chatbox.addMessage("Chatroom creation failed");
        return;
    }
    chatbox.addMessage("Chatroom successfully initialized!");

    std::string rec = "", send = "", temp = "";
    while (true) {
        temp = server.receive_message(new_socket);
        if (rec != temp) {
            rec = temp;
            chatbox.addMessage(rec);
        }
        // Example: get message to send
        // send = chatbox.getSendMessage();
        server.send_message(new_socket, send);

        // Check for quit condition
        // if (quit_condition) break;
    }
    server.terminate();
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






