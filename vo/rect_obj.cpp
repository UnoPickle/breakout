#include "rect_obj.h"

rect_obj::rect_obj(const uint32_t color, const vector2& size, const vector2& start_pos) : ivisual_obj(start_pos), m_color(color)
{
    m_rect = std::make_shared<sdl_surface>(size.x, size.y, SDL_PIXELFORMAT_ARGB8888);
    set_color(color);
}

void rect_obj::resize(const vector2& new_size)
{
    m_rect = std::make_shared<sdl_surface>(new_size.x, new_size.y, SDL_PIXELFORMAT_ARGB8888);
    set_color(m_color);
}

void rect_obj::set_color(const uint32_t color)
{
    m_rect->fill_rect(nullptr, SDL_MapRGB(SDL_GetPixelFormatDetails(m_rect->surface_object()->format), nullptr, color,
                                      color >> 8, color >> 16));
    m_color = color;
}

sdl_surface& rect_obj::get_surf()
{
    return *m_rect;
}
