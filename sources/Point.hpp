#pragma once

#include <iostream>

namespace ariel {
    class Point {

    private:
        double x_val;
        double y_val;

    public:
        //Constructor
        Point(double x_value , double y_value) : x_val(x_value) , y_val(y_value){}
//        ~Point() = default;

        double getXval();
        double getYval();
        double distance(const Point &other) const;
        void print() const;
        static Point moveTowards(const Point& src, const Point& dest, double dist);
    };
}