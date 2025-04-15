#include "breakout_scene.h"

#include "../input.h"
#include "../resources/image_resource.h"
#include "../resources/resource_manager.h"

breakout_scene::breakout_scene() : m_player(
    static_cast<image_resource*>(g_resource_manager.get_resource("assets/snail.bmp"))->get_surface(), true, {0, 0})
{
    add_object(m_player);
}

void breakout_scene::start()
{
}

void breakout_scene::update(double deltatime)
{
    if (g_input.get_key(SDL_SCANCODE_RIGHT) == key_state::DOWN)
    {
        m_player.set_pos({ static_cast<float>(m_player.get_pos().x + deltatime * 100), 0});
    }
}

void breakout_scene::exit()
{
}
