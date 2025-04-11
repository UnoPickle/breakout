#include "test_scene.h"

test_scene::test_scene() : _img_surf("assets/snail.bmp"), _img_obj(_img_surf, true, {0, 0})
{
    add_object(_img_obj);
}

void test_scene::start()
{
}

void test_scene::update(const uint64_t deltatime)
{
    static float i = 0;
    i++;
    _img_obj.set_pos({i / 50 * deltatime, 0});
}

void test_scene::exit()
{
}

test_scene::~test_scene()
{
}
