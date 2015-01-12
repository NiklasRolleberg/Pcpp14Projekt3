#include "Curvebase.hpp"
#include <cstdlib>
#include <memory>
#include <cstdio>

class Domain {
public:
    Domain(Curvebase&, Curvebase&, Curvebase&, Curvebase&);
    Domain(const Domain& d);
    Domain &operator=(Domain &d);
    ~Domain();
    void generate_grid (int m, int n);
    void writeToFile();
    // more members
    bool check_consistency();
private:
    //std::array<Curvebase, 10> sides;
    Curvebase* sides[4];
    //std::shared_ptr<Curvebase> sides[4];
    double *x_, *y_;
    int m_, n_;
    //bool check_consistency();
    // more members
    double fi1(double s);
    double fi2(double s);
    double FIx(double e1, double e2);
    double FIy(double e1, double e2);
};

//Constructor
Domain::Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4)
{
    sides[0] = &s1;
    sides[1] = &s2;
    sides[2] = &s3;
    sides[3] = &s4;

   if (~check_consistency())
        exit(0);
        //sides[0] = sides[1] = sides[2] = sides[3] = nullptr;

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
        double hy = 1./(m_-1);
        double hx = 1./(n_-1);

        for(int i=0; i<n_; i++)
        {
            for(int j=0; j<m_; j++)
            {
                x_[j+i*m_] = FIx(hx*i, hy*j);
                y_[j+i*m_] = FIy(hx*i, hy*j);
            }
        }
    }
}


Domain::~Domain()
{
    std::cerr << "Domain destructor" << std::endl;;
    if (m_ > 0)
    {
        delete [] x_;
        delete [] y_;
    }
}

bool Domain::check_consistency()
{
    std::cout << "Check_constistency" << std::endl;
    std::cout << "Line 0: (" << sides[0]->x(0) << " , " << sides[0]->y(0) << ") \t (" << sides[0]->x(1) << " , " << sides[0]->y(1) << ")" << std::endl;
    std::cout << "Line 1: (" << sides[1]->x(0) << " , " << sides[1]->y(0) << ") \t (" << sides[1]->x(1) << " , " << sides[1]->y(1) << ")" << std::endl;
    std::cout << "Line 2: (" << sides[2]->x(0) << " , " << sides[2]->y(0) << ") \t (" << sides[2]->x(1) << " , " << sides[2]->y(1) << ")" << std::endl;
    std::cout << "Line 3: (" << sides[3]->x(0) << " , " << sides[3]->y(0) << ") \t (" << sides[3]->x(1) << " , " << sides[3]->y(1) << ")" << std::endl;

    if ( true )
        return true;
    else
        return false;
}

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
    double FIx = fi1(e1)*sides[3]->x(e2) + fi2(e1)*sides[1]->x(e2) + fi1(e2)*sides[0]->x(e1) + fi2(e2)*sides[2]->x(e1)
                -fi1(e1)*fi1(e2)*sides[0]->x(0)
                -fi2(e1)*fi1(e2)*sides[1]->x(1)
                -fi1(e1)*fi2(e2)*sides[2]->x(0)
                -fi2(e1)*fi2(e2)*sides[1]->x(0);
    return FIx;
}

double Domain::FIy(double e1, double e2)
{
    //std::cerr << "FIy"<< std::endl;
    double FIy = fi1(e1)*sides[3]->y(e2) + fi2(e1)*sides[1]->y(e2) + fi1(e2)*sides[0]->y(e1) + fi2(e2)*sides[2]->y(e1)
                -fi1(e1)*fi1(e2)*sides[0]->y(0)
                -fi2(e1)*fi1(e2)*sides[1]->y(1)
                -fi1(e1)*fi2(e2)*sides[2]->y(0)
                -fi2(e1)*fi2(e2)*sides[1]->y(0);
    return FIy;
}

void Domain::writeToFile()
{
    FILE *fp;
    fp =fopen("X.bin","wb");
    fwrite(x_,sizeof(double),m_*n_,fp);
    fclose(fp);

    fp =fopen("Y.bin","wb");
    fwrite(y_,sizeof(double),m_*n_,fp);
    fclose(fp);
}

