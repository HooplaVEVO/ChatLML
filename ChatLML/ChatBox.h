#ifndef CHATBOX_H
#define CHATBOX_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>
//#include <FL/fl_ask.h>
#include "server.h"   // Make sure this is correctly pointed to your Server header
#include "client.h"   // Make sure this is correctly pointed to your Client header

class ChatBox : public Fl_Window {
public:
    ChatBox(int x, int y, int w, int h, const char* title);
    ~ChatBox();
    

    std::string getUsername();
    // Declare pointers to Server and Client
    Server* server;
    Client* client;

    // Widget members
    Fl_Box* background;
    Fl_Box* welcomeLabel;
    Fl_Input* usernameInput;
    Fl_Input* joinInput;
    Fl_Input* messageInput;
    Fl_Multiline_Output* chatDisplay;
    Fl_Button* nextButton;
    Fl_Button* hostButton;
    Fl_Button* joinButton;
    Fl_Button* quitButton;
    Fl_Button* sendButton;

    // Screen functions
    void addMessage(const std::string& username, const std::string& message);
    void showWelcomeScreen();
    void showUsernameScreen();
    void showHostJoinScreen();
    void showHostScreen();
    void showJoinScreen();
    void showChatScreen();
    void attemptToJoinServer();

private:
    static void onHostButtonClicked(Fl_Widget*, void*);
    static void onJoinButtonClicked(Fl_Widget*, void*);
    static void onQuitButtonClicked(Fl_Widget*, void*);
    static void onNextButtonClicked(Fl_Widget*, void*);
    static void onSendButtonClicked(Fl_Widget*, void*);
};

#endif // CHATBOX_H
