#pragma once
#include "ivisual_obj.h"
#include "../sdl/sdl_font.h"

class text_obj : public ivisual_obj
{
public:
    text_obj(TTF_Font* font, const std::string& text, const SDL_Color color, const vector2& start_pos);
    ~text_obj() override;

    sdl_surface& get_surf() override;

    void set_text(const std::string& text);
    void set_color(SDL_Color new_color);

private:
    sdl_font m_font;
    std::string m_text;
    SDL_Color m_color;
    std::unique_ptr<sdl_surface> m_text_surface;
};
