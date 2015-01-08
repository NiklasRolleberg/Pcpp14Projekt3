#ifndef CURVEBASE_H
#define CURVEBASE_H
#include <cmath>

class Curvebase {
protected:
    double pmin; //vad är detta?
    double pmax;
    double a;
    double b;
    //int rev; // orientation of the curve
    double length;

    double dx;
    double dy;
    //(......)

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
        return  0;
    }
    double y(double s) //arc length parametrization s e[0,1];
    {
        return 0; //fel kanske
    }
};
#endif // CURVEBASE_H
