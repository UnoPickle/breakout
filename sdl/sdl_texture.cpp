#include "sdl_texture.h"


sdl_texture::sdl_texture(const sdl_renderer& ren_context, const sdl_surface& surface)
{
    _texture = SDL_CreateTextureFromSurface(ren_context.renderer_object(), surface.surface_object());
}

sdl_texture::~sdl_texture()
{
    SDL_DestroyTexture(_texture);
}

SDL_Texture* sdl_texture::texture_object() const
{
    return _texture;
}
