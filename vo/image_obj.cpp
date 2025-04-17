#include "image_obj.h"

image_obj::image_obj(sdl_surface &surf, const vector2 &start_pos)
    : ivisual_obj(start_pos), _img_surf(surf) {
}

sdl_surface &image_obj::get_surf() {
    return _img_surf;
}
