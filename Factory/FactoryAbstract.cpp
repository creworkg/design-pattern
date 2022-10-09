#include <string>
#include <iostream>

using namespace std;

class ButtonInterface
{
public:
    virtual void onPress() = 0;
};

class ButtonSpring : public ButtonInterface
{
public:
    void onPress()
    {
        cout << "onPress spring button" << endl;
    }
};

class ButtonSummer : public ButtonInterface
{
public:
    void onPress()
    {
        cout << "onPress summer button" << endl;
    }
};

class TextFieldInterface
{
public:
    virtual void onInput() = 0;
};

class TextFieldSpring : public TextFieldInterface
{
public:
    void onInput()
    {
        cout << "onInput spring text field" << endl;
    }
};

class TextFieldSummer : public TextFieldInterface
{
public:
    void onInput()
    {
        cout << "onInput summer text field" << endl;
    }
};

class ComboxInterface
{
public:
    virtual void onClick() = 0;
};

class ComboxSpring : public ComboxInterface
{
public:
    void onClick()
    {
        cout << "onClick spring combox" << endl;
    }
};

class ComboxSummer : public ComboxInterface
{
public:
    void onClick()
    {
        cout << "onClick summer combox" << endl;
    }
};

class FactoryInterface
{
public:
    virtual ComboxInterface * createCombox() = 0;
    virtual TextFieldInterface * createTextField() = 0;
    virtual ButtonInterface * createButton() = 0;
};

class FactorySpring : public FactoryInterface
{
public:
    ComboxInterface * createCombox()
    {
        return new ComboxSpring();
    }
    TextFieldInterface * createTextField()
    {
        return new TextFieldSpring();
    }
    ButtonInterface * createButton()
    {
        return new ButtonSpring();
    }
};

class FactorySummer : public FactoryInterface
{
public:
    ComboxInterface * createCombox()
    {
        return new ComboxSummer();
    }
    TextFieldInterface * createTextField()
    {
        return new TextFieldSummer();
    }
    ButtonInterface * createButton()
    {
        return new ButtonSummer();
    }
};

int main(int argc, char ** argv)
{
    FactorySpring factory;
    auto button = factory.createButton();
    button->onPress();
    delete button;
}


