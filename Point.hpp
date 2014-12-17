#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    /** variables */
    double x;
    double y;

public:
    /** constructors */
    Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) { }
    Point(const Point& Q): x(Q.x), y(Q.y) { }
    ~Point()
    {
        std::cerr << "destructor: Point" << std::endl;
    }

    /** functions */
    inline double X() const { return x; }
    inline double Y() const { return y; }
    void zero() { x = y = 0.0; }

    /** operators */
    Point& operator=(const Point& P) {
        std::cerr << "\t= operator" << std::endl;
        if (this != &P) {
            x = P.x; // equivalent: (*this).x = P.x;
            y = P.y;
        }
        return *this; // dereferencing!
    }

    const Point operator-() const {
        std::cerr << "\t -() operator" << std::endl;
        return Point(-x,-y);
    }

    Point operator+(const Point& Q) const {
        std::cerr << "\t + operator" << std::endl;
        return Point(x+Q.x,y+Q.y);
    }

    inline Point& operator+=(const Point& Q) {
        std::cerr << "\t += operator" << std::endl;
        x += Q.x;
        y += Q.y;
        return *this;
    }

    /*
    ostream& operator<‌<(ostream& os, const Point& P) {
        os <‌< "(" <‌< P.X() <‌< ", " <‌< P.Y() <‌< ")";
        return os;
    }
    istream& operator>‌>(istream& is, Point& P) {
        double x, y;
        is >‌> x >‌> y;
        if (is) // Success?
            P = Point(x,y);
        else
            P = Point();
        return is;
    }
    */
};
#endif // POINT_H


/*
class Point2 {
private:
double r;
double phi;
public:
double X() { return r*std::cos(phi); }
double Y() { return r*std::sin(phi); }
void zero() { r = phi = 0.0; }
};
*/
