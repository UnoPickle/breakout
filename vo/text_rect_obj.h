#pragma once
#include "ivisual_obj.h"
#include "rect_obj.h"
#include "text_obj.h"
#include "../sdl/sdl_font.h"

class text_rect_obj : public ivisual_obj
{
public:
    text_rect_obj(TTF_Font* font, const std::string& text, const SDL_Color text_color, const SDL_Color rect_color,
                  const float text_rect_padding, const vector2& start_pos);
    ~text_rect_obj() override = default;

    sdl_surface& get_surf() override;

    void set_bg_color(const SDL_Color new_color);
    void set_fg_color(const SDL_Color new_color);
    void set_text(const std::string& new_text);

private:
    void recalc_bg();

    void generate_surface();
    float m_text_rect_padding;

    text_obj m_text;
    rect_obj m_bg;

    std::unique_ptr<rect_obj> m_blittable;
};
