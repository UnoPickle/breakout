#pragma once
#include "../vo/ivisual_obj.h"

using scene_obj_id = uint64_t;

class scene_obj
{
public:
    scene_obj(ivisual_obj& object, const scene_obj_id id);



    [[nodiscard]] ivisual_obj& object() const;
    const scene_obj_id id() const;

private:
    ivisual_obj& m_object;
    scene_obj_id m_id;
};


