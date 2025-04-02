#include "breakout.h"


breakout::breakout() : _window("my game", 1920, 1080, 0), _sdl_renderer(_window)
{
}

breakout::~breakout()
{
}

void breakout::start()
{
    sdl_surface surface("assets/snail.bmp");
    sdl_texture texture(_sdl_renderer, surface);

    _sdl_renderer.render_texture(texture, SDL_FRect { 0, 0, 256, 256}, SDL_FRect { 0, 0, 512, 256});
    _sdl_renderer.render();

    system("pause");
}
