#include "ChatBox.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <string>
#include <FL/Fl_PNG_Image.H>
#include "server.h"
#include "client.h"
#include <iostream>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>

ChatBox::ChatBox(int x, int y, int w, int h, const char* title) : Fl_Window(x, y, w, h, title) {
    
    
    Fl_PNG_Image *bg_image = new Fl_PNG_Image("/Users/laila/Downloads/chat4.png");
    if (bg_image->w() == 0 || bg_image->h() == 0) {
    std::cerr << "Failed to load image." << std::endl;
    // Handle error, maybe set a fallback color or image
    } else {
    Fl_Box *background = new Fl_Box(0, 0, w, h);
    background->image(bg_image);
    this->add(background);
}

    int buttonTextSize = 24;
    //window->size(new_width, new_height);
    int welcomeLabelWidth = w - 40; // width of the label
    int welcomeLabelHeight = 70; // height of the label
    int welcomeLabelX = (w - welcomeLabelWidth) / 2; // center the label on the x-axis
    int welcomeLabelY = h / 4;
    // Initialize widgets with adjusted positions and sizes
    welcomeLabel = new Fl_Box(welcomeLabelX, welcomeLabelY, welcomeLabelWidth, welcomeLabelHeight, "Welcome to ChatLML!");
    welcomeLabel->box(FL_NO_BOX);
    welcomeLabel->labelfont(FL_BOLD + FL_ITALIC);
    welcomeLabel->labelsize(45);
    welcomeLabel->labeltype(FL_SHADOW_LABEL);
    welcomeLabel->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);

    int inputWidth = 300; // Match width of the welcome label
    int inputHeight = 30; // Height of the input field
    int inputX = (w - inputWidth) / 2; // Center the input field on the x-axis
    int inputY = welcomeLabelY + welcomeLabelHeight + 20; // Position below the welcome label

    

    int buttonWidth = 70; // width of the button
    int buttonHeight = 30; // height of the button
    int buttonX = (w - buttonWidth) / 2; // center the button on the x-axis
    int buttonY = inputY + inputHeight + 20;

    int hostButtonX = (w - buttonWidth) / 4;  // Adjust position if necessary
    int joinButtonX = 3 * (w - buttonWidth) / 4;  // Adjust position if necessary
    int buttonsY = buttonY;

//Initialize ip input for join:

// Initialize the username input
usernameInput = new Fl_Input(inputX, inputY, inputWidth, inputHeight, "Username:");
usernameInput->color(FL_WHITE);
usernameInput->labelfont(FL_BOLD + FL_ITALIC);
usernameInput->textsize(24); // Make text bigger
usernameInput->labelsize(18);



    // Initialize the nextButton
    int nextButtonWidth = 200; // width of the button
    int nextButtonHeight = 80; // height of the button
    int nextButtonX = (w - nextButtonWidth) / 2; // center the button on the x-axis
    int nextButtonY = welcomeLabelY + welcomeLabelHeight + 80; // position the button below the label

    nextButton = new Fl_Button(nextButtonX, nextButtonY, nextButtonWidth, nextButtonHeight, "Next");
    nextButton->color(FL_MAGENTA);
    nextButton->labelsize(buttonTextSize);
    nextButton->labelfont(FL_BOLD + FL_ITALIC);
    nextButton->callback(ChatBox::onNextButtonClicked, (void*)this);

    // Place the host and join buttons below the username input
hostButton = new Fl_Button(hostButtonX, buttonsY, buttonWidth, buttonHeight, "Host");
hostButton->labelsize(buttonTextSize);
hostButton->callback(ChatBox::onHostButtonClicked, (void*)this);

joinButton = new Fl_Button(joinButtonX, buttonsY, buttonWidth, buttonHeight, "Join");
joinButton->labelsize(buttonTextSize);
joinButton->callback(ChatBox::onJoinButtonClicked, (void*)this);

joinInput = new Fl_Input(inputX, inputY, inputWidth, inputHeight, "IP to join:");
joinInput->textsize(24);
joinInput->labelsize(18);

// chatbox: when you figure out how  to start a chatroom, this is the code of the actual chatroom
    chatDisplay = new Fl_Multiline_Output(10, 100, w - 20, h - 200, "");
    chatDisplay->box(FL_DOWN_BOX);
    chatDisplay->textfont(FL_COURIER);
    chatDisplay->textsize(24);
    chatDisplay->wrap(1);

    messageInput = new Fl_Input(10, chatDisplay->y() + chatDisplay->h() + 10, w - 110, 30, "");
    messageInput->hide();
    sendButton = new Fl_Button(w - 90, messageInput->y(), 80, 30, "Send");
    sendButton->callback(ChatBox::onSendButtonClicked, (void*)this);
    sendButton->hide();

    chatDisplay->hide();
    messageInput->hide();
    sendButton->hide();

    // The quit button is usually at the bottom of the application
    quitButton = new Fl_Button(w - 70, h - 40, 60, 30, "Quit");
    quitButton->callback(onQuitButtonClicked, (void*)this);


     // End of widget addition
    showWelcomeScreen();
    end();
}
std::string ChatBox::getUsername() {
    return usernameInput->value();
}


void ChatBox::showWelcomeScreen() {
        std::cout << "Showing welcome screen." << std::endl;

    this->show();
    // Only the welcome label and next button should be visible at first
    welcomeLabel->show();
    welcomeLabel->labelcolor(FL_GREEN);
    usernameInput->hide();
    nextButton->show();
    hostButton->hide();
    joinButton->hide();
    joinInput->hide();
    
}

void ChatBox::showUsernameScreen() {
    welcomeLabel->label("Enter your username:");
    usernameInput->show();
    nextButton->label("Host/Join");
    nextButton->show();
    hostButton->hide();
    joinButton->hide();
    joinInput->hide();
}


void ChatBox::showHostJoinScreen() {
    welcomeLabel->label("Host or Join a Chat?");
    usernameInput->hide();
    nextButton->hide();
    hostButton->show();
    joinButton->show();
    joinInput->hide();
}
void ChatBox::showJoinScreen() {
    // Hide all unnecessary widgets
    welcomeLabel->label("Enter Server IP:");
    welcomeLabel->show();
    usernameInput->hide();

    // Show the IP input field and adjust the button for action
    joinInput->show();
    nextButton->label("Connect");
    nextButton->show();

    // Hide other buttons that are not needed
    hostButton->hide();
    joinButton->hide();
}


void ChatBox::onNextButtonClicked(Fl_Widget*, void* v) {
    ChatBox* chatbox = static_cast<ChatBox*>(v);
    const char* currentLabel = chatbox->nextButton->label();

    if (strcmp(currentLabel, "Host/Join") == 0) {
        chatbox->showHostJoinScreen();
    } else if (strcmp(currentLabel, "Connect") == 0) {
        chatbox->attemptToJoinServer();
    } else {
        chatbox->showUsernameScreen();
    }
}

void ChatBox::showHostScreen(){
    usernameInput->hide();
    nextButton->hide();
    hostButton->hide();
    joinButton->hide();
    joinInput->hide();

}
void ChatBox::showChatScreen() {
    welcomeLabel->hide();
    usernameInput->hide();
    nextButton->hide();
    hostButton->hide();
    joinButton->hide();
    joinInput->hide();

    chatDisplay->show();
    messageInput->show();
    sendButton->show();
}
void ChatBox::attemptToJoinServer() {
    std::string IP = joinInput->value();
    std::string username = getUsername(); // Assume this retrieves a previously entered username

    if (IP.empty()) {
        fl_alert("Please enter a server IP to join.");
        return;
    }
}

//chatbox
//when you figure out how  to start a chatroom, this is the code of the actual chatroom
void ChatBox::onSendButtonClicked(Fl_Widget*, void* v) {
    ChatBox* chatbox = static_cast<ChatBox*>(v);
    const char* msg = chatbox->messageInput->value();
    if (msg && strlen(msg) > 0) {
        std::string username = chatbox->getUsername();  // Fetch the username
        chatbox->addMessage(username, msg);  // Send both username and message
        chatbox->messageInput->value("");  // Clear the input field after sending
    }
}


ChatBox::~ChatBox() {
    
}

void ChatBox::onJoinButtonClicked(Fl_Widget*, void* v) {
    ChatBox* chatbox = static_cast<ChatBox*>(v);

    // Get the input values
    std::string IP = chatbox->joinInput->value();
    std::string username = chatbox->usernameInput->value();

    // Check for the necessary conditions before attempting to connect
    if (username.empty()) {
        fl_alert("Please enter your username.");
        chatbox->showUsernameScreen(); // Make sure user can enter username
        return;
    }

    if (IP.empty()) {
        fl_alert("Please enter a server IP to join.");
        chatbox->showJoinScreen(); // Ensure IP input is visible
        return;
    }

    // Attempt to connect if all inputs are valid
    Client client(username);
    if (client.init(IP) == 0) {
        chatbox->addMessage(username, "Connected to server successfully.");
        chatbox->showChatScreen();
    } else {
        fl_alert("Failed to connect to server.");
    }
}



void ChatBox::onHostButtonClicked(Fl_Widget*, void* v) {
    ChatBox* chatbox = static_cast<ChatBox*>(v);
    std::string username = chatbox->usernameInput->value();
    if (username.empty()) {
        fl_alert("Please enter your username.");
        chatbox->showUsernameScreen(); // Make sure user can enter username
        return;
    }
    Server server(username);
    if (server.init() == 0) {
        // Correctly pass both the username and the message directly
        chatbox->addMessage(username, "Server started successfully. Waiting for connections...");
        chatbox->showChatScreen();
    } else {
        fl_alert("Failed to start server.");
    }
}

//chat room code
void ChatBox::addMessage(const std::string& username, const std::string& message) {
    std::string formattedMessage = username + ": " + message + "\n";
    std::string newContent = std::string(chatDisplay->value()) + formattedMessage;
    chatDisplay->value(newContent.c_str());

    }
    



void ChatBox::onQuitButtonClicked(Fl_Widget*, void* v) {
    ((ChatBox*)v)->hide(); // Alternatively, Fl::exit();
}




