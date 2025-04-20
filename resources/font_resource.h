#pragma once
#include <filesystem>
#include <string>

#include "iresource.h"
#include <SDL3_ttf/SDL_ttf.h>

class font_resource : public iresource
{
public:
    explicit font_resource(const std::string &path);

private:
};
