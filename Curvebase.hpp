#ifndef CURVEBASE_H
#define CURVEBASE_H

class Curvebase {
protected:
    double pmin;
    double pmax;
    double a;
    double b;
    int rev; // orientation of the curve
    double length;
    //(......)

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double integrate(double a, double b); //arc length integral
    //(.....)

public:
    Curvebase(); //constructor
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
};

#endif // CURVEBASE_H
