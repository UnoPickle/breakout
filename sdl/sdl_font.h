#pragma once
#include <filesystem>
#include <SDL3_ttf/SDL_ttf.h>

#include "sdl_surface.h"

class sdl_font
{
public:
    sdl_font(const std::filesystem::path& path, const float point_size);
    ~sdl_font();

    TTF_Font* get_font() const;
    sdl_surface generate_surface(const std::string& text, const SDL_Color color) const;

private:
    TTF_Font* m_font = nullptr;
};
