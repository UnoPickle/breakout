#include "sdl_font_init_exception.h"

sdl_font_init_exception::sdl_font_init_exception(const std::string& message) : sdl_exception("[ sdl_font_init_exception ]: " + message)
{
}
