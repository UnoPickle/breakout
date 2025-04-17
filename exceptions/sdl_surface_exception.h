#pragma once
#include "sdl_exception.h"

class sdl_surface_exception : public sdl_exception
{
public:
    explicit sdl_surface_exception(const std::string& message);
};
