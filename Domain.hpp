#include "Curvebase.hpp"
#include <cstdlib>

class Domain {
public:
    Domain(const Curvebase&, const Curvebase&, const Curvebase&, const Curvebase&);
    Domain(const Domain& d);
    Domain &operator=(Domain &d);
    ~Domain();
    void generate_grid (int m, int n);
    // more members

private:
    Curvebase* sides;
    double *x_, *y_;
    int m_, n_;
    bool check_consistency();
    // more members
    double fi1(double s);
    double fi2(double s);
    double FIx(double e1, double e2);
    double FIy(double e1, double e2);
};

//Constructor
Domain::Domain(const Curvebase& s1, const Curvebase& s2, const Curvebase& s3, const Curvebase& s4)
{
    sides = (Curvebase*)calloc(4,sizeof(Curvebase));

    sides[0] = s1;
    sides[1] = s2;
    sides[2] = s3;
    sides[3] = s4;
    std::cerr << sides[0].x(1)<< std::endl;
   // if (~check_consistency())
     //   sides[0] = sides[1] = sides[2] = sides[3] = nullptr;
    m_ = n_ = 0;
    x_ = y_ = nullptr;
}

//Copy constructor
Domain::Domain(const Domain& d) :
    m_(d.m_), n_(d.n_), x_(NULL), y_(NULL)
    {
        if (m_ > 0)
            {
            x_ = new double[m_*n_];
            y_ = new double[m_*n_];
            for (int i = 0; i < m_*n_; i++)
            {
                x_[i] = d.x_[i];
                y_[i] = d.y_[i];
            }
        }
    }


Domain& Domain::operator=(Domain &d)
{
    if (this != &d)
    {
        // Do not copy to itself
    }
    if (m_ == d.m_ && n_ == d.n_)
    for (int i = 0; i < m_*n_; i++)
    {
        x_[i] = d.x_[i];
        y_[i] = d.y_[i];
    }
    else
    {
        if (m_ > 0)
        {
            delete [] x_;
            delete [] y_;
            x_ = y_ = nullptr;
        }
        m_ = d.m_;
        n_ = d.n_;
        if (m_ > 0)
        {
            x_ = new double[m_*n_];
            y_ = new double[m_*n_];
            for (int i = 0; i < m_*n_; i++)
            {
                x_[i] = d.x_[i];
                y_[i] = d.y_[i];
            }
        }
    }
}

void Domain::generate_grid(int m, int n) {
    std::cerr << "generate_grid"<< std::endl;
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
        double hy = 1./m;
        double hx = 1./n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                x_[i+j*n] = FIx(hx*i, hy*i);
                y_[i+j*n] = FIy(hx*i, hy*i);
            }
        }

    }
}


Domain::~Domain()
{
    std::cerr << "Domain destructor";
    if (m_ > 0)
    {
        delete [] x_;
        delete [] y_;
    }
}

//bool check_consistency()
//{
//    if ( )
//        return true;
//    else
//        return false;
//}

double Domain::fi1(double s)
{
    return s;
}
double Domain::fi2(double s)
{
    return 1-s;
}

double Domain::FIx(double e1, double e2)
{
    std::cerr << "FIx" << std::endl;
    double FIx = fi1(e1)*sides[3].x(e2) + fi2(e1)*sides[1].x(e2) + fi1(e2)*sides[0].x(e1) + fi2(e2)*sides[2].x(e1)
                -fi1(e1)*fi1(e2)*sides[0].x(0)
                -fi2(e1)*fi1(e2)*sides[1].x(0)
                -fi2(e1)*fi1(e2)*sides[0].x(1)
                -fi2(e1)*fi2(e2)*sides[1].x(1);

    return FIx;
}

double Domain::FIy(double e1, double e2)
{
    std::cerr << "FIx"<< std::endl;
    double FIy = fi1(e1)*sides[3].y(e2) + fi2(e1)*sides[1].y(e2) + fi1(e2)*sides[0].y(e1) + fi2(e2)*sides[2].y(e1)
                -fi1(e1)*fi1(e2)*sides[0].y(0)
                -fi2(e1)*fi1(e2)*sides[1].y(0)
                -fi2(e1)*fi1(e2)*sides[0].y(1)
                -fi2(e1)*fi2(e2)*sides[1].y(1);

    return FIy;
}
