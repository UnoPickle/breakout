#include "sdl_surface_init_exception.h"

sdl_surface_init_exception::sdl_surface_init_exception(const std::string& message)
    : sdl_exception("[ sdl_surface_init_exception ]: " + message)
{
}
