#include "scene_obj.h"

scene_obj::scene_obj(ivisual_obj& object, const scene_obj_id id) : m_object(object), m_id(id)
{
}

/*scene_obj& scene_obj::operator=(const scene_obj& other)
{
    this->m_object = other.m_object;
    this->m_id = other.m_id;

    return *this;
}*/

ivisual_obj& scene_obj::object() const
{
    return m_object;
}

const scene_obj_id scene_obj::id() const
{
    return m_id;
}
