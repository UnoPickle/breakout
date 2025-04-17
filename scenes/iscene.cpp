#include "iscene.h"

#include <algorithm>

void iscene::render(const sdl_renderer& renderer)
{
    for (const std::shared_ptr object : m_objects)
    {
        ivisual_obj& vis_obj = object->object();

        SDL_Surface* surf = vis_obj.get_surf().surface_object();
        sdl_texture tex(renderer, vis_obj.get_surf());
        renderer.render_texture(tex, {0, 0, (float)surf->w, (float)surf->h}, {
                                    vis_obj.get_pos().x, vis_obj.get_pos().y, (float)surf->w, (float)surf->h
                                });
    }
}

scene_obj& iscene::add_object(ivisual_obj& object)
{
    const std::shared_ptr<scene_obj> new_obj = m_objects.
        emplace_back(std::make_shared<scene_obj>(object, get_new_id()));

    return *new_obj;
}

void iscene::remove_object(const scene_obj_id obj_id)
{
    const auto obj_it = std::find_if(m_objects.begin(), m_objects.end(), [obj_id](const std::shared_ptr<scene_obj>& obj)
    {
        return obj->id() == obj_id;
    });


    if (obj_it != m_objects.end())
    {
        m_objects.erase(obj_it);
    }
}

scene_obj_id iscene::get_new_id()
{
    const scene_obj_id new_iud = m_cur_id;
    m_cur_id++;

    return new_iud;
}
