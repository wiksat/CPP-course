//
// Created by wikto on 19.04.2023.
//

#include "circle.h"

namespace Shapes {
    Circle::Circle(int xCenter, int yCenter, int radius) noexcept: x_center(xCenter), y_center(yCenter), radius(radius) {}

    bool Circle::isIn(int x, int y) const {
        return (x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) <= radius * radius;
    }

    int Circle::x() const {
        return x_center;
    }

    int Circle::y() const {
        return y_center;
    }

    int Circle::getRadius() const {
        return radius;
    }
} // Shapes