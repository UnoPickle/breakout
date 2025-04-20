#pragma once
#include "ivisual_obj.h"
#include "../sdl/sdl_font.h"

class text_obj : public ivisual_obj
{
public:
    text_obj(const sdl_font& font, const std::string& text, const SDL_Color color, const vector2& start_pos);
    ~text_obj() override = default;

    sdl_surface& get_surf() override;

private:
    sdl_surface m_text_surf;
};
