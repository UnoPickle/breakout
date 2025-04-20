#include "sdl_font.h"

#include <iostream>

#include "../exceptions/sdl_font_exception.h"
#include "../exceptions/sdl_font_init_exception.h"

sdl_font::sdl_font(const std::filesystem::path& path, const float point_size) : m_font(
    TTF_OpenFont(path.string().c_str(), point_size))
{
    if (m_font == nullptr)
    {
        throw sdl_font_init_exception("failed to load font file: " + path.string());
    }
}

sdl_font::~sdl_font()
{
    TTF_CloseFont(m_font);
}

TTF_Font* sdl_font::get_font() const
{
    return m_font;
}

sdl_surface sdl_font::generate_surface(const std::string& text, const SDL_Color color) const
{
    SDL_Surface* surf = TTF_RenderText_Blended(m_font, text.c_str(), text.length(), color);

    if (surf == nullptr)
    {
        throw sdl_font_exception("could not generate surface from font \"" + std::string(TTF_GetFontStyleName(m_font)) + "\" with text \"" + text + "\"");
    }

    return sdl_surface(surf);
}
