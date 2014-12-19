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

    double dx;
    double dy;
    //(......)

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;

    double integrate(Point a, Point b) //arc length integral
    {
        //räknar ut längden av kurvan
        Point avst = b+(-a);
        return sqrt(avst.X()*avst.X()+avst.Y()*avst.Y());
    }

public:
    Curvebase() //constructor
    {
        std::cerr << "Curvebase()" << std::endl;
    }

    double x(double s) //arc length parametrization
    {
        return  xp(s*length);
    }
    double y(double s) //arc length parametrization s e[0,1];
    {
        return yp(s*length); //fel kanske
    }
};

/**---------------------------Line class------------------------------*/
class Line : public Curvebase
{
public:
    Line(Point a_, Point b_)
    {
        std::cerr << "line constructor" << std::endl;

        a = a_;
        b = b_;
        length = integrate(a,b);
        Point p = b+(-a);

        dx = p.X() / length;
        dy = p.Y() / length;

        std::cerr << "\t\tLength: " << length << " dx: "<< dx << " dy:" << dy << std::endl;
    }

    ~Line()
    {
        std::cerr << "destructor Line" << std::endl;
    }

private:
    double xp(double p)
    {
        return a.X() + dx*p;
    }
    double yp(double p)
    {
        return a.Y() + dy*p;
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
