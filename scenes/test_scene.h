#pragma once
#include "iscene.h"
#include "../vo/image_obj.h"


class test_scene : public iscene
{
public:
    test_scene();

    void start() override;
    void update(const uint64_t deltatime) override;
    void exit() override;

    ~test_scene() override;

private:
    sdl_surface _img_surf;
    image_obj _img_obj;
};
