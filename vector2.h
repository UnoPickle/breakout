#ifndef VECTOR2_H
#define VECTOR2_H


struct vector2
{
    vector2(float x, float y);
    vector2(const vector2& other);

    vector2& operator=(const vector2& other);

    float x;
    float y;
};


#endif //VECTOR2_H
