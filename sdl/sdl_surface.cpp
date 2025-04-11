#include "sdl_surface.h"

#include "../exceptions/sdl_surface_init_exception.h"

sdl_surface::sdl_surface(const std::string& filename)
{
    _surface = SDL_LoadBMP(filename.c_str());

    if (_surface == nullptr)
    {
        throw sdl_surface_init_exception("couldn't load " + filename);
    }
}

sdl_surface::sdl_surface(const sdl_surface& other)
{
    *this = other;
}

sdl_surface::~sdl_surface()
{
    SDL_DestroySurface(_surface);
}

SDL_Surface* sdl_surface::surface_object() const
{
    return _surface;
}

sdl_surface& sdl_surface::operator=(const sdl_surface& other)
{
    _surface = other._surface;
    return *this;
}
