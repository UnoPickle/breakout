

#include "ivisual_obj.h"

ivisual_obj::ivisual_obj(bool collideable, const vector2& start_pos) : _collideable(collideable), _pos(start_pos)
{
}

void ivisual_obj::set_pos(const vector2& pos)
{
    _pos = pos;
}

vector2 ivisual_obj::get_pos() const
{
    return _pos;
}
