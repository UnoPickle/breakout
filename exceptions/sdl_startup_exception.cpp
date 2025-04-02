#include "sdl_startup_exception.h"

sdl_startup_exception::sdl_startup_exception(const std::string& message) : sdl_exception(
    "[ sdl_startup_exception ]: " + message)
{

}
