#include "test_scene.h"

#include <iostream>

#include "../input.h"

test_scene::test_scene() : _img_surf("assets/snail.bmp"), _img_obj(_img_surf, {0, 0})
{
    add_object(_img_obj);
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
