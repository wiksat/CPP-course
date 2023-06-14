//
// Created by wikto on 19.04.2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H

#include "shape.h"

namespace Shapes {

    class Rectangle: public Shape{
    private:
        int xFrom_, yFrom_, xTo_, yTo_;
    public:
        Rectangle(int xFrom, int yFrom, int xTo, int yTo) noexcept;
        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const;

        [[nodiscard]] int xTo() const;

        [[nodiscard]] int y() const;

        [[nodiscard]] int yTo() const;
    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
