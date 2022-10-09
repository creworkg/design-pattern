#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
private:
    Singleton();// = default;
    // static Singleton* instance;
    static shared_ptr<Singleton> _instance;
public:
    ~Singleton();
    static shared_ptr<Singleton> GetInstance();
};

Singleton::Singleton()
{
    cout << "Singleton" << endl;
}

Singleton::~Singleton()
{
    cout << "~Singleton" << endl;
}

shared_ptr<Singleton> Singleton::GetInstance()
{
    // if (instance == nullptr) {
    //     instance = new Singleton();
    // }
    if (_instance == nullptr) {
        _instance = make_shared<Singleton>();
    }
    return _instance;
}

// Singleton* Singleton::instance = nullptr;
static shared_ptr<Singleton> _instance = nullptr;

int main()
{
    auto a = Singleton::GetInstance();
    auto b = Singleton::GetInstance();

    if (a == b) {
        std::cout <<"same" << std::endl;
    }
}