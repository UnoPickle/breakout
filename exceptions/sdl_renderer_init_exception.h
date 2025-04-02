#ifndef SDL_RENDERER_INIT_EXCEPTION_H
#define SDL_RENDERER_INIT_EXCEPTION_H
#include "sdl_exception.h"


class sdl_renderer_init_exception : public sdl_exception
{
public:
    explicit sdl_renderer_init_exception(const std::string& message);
};


#endif //SDL_RENDERER_INIT_EXCEPTION_H
