#include "ChatBox.h"

ChatBox::ChatBox(int x, int y, int w, int h) {
    textBuffer = new Fl_Text_Buffer();
    textDisplay = new Fl_Text_Display(x, y, w, h);
    textDisplay->buffer(textBuffer);
    textDisplay->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, w);
}

void ChatBox::appendMessage(const std::string& message) {
    textBuffer->append(message.c_str());
    textBuffer->append("\n");
}
