#include "AmountOfTryExceptions.h"

const char* AmountOfTryExceptions::what() const throw()
{
    return "Amount of try has exceeded!";
}
