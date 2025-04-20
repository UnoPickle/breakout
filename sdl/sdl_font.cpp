#include "sdl_font.h"

#include "../exceptions/sdl_font_exception.h"


sdl_font::sdl_font(TTF_Font* font) : m_font(font)
{
}

sdl_font::~sdl_font()
{
    TTF_CloseFont(m_font);
}

TTF_Font* sdl_font::get_font() const
{
    return m_font;
}

SDL_Surface* sdl_font::generate_surface(const std::string& text, const SDL_Color color) const
{
    SDL_Surface* surf = TTF_RenderText_Blended(m_font, text.c_str(), text.length(), color);

    if (surf == nullptr)
    {
        throw sdl_font_exception("could not generate surface from font \"" + std::string(TTF_GetFontStyleName(m_font)) + "\" with text \"" + text + "\"");
    }

    return surf;
}
