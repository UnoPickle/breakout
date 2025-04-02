#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H
#include <SDL3/SDL_render.h>

#include "sdl_texture.h"
#include "sdl_window.h"

class sdl_texture;

class sdl_renderer
{
public:
    explicit sdl_renderer(const sdl_window& window);
    ~sdl_renderer();

    void render_texture(sdl_texture& texture, const SDL_FRect& srcrect, const SDL_FRect& dstrect) const;
    void render() const;
    void clear() const;

    [[nodiscard]] SDL_Renderer* renderer_object() const;

private:
    SDL_Renderer* _renderer = nullptr;
    const sdl_window& _window;
};


#endif //SDL_RENDERER_H
