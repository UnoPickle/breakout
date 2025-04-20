#include "test_scene.h"

#include <iostream>

#include "../resources/font_resource.h"
#include "../resources/resource_manager.h"

test_scene::test_scene() : m_text_surf(
                               static_cast<font_resource*>(g_resource_manager.
                                   get_resource("assets/Jersey10-Regular.ttf"))->get_font(20.5f), "hello world",
                               {0xff, 0, 0, 0x00}, {0, 0}), _img_surf("assets/snail.bmp"), _img_obj(_img_surf, {0, 0})
{
    //add_object(_img_obj);
    add_object(m_text_surf);
}

void test_scene::start()
{
}

void test_scene::update(const double deltatime)
{
}

void test_scene::exit()
{
}

test_scene::~test_scene()
{
}
