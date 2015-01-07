#ifndef CURVEBASE_H
#define CURVEBASE_H
#include "Point.hpp"

class Curvebase {
protected:
    double pmin = 0; //vad är detta?
    double pmax = 0;;
    double a;
    double b;

    double xStart;
    double yStart;

    //int rev; // orientation of the curve
    public:

    double length;
    protected:
    //(......)

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    virtual double integrate(double a, double b) = 0;//arc length integral

public:
    Curvebase() {}

    double x(double s) //arc length parametrization
    {
        //return  xp(s*length);
        return  xp(s*length);
    }
    double y(double s) //arc length parametrization s e[0,1];
    {
        //return yp(s*length); //fel kanske
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


        xStart = a_.X();
        yStart = a_.Y();

        Point avst = b_+(-a_);
        length = sqrt(avst.X()*avst.X()+avst.Y()*avst.Y());

        dx = avst.X();
        dy = avst.Y();

        std::cerr << "\t\tLength: " << length << " dx: "<< dx << " dy:" << dy << std::endl;
    }

    ~Line()
    {
        std::cerr << "destructor Line" << std::endl;
    }

private:
    double xp(double p)
    {
        return xStart + dx*p;
    }
    double yp(double p)
    {
        return yStart + dy*p;
    }
    double dxp(double p)
    {
        return dx;
    }
    double dyp(double p)
    {
        return dy;
    }

    double integrate(double a, double b) //räknar ut längden av kurvan
    {
        double sv = 0;
        return sv;
    }
};

/**--------------------------Curve class----------------------*/
class Curve : public Curvebase
{
public:
    Curve()
    {
        std::cerr << "Curve constructor" << std::endl;
        pmax = 5;
        pmin = -10;
    }

    ~Curve()
    {
        std::cerr << "destructor Curve" << std::endl;
    }

private:
    double xp(double p) //finv(p)
    {
        if(p>pmax || p<pmin)
            return 0;

        if(p<=-3)
        {

            return 1;
        }
        return 8945;
    }
    double yp(double p) //f(p)
    {
        return 1;
    }
    double dxp(double p)
    {
        return 1;
    }
    double dyp(double p)
    {
        return 1;
    }

    double integrate(double a, double b)
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
