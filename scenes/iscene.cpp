#include "iscene.h"

void iscene::render(const sdl_renderer& renderer)
{
    for (scene_obj object : _objects)
    {
        sdl_surface surf = object.object().get_surf();
        sdl_texture tex(renderer, surf);
        renderer.render_texture(tex, {0, 0, static_cast<float>(surf.surface_object()->w), static_cast<float>(surf.surface_object()->h)}, {
                                    static_cast<float>(object.object().get_pos().x), static_cast<float>(object.object().get_pos().y),
                                    static_cast<float>(surf.surface_object()->w), static_cast<float>(surf.surface_object()->h)
                                });
    }
}

scene_obj& iscene::add_object(ivisual_obj& object)
{
    scene_obj& new_obj = _objects.emplace_back(object, get_new_id());

    return new_obj;
}

scene_obj_id iscene::get_new_id()
{
    const scene_obj_id new_iud = _cur_id;
    _cur_id++;

    return new_iud;
}
