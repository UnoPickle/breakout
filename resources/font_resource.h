#pragma once
#include <filesystem>
#include <string>

#include "iresource.h"

#include "../sdl/sdl_font.h"

class font_resource : public iresource
{
public:
    explicit font_resource(const std::string &path);
    [[nodiscard]] TTF_Font* get_font(float point_size) const;

private:
    std::filesystem::path m_font_path;

};
