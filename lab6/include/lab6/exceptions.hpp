#ifndef EX_HPP
#define EX_HPP
#include <iostream>
#include <exception>

class MyException
{
private:
    std::string msg;
public:
    MyException(std::string error): msg(error) {}
    const char *what()
    {
        return msg.c_str();
    }
};
#endif