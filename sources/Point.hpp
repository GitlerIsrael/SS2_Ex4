#pragma once

#include <iostream>

namespace ariel {
    class Point {

    private:
        double x_val;
        double y_val;

    public:
        //Constructor
        Point(double x , double y) : x_val(x) , y_val(y){}
//        ~Point() = default;

        int getXval();
        int getYval();
        double distance(const Point &other) const;
        void print() const;
        friend Point moveTowards(const Point& src, const Point& dest, double dist);
    };
}