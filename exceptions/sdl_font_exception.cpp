

#include "sdl_font_exception.h"

sdl_font_exception::sdl_font_exception(const std::string& message) : sdl_exception("[ sdl_font_exception ]: " + message)
{
}
