#include "sdl_surface.h"

#include "../exceptions/sdl_surface_init_exception.h"

sdl_surface::sdl_surface(const std::string& filename)
{
    m_surface = SDL_LoadBMP(filename.c_str());

    if (m_surface == nullptr)
    {
        throw sdl_surface_init_exception("couldn't load " + filename);
    }
}

sdl_surface::sdl_surface(const int width, const int height, const SDL_PixelFormat format)
{
    m_surface = SDL_CreateSurface(width, height, format);

    if (m_surface == nullptr)
    {
        throw sdl_surface_init_exception("couldn't create surface");
    }
}

sdl_surface::sdl_surface(SDL_Surface* surface) : m_surface(surface)
{
}

sdl_surface::sdl_surface(const sdl_surface& other)
{
    *this = other;
}

sdl_surface::~sdl_surface()
{
    SDL_DestroySurface(m_surface);
}

void sdl_surface::fill_rect(const SDL_Rect* rect, const uint32_t color) const
{
    if (!SDL_FillSurfaceRect(m_surface, rect, color))
    {
        throw sdl_surface_init_exception("couldn't fill rect");
    }
}

void sdl_surface::blit_surface(const sdl_surface& src) const
{
    blit_surface(src, nullptr, nullptr);
}

void sdl_surface::blit_surface(const sdl_surface& src, const SDL_Rect* src_rect, const SDL_Rect* dst_rect) const
{
    SDL_BlitSurface(src.surface_object(), src_rect, m_surface, dst_rect);
}

SDL_Surface* sdl_surface::surface_object() const
{
    return m_surface;
}

sdl_surface& sdl_surface::operator=(const sdl_surface& other)
{
    m_surface = other.m_surface;
    return *this;
}
