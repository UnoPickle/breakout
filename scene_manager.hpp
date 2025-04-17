#pragma once
#include "scenes/iscene.h"
#include "scenes/test_scene.h"

class scene_manager
{
public:
    scene_manager() = default;

    template <class T, class ... Args>
    void set_scene(Args&&... args);

    [[nodiscard]] iscene* active_scene() const;

private:
    std::unique_ptr<iscene> m_scene = nullptr;
};

template <typename T, typename ... Args>
void scene_manager::set_scene(Args&&... args)
{
    if (m_scene != nullptr)
    {
        m_scene->exit();
    }

    m_scene = std::make_unique<T>(std::forward<Args>(args)...);

    m_scene->start();
}


extern scene_manager g_scene_manager;
