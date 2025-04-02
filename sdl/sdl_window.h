#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H
#include <cstdint>
#include <string>
#include <SDL3/SDL_video.h>


class sdl_window
{
public:
    sdl_window(const std::string& title, uint32_t w, uint32_t h, SDL_WindowFlags flags);
    ~sdl_window();

    [[nodiscard]] SDL_WindowID id() const;
    [[nodiscard]] SDL_Window* window_object() const;

private:
    SDL_Window* _window = nullptr;
};


#endif //SDL_WINDOW_H
