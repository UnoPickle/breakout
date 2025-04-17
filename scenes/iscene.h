#pragma once
#include <memory>
#include <vector>

#include "scene_obj.h"
#include "../sdl/sdl_renderer.h"

class iscene
{
public:
    virtual ~iscene() = default;

    virtual void start() = 0;
    virtual void update(double deltatime) = 0;
    virtual void exit() = 0;

    void render(const sdl_renderer& renderer);
    scene_obj& add_object(ivisual_obj& object);
    void remove_object(scene_obj_id obj_id);

private:
    scene_obj_id get_new_id();

    std::vector<std::shared_ptr<scene_obj>> m_objects;
    scene_obj_id m_cur_id = 0;
};
