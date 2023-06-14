//
// Created by wikto on 19.04.2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H

#include "shape.h"

namespace Shapes {

    class Circle: public Shape{
    private:
        int x_center, y_center, radius;
    public:
        Circle(int xCenter, int yCenter, int radius) noexcept;

        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const;

        [[nodiscard]] int y() const;

        [[nodiscard]] int getRadius() const;
    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
