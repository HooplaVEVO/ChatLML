#ifndef CHAT_BOX_H
#define CHAT_BOX_H

#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <string>

class ChatBox {
public:
    ChatBox(int x, int y, int w, int h);
    void appendMessage(const std::string& message);

private:
    Fl_Text_Display* textDisplay;
    Fl_Text_Buffer* textBuffer;
};

#endif // CHAT_BOX_H
