

#ifndef SDL_STARTUP_EXCEPTION_H
#define SDL_STARTUP_EXCEPTION_H
#include "breakout_exception.h"
#include "sdl_exception.h"


class sdl_startup_exception : public sdl_exception{
public:
    explicit sdl_startup_exception(const std::string& message);
};



#endif //SDL_STARTUP_EXCEPTION_H
