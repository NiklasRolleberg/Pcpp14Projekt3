#ifndef CURVEBASE_H
#define CURVEBASE_H
#include "Point.hpp"

class Curvebase {
protected:
    double pmin = 0; //vad är detta?
    double pmax = 0;
    //double a;
    //double b;

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
        double tol = length/1000;
        double target = s*length;
        double a = pmin;
        double b = pmax;
        double current = (b-a)/2;

        int max = 10;
        double tempLength = integrate(pmin,current);
        while(std::abs(tempLength-target)>tol)
        {
            if(tempLength>target)
            {
                b = current;
            }
            else
            {
                a = current;
            }
            current = a+ ((b-a)/2);
            tempLength = integrate(pmin,current);
            //std::cerr << "Current: " << current << "\t tempL: " << tempLength << "\t target: " << target << " [" << a << " , " << b << "]" << std::endl;
        }

        return xp(current);
    }
    double y(double s) //arc length parametrization s e[0,1];
    {
        double tol = length/1000;
        double target = s*length;
        double a = pmin;
        double b = pmax;
        double current = (b-a)/2;

        int max = 10;
        double tempLength = integrate(pmin,current);
        while(std::abs(tempLength-target)>tol)
        {
            if(tempLength>target)
            {

                b = current;
            }
            else
            {
                a = current;
            }
            current = a+ ((b-a)/2);
            tempLength = integrate(pmin,current);
            //std::cerr << "Current: " << current << "\t tempL: " << tempLength << "\t target: " << target << " [" << a << " , " << b << "]" << std::endl;
        }
        return yp(current);
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

        pmin = 0;
        pmax = 1;

        xStart = a_.X();
        yStart = a_.Y();

        Point avst = b_+(-a_);
        length = sqrt(avst.X()*avst.X()+avst.Y()*avst.Y());

        dx = avst.X();
        dy = avst.Y();

        /*std::cerr << "\t\tLength: " << length << " dx: "<< dx << " dy:" << dy << std::endl;
        std::cerr << "integrate test" << std::endl;
        std::cerr << "0->0: " << integrate(0,0) << std::endl;
        std::cerr << "0->0.5: " << integrate(0,0.5) << std::endl;
        std::cerr << "0->1: " << integrate(0,1) << std::endl;*/
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

        //double alength = a*sqrt(dx*dx+dy*dy); //length 0->a
        double blength = b*length;//sqrt(dx*dx+dy*dy); //length 0->b
        return blength;//-alength;
    }
};

/**--------------------------Curve class----------------------*/
class Curve : public Curvebase
{
public:
    Curve(int j)
    {
        std::cerr << "Curve constructor" << std::endl;
        pmax = 5;
        pmin = -10;

        length = integrate(pmin,pmax);
    }

    ~Curve()
    {
        std::cerr << "destructor Curve" << std::endl;
    }

private:
    double xp(double p) //finv(p)
    {
        return p;
    }
    double yp(double p) //f(p)
    {
        if(p<=-3)
        {
            return 0.5/(1+exp(-3*p));
        }
        return 0.5/(1+exp(-3*(p+6)));
    }
    double dxp(double p)
    {
        return 1;
    }
    double dyp(double p)
    {
        double g = (exp(- 3*p - 18) + 1);
        return (3*exp(- 3*p - 18))/(2*(g*g));
    }

    double integrate(double a, double b)
    {
        double l = 0;
        double h = 0.01;
        double s = a;
        while (s<=b)
        {
            double xx = dxp(s);
            double yy = dyp(s);
            l += sqrt(xx*xx + yy*yy);
            s+=h;
        }
    }
};

#endif // CURVEBASE_H
