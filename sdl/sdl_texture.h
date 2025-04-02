#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H
#include "sdl_renderer.h"
#include "sdl_surface.h"

class sdl_renderer;

class sdl_texture
{
public:
    sdl_texture(const sdl_renderer& ren_context, const sdl_surface& surface);
    ~sdl_texture();

    [[nodiscard]] SDL_Texture* texture_object() const;

private:
    SDL_Texture* _texture;
};


#endif //SDL_TEXTURE_H
