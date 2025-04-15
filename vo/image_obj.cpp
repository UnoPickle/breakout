#include "image_obj.h"

image_obj::image_obj(sdl_surface &surf, const bool collideable, const vector2 &start_pos)
    : ivisual_obj(collideable, start_pos), _img_surf(surf) {
}

void image_obj::start() {
}

void image_obj::exit() {
}

sdl_surface &image_obj::get_surf() {
    return _img_surf;
}
