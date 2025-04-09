#pragma once
#include <vector>

#include "scene_obj.h"
#include "../sdl/sdl_renderer.h"

class iscene
{
public:
    void render(const sdl_renderer& renderer);
    scene_obj& add_object(ivisual_obj& object);

private:
    scene_obj_id get_new_id();

    std::vector<scene_obj> _objects;
    scene_obj_id _cur_id = 0;
};
