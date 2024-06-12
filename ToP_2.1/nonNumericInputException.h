#pragma once
#include <stdexcept>
using namespace std;

class NonNumericInputException :
    public std::exception
{
private:

public:
    NonNumericInputException(const char* msg);
    ~NonNumericInputException();
};
