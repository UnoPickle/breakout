#include "image_resource.h"

image_resource::image_resource(const std::string &path) : iresource(resource_type::IMAGE), m_surface(path) {
}

sdl_surface &image_resource::get_surface() {
    return m_surface;
}
