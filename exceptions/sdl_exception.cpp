#include "sdl_exception.h"

#include <SDL3/SDL_error.h>

sdl_exception::sdl_exception(const std::string& message) : breakout_exception(
    message + " (" + std::string(SDL_GetError()) + ")")
{
    SDL_ClearError();
}
