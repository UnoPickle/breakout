#ifndef VECTOR2_H
#define VECTOR2_H
#include <cstdint>


struct vector2
{
    vector2(int64_t x, int64_t y);
    vector2(const vector2& other);

    vector2& operator=(const vector2& other);

    int64_t x;
    int64_t y;
};


#endif //VECTOR2_H
