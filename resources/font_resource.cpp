#include "font_resource.h"

font_resource::font_resource(const std::string& path) : iresource(resource_type::FONT), m_font_path(path)
{
}

sdl_font font_resource::get_font(const float point_size) const
{
    return {m_font_path, point_size};
}
