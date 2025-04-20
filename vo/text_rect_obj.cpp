#include "text_rect_obj.h"

text_rect_obj::text_rect_obj(TTF_Font* font, const std::string& text, const SDL_Color text_color,
                             const SDL_Color rect_color, const float text_rect_padding,
                             const vector2& start_pos) : ivisual_obj(start_pos),
                                                         m_text_rect_padding(text_rect_padding),
                                                         m_text(font, text, text_color, start_pos), m_bg(rect_color, {0, 0}, start_pos)
{
    recalc_bg();

    generate_surface();
}

sdl_surface& text_rect_obj::get_surf()
{
    return m_blittable->get_surf();
}

void text_rect_obj::set_bg_color(const SDL_Color new_color)
{
    m_bg.set_color(new_color);

    generate_surface();
}

void text_rect_obj::set_fg_color(const SDL_Color new_color)
{
    m_text.set_color(new_color);

    generate_surface();
}

void text_rect_obj::set_text(const std::string& new_text)
{
    m_text.set_text(new_text);
    recalc_bg();

    generate_surface();
}

void text_rect_obj::recalc_bg()
{
    m_bg.resize({
    static_cast<float>(m_text.get_surf().surface_object()->w) + m_text_rect_padding * 2,
    static_cast<float>(m_text.get_surf().surface_object()->h) + m_text_rect_padding * 2,
});
}

void text_rect_obj::generate_surface()
{
    vector2 bg_size = m_bg.size();
    vector2 blittable_start_pos = {0, 0};
    m_blittable = std::make_unique<rect_obj>(m_bg.color(), bg_size, blittable_start_pos);

    const SDL_Rect dst_rect = {static_cast<int>(m_text_rect_padding), static_cast<int>(m_text_rect_padding), m_bg.get_surf().surface_object()->w, m_bg.get_surf().surface_object()->h};
    m_blittable->get_surf().blit_surface(m_text.get_surf(), nullptr, &dst_rect);
}
