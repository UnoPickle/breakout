

#include "breakout_exception.h"

breakout_exception::breakout_exception(const std::string& message) : _message(message)
{
}

const char* breakout_exception::what() const noexcept
{
    return _message.c_str();
}
