#include "Curvebase.hpp"
#include <cstdlib>

class Domain {
public:
    Domain(const Curvebase&, const Curvebase&, const Curvebase&, const Curvebase&);
    Domain(const Domain&);
    Domain &operator=(Domain &);
    ~Domain();
    void generate_grid (int m, int n);
    // more members

private:
    Curvebase* sides;
    double *x_, *y_;
    int m_, n_;
    bool check_consistency();
    // more members
};

//Constructor
Domain::Domain(const Curvebase& s1, const Curvebase& s2, const Curvebase& s3, const Curvebase& s4)
{
    sides = (Curvebase*)calloc(4,sizeof(Curvebase));

    sides[0] = s1;
    sides[1] = s2;
    sides[2] = s3;
    sides[3] = s4;
    if (~check_consistency())
        sides[0] = sides[1] = sides[2] = sides[3] = nullptr;
    m_ = n_ = 0;
    x_ = y_ = nullptr;
}


void Domain::generate_grid(int m, int n) {
    if (m <= 0 || n <= 0)
    {
        // Do something meaningful
        std::cout << "Size cannot be negative";
        //exit(0);//?
    }
    else
    {
        if (m_ > 0)
        {
            // There exists already a grid!
            delete [] x_;
            delete [] y_;
        }
        m_ = m; n_ = n;
        x_ = new double[m_*n_];
        y_ = new double[m_*n_];
        // Fill x_[] and y_[] with values!


    }
}
