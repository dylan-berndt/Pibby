

#ifndef PIBBY_VECTOR_H
#define PIBBY_VECTOR_H

#include "pico/stdlib.h"

class Vector  {
public:
    Vector(uint16_t x, uint16_t y) : x_(x), y_(y) {}
    uint16_t x() const {return x_;};
    uint16_t y() const {return y_;};
private:
    const uint16_t x_;
    const uint16_t y_;
};

#endif //PIBBY_VECTOR_H
