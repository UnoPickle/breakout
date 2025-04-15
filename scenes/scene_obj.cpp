#include "scene_obj.h"

scene_obj::scene_obj(ivisual_obj& object, const scene_obj_id& id) : _object(object), _id(id)
{
}

ivisual_obj& scene_obj::object() const
{
    return _object;
}

const scene_obj_id scene_obj::id() const
{
    return _id;
}
