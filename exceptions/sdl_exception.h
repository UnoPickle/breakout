#ifndef SDL_EXCEPTION_H
#define SDL_EXCEPTION_H
#include "breakout_exception.h"


class sdl_exception : public breakout_exception
{
public:
    explicit sdl_exception(const std::string& message);
};


#endif //SDL_EXCEPTION_H
