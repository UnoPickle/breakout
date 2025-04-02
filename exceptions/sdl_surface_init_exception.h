#ifndef SDL_SURFACE_INIT_EXCEPTION_H
#define SDL_SURFACE_INIT_EXCEPTION_H
#include "sdl_exception.h"


class sdl_surface_init_exception : public sdl_exception
{
public:
    explicit sdl_surface_init_exception(const std::string& message);
};


#endif //SDL_SURFACE_INIT_EXCEPTION_H
