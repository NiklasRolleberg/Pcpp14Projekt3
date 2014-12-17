#ifndef CURVEBASE_H
#define CURVEBASE_H
#include "Point.hpp"

class Curvebase {
protected:
    double pmin; //vad är detta?
    double pmax;
    Point a;
    Point b;
    //int rev; // orientation of the curve
    double length;
    //(......)

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;

    double integrate(Point a, Point b) //arc length integral
    {
        //räknar ut längden av kurvan
        return 0;
    }

public:
    Curvebase() //constructor
    {
        std::cerr << "Curvebase()" << std::endl;
    }

    double x(double s) //arc length parametrization
    {
        return xp(s*(b.X()-a.X()) + a.X()); //fel kanske
    }
    double y(double s) //arc length parametrization s e[0,1];
    {
        return xp(s*(b.Y()-a.Y()) + a.Y()); //fel kanske
    }
};

/**---------------------------Line class------------------------------*/
class Line : public Curvebase
{
private:
    double dx_;
    double dy_;

public:
    Line(Point a_, Point b_)
    {
        a = a_;
        b = b_;
    }

    ~Line()
    {
        std::cerr << "destructor Line" << std::endl;
    }

private:
    double xp(double p)
    {
        return 0;
    }
    double yp(double p)
    {
        return 0;
    }
    double dxp(double p)
    {
        return 0;
    }
    double dyp(double p)
    {
        return 0;
    }
};

/**--------------------------Curve class----------------------*/
class Curve : public Curvebase
{
private:
    double dx_;
    double dy_;

public:
    Curve(Point a_, Point b_)
    {
        a = a_;
        b = b_;
    }

    ~Curve()
    {
        std::cerr << "destructor Curve" << std::endl;
    }

private:
    double xp(double p)
    {
        return 0;
    }
    double yp(double p)
    {
        return 0;
    }
    double dxp(double p)
    {
        return 0;
    }
    double dyp(double p)
    {
        return 0;
    }
};

#endif // CURVEBASE_H
