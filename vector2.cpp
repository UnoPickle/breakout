

#include "vector2.h"

vector2::vector2(const int64_t x, const int64_t y) : x(x), y(y)
{
}

vector2::vector2(const vector2& other)
{
    *this = other;
}

vector2& vector2::operator=(const vector2& other)
{
    x = other.x;
    y = other.y;

    return *this;
}
