#pragma once
#include "sdl_exception.h"

class sdl_font_init_exception : public sdl_exception
{
public:
    explicit sdl_font_init_exception(const std::string& message);
};
