#ifndef IMAGE_OBJ_H
#define IMAGE_OBJ_H
#include "ivisual_obj.h"


class image_obj : public ivisual_obj
{
public:
    image_obj(sdl_surface& surf, const vector2& start_pos);

    sdl_surface& get_surf() override;
    ~image_obj() override = default;

protected:
    sdl_surface& _img_surf;
};


#endif //IMAGE_OBJ_H
