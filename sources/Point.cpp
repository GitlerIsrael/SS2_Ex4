//
// Created by israel on 5/15/23.
//

#include <iostream>
#include <cmath>
#include "Point.hpp"

namespace ariel {

    //  Returns x coordinate value.
    double Point::getXval() {
        return  x_val;
    }

    // Returns y coordinate value.
    double Point::getYval() {
        return  y_val;
    }

    // Calculate the distance between 2 point objects.
    double Point::distance(const Point &other) const {
        double dx = x_val - other.x_val;
        double dy = y_val - other.y_val;
        return std::sqrt(dx * dx + dy * dy);
    }

    // Print point object details.
    void Point::print() const {
        std::cout << "(" << x_val<< ", " << y_val << ")";
    }

    // Returns point object which represent the movement from point src to point dest with max distance dist.
    Point Point::moveTowards(const Point &src, const Point &dest, double dist) {
        if (dist < 0) throw std::invalid_argument("argument must be non-negative");
        double d = src.distance(dest);
        if (d <= dist) {
            return dest;
        } else {
            double dx = dest.x_val - src.x_val;
            double dy = dest.y_val - src.y_val;
            double factor = dist / d;
            double new_x = src.x_val + dx * factor;
            double new_y = src.y_val + dy * factor;
            return Point(new_x, new_y);
        }
    }
}