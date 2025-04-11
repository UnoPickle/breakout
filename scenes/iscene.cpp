#include "iscene.h"

void iscene::render(const sdl_renderer &renderer) {
    for (scene_obj object: _objects) {
        ivisual_obj& vis_obj = object.object();

        SDL_Surface *surf = vis_obj.get_surf().surface_object();
        sdl_texture tex(renderer, vis_obj.get_surf());
        renderer.render_texture(tex, {0, 0, (float) surf->w, (float) surf->h}, {
                                    vis_obj.get_pos().x, vis_obj.get_pos().y,(float) surf->w, (float) surf->h
                                });
    }
}

scene_obj &iscene::add_object(ivisual_obj &object) {
    scene_obj &new_obj = _objects.emplace_back(object, get_new_id());

    return new_obj;
}

scene_obj_id iscene::get_new_id() {
    const scene_obj_id new_iud = _cur_id;
    _cur_id++;

    return new_iud;
}
