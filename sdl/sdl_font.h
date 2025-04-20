#pragma once
#include <filesystem>
#include <SDL3_ttf/SDL_ttf.h>

#include "sdl_surface.h"

class sdl_font
{
public:
    explicit sdl_font(TTF_Font* font);
    ~sdl_font();

    [[nodiscard]] TTF_Font* get_font() const;
    SDL_Surface* generate_surface(const std::string& text, const SDL_Color color) const;

private:
    TTF_Font* m_font = nullptr;
};
