#ifndef CURVEBASE_H
#define CURVEBASE_H
#include <cmath>

class Curvebase {
protected:
    double pmin;
    double pmax;
    double length;

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;


    /** arc length integral - calculates the arc length for a curve */
    double integrate(double a, double b)
    {
        return adaptiveSimpsons(a, b, 0.000000001, 10);
    }

    double adaptiveSimpsonsAux(double a, double b, double epsilon, double S, double fa, double fb, double fc, int bottom) {
      double c = (a + b)/2, h = b - a;
      double d = (a + c)/2, e = (c + b)/2;
      double fd = sqrt(dxp(d)*dxp(d)+dyp(d)*dyp(d));
      double fe = sqrt(dxp(e)*dxp(e)+dyp(e)*dyp(e));
      double Sleft = (h/12)*(fa + 4*fd + fc);
      double Sright = (h/12)*(fc + 4*fe + fb);
      double S2 = Sleft + Sright;
      if (bottom <= 0 || fabs(S2 - S) <= 15*epsilon)
        return S2 + (S2 - S)/15;
      return adaptiveSimpsonsAux(a, c, epsilon/2, Sleft,  fa, fc, fd, bottom-1) +
             adaptiveSimpsonsAux(c, b, epsilon/2, Sright, fc, fb, fe, bottom-1);
    }

    double adaptiveSimpsons(double a, double b, double epsilon,int maxRecursionDepth) {
      double c = (a + b)/2, h = b - a;
      double fa = sqrt(dxp(a)*dxp(a)+dyp(a)*dyp(a));
      double fb = sqrt(dxp(b)*dxp(b)+dyp(b)*dyp(b));
      double fc = sqrt(dxp(c)*dxp(c)+dyp(c)*dyp(c));;
      double S = (h/6)*(fa + 4*fc + fb);
      return adaptiveSimpsonsAux(a, b, epsilon, S, fa, fb, fc, maxRecursionDepth);
    }


public:
    Curvebase() {}

    /** Arc length parameterization, 0 <= s <= 1 */
    double x(double s)
    {
        double err, tol=1e-12, p1;
        int it, maxit=100;
        it = 0; err = tol + 1;

        double p = pmin + s*((pmax-pmin)/2);
        while( err > tol && it < maxit )
        {
            double funktion = integrate(pmin,p)-s*length;
            double derrivata = 1/((pmax-pmin)/100) * (integrate(pmin,p + ((pmax-pmin)/100)) - integrate(pmin,p));
            p1 = p - (funktion/derrivata);
            err = fabs( p1 - p ); p = p1; it++;
        }

        if( err <= tol )
            return xp(p);
        else
            std::cout << "Error, no convergence \n";
        return  0;
    }

    /** Arc length parameterization, 0 <= s <= 1 */
    double y(double s)
    {
        double err, tol=1e-12, p1;
        int it, maxit=100;
        it = 0; err = tol + 1;

        double p = pmin + s*((pmax-pmin)/2);
        while( err > tol && it < maxit )
        {
            double funktion = integrate(pmin,p)-s*length;
            double derrivata = 1/((pmax-pmin)/100) * (integrate(pmin,p + ((pmax-pmin)/100)) - integrate(pmin,p));
            p1 = p - (funktion/derrivata);
            err = fabs( p1 - p ); p = p1; it++;
        }

        if( err <= tol )
            return yp(p);
        else
            std::cout << "Error, no convergence \n";
        return  0;
    }
};

/**---------------------------Line class------------------------------
 * The Line class creates a line from (x,y) = (x0,y0) to (x,y) = (x1,y1)
 */
class Line : public Curvebase
{
private:
    double x0, y0, x1, y1;
    double dx;
    double dy;

    double xp(double p)
    {
        return (1-p)*x0 + p*x1;
    }
    double yp(double p)
    {
        return (1-p)*y0 + p*y1;
    }
    double dxp(double p)
    {
        return dx;
    }
    double dyp(double p)
    {
        return dy;
    }

public:
    Line(double x_0, double y_0, double x_1, double y_1)
    {
        x0 = x_0; y0 = y_0; x1 = x_1; y1 = y_1;
        dx = x1-x0;
        dy = y1-y0;
        length = sqrt(dy*dy+dx*dx);
        pmin = 0;
        pmax = 1;
    }

    ~Line()
    {
        std::cerr << "destructor Line" << std::endl;
    }
};

/**--------------------------Curve class----------------------
 * The curve class creates a curve (defined in the description for project 3) from (x,y) = (-10,0) to (x,y) = (5,0)
 */
class Curve : public Curvebase
{
public:
    Curve(bool s)
    {
        //std::cerr << "Curve constructor" << std::endl;
        pmax = 5;
        pmin = -10;
        length = integrate(pmin,pmax);
    }

    ~Curve()
    {
        std::cerr << "destructor Curve" << std::endl;
    }

private:
    double xp(double p)
    {
        return p;
    }
    double yp(double p)
    {
        if(p<=-3)
        {
            return 0.5/(1+exp(-3*(p+6)));
        }
        return 0.5/(1+exp(3*p));
    }
    double dxp(double p)
    {
        return 1;
    }
    double dyp(double p)
    {
        if(p<=-3)
        {
            double d = (exp(- 3*p - 18) + 1);
            return (3*exp(- 3*p - 18))/(2*d*d);
        }

        double d = (exp(3*p) + 1);
        return -(3*exp(3*p))/(2*d*d);
    }
};


#endif // CURVEBASE_H
