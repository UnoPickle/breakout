#include "text_obj.h"

text_obj::text_obj(TTF_Font* font, const std::string& text, const SDL_Color color, const vector2& start_pos) :
    ivisual_obj(start_pos), m_font(font), m_text(text), m_color(color),
    m_text_surface(std::make_unique<sdl_surface>(m_font.generate_surface(m_text, m_color)))
{
}

text_obj::~text_obj()
{
}

sdl_surface& text_obj::get_surf()
{
    return *m_text_surface;
}

void text_obj::set_text(const std::string& text)
{
    m_text = text;
    m_text_surface = std::make_unique<sdl_surface>(m_font.generate_surface(m_text, m_color));
}

void text_obj::set_color(const SDL_Color new_color)
{
    m_color = new_color;
    m_text_surface = std::make_unique<sdl_surface>(m_font.generate_surface(m_text, m_color));
}
