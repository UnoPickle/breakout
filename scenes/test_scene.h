#pragma once
#include "iscene.h"
#include "../vo/image_obj.h"
#include "../vo/text_obj.h"


class test_scene : public iscene
{
public:
    test_scene();

    void start() override;
    void update(double deltatime) override;
    void exit() override;

    ~test_scene() override;

private:
    text_obj m_text_surf;
    sdl_surface _img_surf;
    image_obj _img_obj;
};
