#ifndef CHATBOX_H
#define CHATBOX_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>

class ChatBox : public Fl_Window {
public:
    ChatBox(int x, int y, int w, int h, const char* title);
    ~ChatBox();
    void addMessage(const std::string& message);

    // Widgets
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

    // Screens
    void showWelcomeScreen();
    void showUsernameScreen();
    void showHostJoinScreen();
    void showHostScreen();
    void showJoinScreen();

private:
    static void onHostButtonClicked(Fl_Widget*, void*);
    static void onJoinButtonClicked(Fl_Widget*, void*);
    static void onQuitButtonClicked(Fl_Widget*, void*);
    static void onNextButtonClicked(Fl_Widget*, void*);
    static void onSendButtonClicked(Fl_Widget*, void*);  // Ensure this is declared
};

#endif // CHATBOX_H
