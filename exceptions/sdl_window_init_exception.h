

#ifndef SDL_WINDOW_INIT_EXCEPTION_H
#define SDL_WINDOW_INIT_EXCEPTION_H
#include "breakout_exception.h"
#include "sdl_exception.h"


class sdl_window_init_exception : public sdl_exception{
public:
    explicit sdl_window_init_exception(const std::string& message);
};



#endif //SDL_WINDOW_INIT_EXCEPTION_H
