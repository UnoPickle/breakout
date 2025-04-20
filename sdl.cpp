#include "sdl.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "exceptions/sdl_startup_exception.h"

sdl::sdl()
{
    int res = SDL_Init(SDL_INIT_VIDEO);

    if (res < 0)
    {
        throw sdl_startup_exception("Couldn't init video");
    }

    res = TTF_Init();
    if (res < 0)
    {
        throw sdl_startup_exception("Couldn't init ttf");
    }
}

sdl::~sdl()
{
    SDL_Quit();
    TTF_Quit();
}
