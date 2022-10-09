#include <string>
#include <iostream>

using namespace std;

class LoggerInterface
{
public:
    virtual void writeLog(const string & msg) = 0;
};

class FileLogger : public LoggerInterface
{
public:
    void writeLog(const string & msg)
    {
        if (msg.empty()) {
            cout << "file log: empty log" << endl;
        } else {
            cout << "file log: " << msg << endl;
        }
    }
};


class DataBaseLogger : public LoggerInterface
{
public:
    void writeLog(const string & msg)
    {
        if (msg.empty()) {
            cout << "data base log: empty log" << endl;
        } else {
            cout << "data base log:" << msg << endl;
        }
    }
};

class FactoryInterface
{
public:
    virtual LoggerInterface * createLogger(const string & loggerName) = 0;
};

class FactoryFileLogger : public FactoryInterface
{
public:
    LoggerInterface * createLogger(const string & loggerName)
    {
        return new FileLogger();
    }
};

class FactoryDataBaseLogger : public FactoryInterface
{
public:
    LoggerInterface * createLogger(const string & loggerName)
    {
        return new DataBaseLogger();
    }
};

int main(int argc, char *argv[])
{
    auto factory = new FactoryDataBaseLogger();
    auto logger = factory->createLogger("logger");
    logger->writeLog("data base");
}