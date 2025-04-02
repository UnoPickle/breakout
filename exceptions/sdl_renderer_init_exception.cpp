

#include "sdl_renderer_init_exception.h"

sdl_renderer_init_exception::sdl_renderer_init_exception(const std::string& message) : sdl_exception("[ sdl_renderer_init_exception ]: " + message)
{
}
