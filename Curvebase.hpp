#ifndef CURVEBASE_H
#define CURVEBASE_H
#include <cmath>

class Curvebase {
protected:
    double pmin; //vad är detta?
    double pmax;
    //double a;
    //double b;
    //int rev; // orientation of the curve
    double length;

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;


    double integrate(double a, double b) //arc length integral
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

    double x(double s) //arc length parametrization
    {
        //lös f(p) = integrate(a,p) - s*length
        double err, tol=1e-12, p1;
        int it, maxit=100;
        it = 0; err = tol + 1;

        double p = pmin + s*((pmax-pmin)/2);
        //std::cerr << "pstart= " << p << std::endl;
        while( err > tol && it < maxit )
        {
            double funktion = integrate(pmin,p)-s*length;
            double derrivata = 1/((pmax-pmin)/100) * (integrate(pmin,p + ((pmax-pmin)/100)) - integrate(pmin,p));
            p1 = p - (funktion/derrivata);
            err = fabs( p1 - p ); p = p1; it++;

            //std::cerr << "Newtons metod. f= " << funktion << "\t f'= " << derrivata << "\t p = " << p << std::endl;
        }

        if( err <= tol )
            return xp(p);
        else
            std::cout << "Error, no convergence \n";
        return  0;
    }

    double y(double s) //arc length parametrization s e[0,1];
    {
        /*
        std::cerr << "\nfUNKTIONS TEST!" << std::endl;

        std::cerr << "\nintegrate(pmin,pmax): " << integrate(pmin,pmax) << std::endl;
        std::cerr << "integrate(pmin,pmin+(pmax-pmin)/2): " << integrate(pmin,pmin+(pmax-pmin)/2) << std::endl;

        std::cerr << "\nxp((pmax-pmin)/2): " << xp((pmax-pmin)/2) << std::endl;
        std::cerr << "yp((pmax-pmin)/2): " << yp((pmax-pmin)/2) << std::endl;

        std::cerr << "\ndxp((pmax-pmin)/2): " << dxp((pmax-pmin)/2) << std::endl;
        std::cerr << "dyp((pmax-pmin)/2): " << dyp((pmax-pmin)/2) << std::endl;
        */

        //lös f(p) = integrate(a,p) - s*length
        double err, tol=1e-12, p1;
        int it, maxit=100;
        it = 0; err = tol + 1;

        double p = pmin + s*((pmax-pmin)/2);
        //std::cerr << "pstart= " << p << std::endl;
        while( err > tol && it < maxit )
        {
            double funktion = integrate(pmin,p)-s*length;
            double derrivata = 1/((pmax-pmin)/100) * (integrate(pmin,p + ((pmax-pmin)/100)) - integrate(pmin,p));
            p1 = p - (funktion/derrivata);
            err = fabs( p1 - p ); p = p1; it++;

            //std::cerr << "Newtons metod. f= " << funktion << "\t f'= " << derrivata << "\t p = " << p << std::endl;
        }

        if( err <= tol )
            return yp(p);
        else
            std::cout << "Error, no convergence \n";
        return  0;
    }
};

/**---------------------------Line class------------------------------*/
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
        std::cerr << "line length: " << length << std::endl;
        pmin = 0;
        pmax = 1;
    }

    ~Line()
    {
        std::cerr << "destructor Line" << std::endl;
    }
};

/**--------------------------Curve class----------------------*/
class Curve : public Curvebase
{
public:
    Curve(bool s)
    {
        std::cerr << "Curve constructor" << std::endl;
        pmax = 5;
        pmin = -10;
        length = integrate(pmin,pmax);
        std::cerr << "Curve length " << length << std::endl;
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
