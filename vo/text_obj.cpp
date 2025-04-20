#include "text_obj.h"

text_obj::text_obj(const sdl_font& font, const std::string& text, const SDL_Color color, const vector2& start_pos) :
    ivisual_obj(start_pos), m_text_surf(font.generate_surface(text, color))
{
}

sdl_surface& text_obj::get_surf()
{
    return m_text_surf;
}
