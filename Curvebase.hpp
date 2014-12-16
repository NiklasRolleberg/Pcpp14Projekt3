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

double integrate(double a, double b)
{
    //räkna ut avståndet från a till b
    return 0;
}

class Line : public Curvebase
{
public:
    Line(double a_, double b_) : a(a_), b(b_) {}
private:
    double xp(double p) = 0;
    double yp(double p) = 0;
    double dxp(double p) = 0;
    double dyp(double p) = 0;
};

#endif // CURVEBASE_H
