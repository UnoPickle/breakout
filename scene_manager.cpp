#include "scene_manager.hpp"

scene_manager g_scene_manager;

iscene* scene_manager::active_scene() const
{
    return m_scene.get();
}

