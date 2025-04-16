#include "sdl_surface_exception.h"

sdl_surface_exception::sdl_surface_exception(const std::string& message) : sdl_exception("[ sdl_surface_exception ]: " + message)
{
}
