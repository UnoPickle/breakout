#include "font_resource.h"

#include "../exceptions/sdl_font_init_exception.h"

font_resource::font_resource(const std::string& path) : iresource(resource_type::FONT), m_font_path(path)
{
}

TTF_Font* font_resource::get_font(const float point_size) const
{
    TTF_Font* font = TTF_OpenFont(m_font_path.string().c_str(), point_size);

    if (font == nullptr)
    {
        throw sdl_font_init_exception("failed to load font file: " + m_font_path.string());
    }

    return font;
}
