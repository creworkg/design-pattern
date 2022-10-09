#include <string.h>
#include <iostream>

using namespace std;

class ChatInterface
{
public:
    virtual void show() = 0;
};

class ChatHistogram : public ChatInterface
{
public:
    void show()
    {
        cout << "this is a histogram" << endl;
    }
};

class ChatPie : public ChatInterface
{
public:
    void show()
    {
        cout << "this is a pie" << endl;
    }
};

class ChatLine : public ChatInterface
{
public:
    void show()
    {
        cout << "this is a line" << endl;
    }
};

class Factory
{
public:
    static ChatInterface* getChat(string chat)
    {
        if (chat == "Pie") {
            return new ChatPie();
        }else if (chat == "Line") {
            return new ChatLine();
        }else if (chat == "Histogram") {
            return new ChatHistogram();
        }
    }
private:
    // static Factory * 
};

int main(int argc, char **argv) {
    ChatInterface *ChatPtr = nullptr;
    ChatPtr = Factory::getChat("Pie");
    ChatPtr->show();
}