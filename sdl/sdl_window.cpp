#include "sdl_window.h"

#include "../exceptions/sdl_window_init_exception.h"

sdl_window::sdl_window(const std::string& title, const uint32_t w, const uint32_t h, const SDL_WindowFlags flags)
{
    _window = SDL_CreateWindow(title.c_str(), w, h, flags);

    if (_window == nullptr)
    {
        throw sdl_window_init_exception("unable to create new window");
    }
}

sdl_window::~sdl_window()
{
    SDL_DestroyWindow(_window);
}

SDL_WindowID sdl_window::id() const
{
    return SDL_GetWindowID(_window);
}

SDL_Window* sdl_window::window_object() const
{
    return _window;
}
