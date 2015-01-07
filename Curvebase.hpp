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
    public:
    double length;
    protected:
    //(......)

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    virtual double integrate(Point a, Point b) = 0;//arc length integral

public:
    Curvebase() {}

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
private:
    double dx;
    double dy;

public:
    Line(Point a_, Point b_)
    {
        std::cerr << "line constructor" << std::endl;

        a = a_;
        b = b_;

        Point p = b+(-a);
        dx = p.X();
        dy = p.Y();

        length = integrate(a,b);


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

    double integrate(Point a, Point b) //räknar ut längden av kurvan
    {
        Point avst = b+(-a);
        return sqrt(avst.X()*avst.X()+avst.Y()*avst.Y());
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
    double xp(double p) //finv(p)
    {
        return 0;
    }
    double yp(double p) //f(p)
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

    double integrate(Point a, Point b)
    {
        length = 0;
        double h = 0.01;
        double s = 0;
        while (s<=1)
        {
            double xx = dxp(s);
            double yy = dyp(s);
            length += sqrt(xx*xx + yy*yy);
            s+=h;
        }
    }
};

#endif // CURVEBASE_H
