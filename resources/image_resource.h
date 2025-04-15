#pragma once
#include <string>

#include "iresource.h"
#include "../sdl/sdl_surface.h"

class image_resource : public iresource {
public:
    explicit image_resource(const std::string &path);

    sdl_surface& get_surface();
private:
    sdl_surface m_surface;
};
