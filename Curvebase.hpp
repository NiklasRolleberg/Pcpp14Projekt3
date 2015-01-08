#ifndef CURVEBASE_H
#define CURVEBASE_H

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
        //räknar ut längden av kurvan
        return 0;
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
