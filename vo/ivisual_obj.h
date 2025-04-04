#ifndef IVISUAL_OBJ_H
#define IVISUAL_OBJ_H
#include "../vector2.h"
#include "../sdl/sdl_surface.h"


class ivisual_obj
{
public:
    ivisual_obj(bool collideable, const vector2& start_pos);
    virtual ~ivisual_obj() = default;

    virtual void start() = 0;
    virtual void update(uint64_t deltatime) = 0;
    virtual void exit() = 0;

    virtual sdl_surface& get_surf() = 0;

    void set_pos(const vector2& pos);
    [[nodiscard]] vector2 get_pos() const;

protected:
    bool _collideable = false;
    vector2 _pos;
};


#endif //IVISUAL_OBJ_H
