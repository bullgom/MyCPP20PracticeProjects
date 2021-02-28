#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Control
{
public:
    std::string getInput();

private:
};

std::string Control::getInput()
{
    std::string input;
    std::cin >> input;
    return input;
}


