#include "sdl_renderer.h"


#include "../exceptions/sdl_renderer_init_exception.h"

sdl_renderer::sdl_renderer(const sdl_window& window) : _window(window)
{
    _renderer = SDL_CreateRenderer(_window.window_object(), nullptr);

    if (_renderer == nullptr)
    {
        throw sdl_renderer_init_exception("couldn't create sdl_renderer");
    }
}

sdl_renderer::~sdl_renderer()
{
    SDL_DestroyRenderer(_renderer);
}

void sdl_renderer::render_texture(sdl_texture& texture, const SDL_FRect& srcrect, const SDL_FRect& dstrect) const
{
    SDL_RenderTexture(_renderer, texture.texture_object(), &srcrect, &dstrect);
}

SDL_Renderer* sdl_renderer::renderer_object() const
{
    return _renderer;
}

void sdl_renderer::render() const
{
    SDL_RenderPresent(_renderer);
}

void sdl_renderer::clear() const
{
    SDL_RenderClear(_renderer);
}
