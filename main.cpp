#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"

using namespace std;

int main()
{
	cout << "HEJSAN"<< endl;


	cout << "curve test" << std::endl;
	Curve test(true);
	//Line test(0,0,0,1);
    /*
    test.y(0);
    std::cout << "\nx(0)" << std::endl;
    test.x(0);
    std::cout << "\nx(0.5)" << std::endl;
    test.x(0.5);
    std::cout << "\nx(1)" << std::endl;
    test.x(1);
    */
    cout << "\n\npoints on curve" << std::endl;
    int n=10;
    double steg = 1./(n-1);
    for(int i=0;i<n;i++)
        std::cout << "\n\ns=" << i*steg << " point: (" << test.x(i*steg) << "," << test.y(i*steg) << ")" << std::endl;

    //Curve C(true);
    Line L0(-10, 0, 5, 0);
    Line L1(5, 0, 5, 3);
    //Line L2(5, 3, -10, 3);
    Line L2(-10, 3, 5, 3);
    //Line L3(-10, 3, -10, 0);
    Line L3(-10, 0, -10, 3);

    //Domain D = Domain(C, L1, L2, L3);
    Domain D = Domain(L0, L1, L2, L3);

    D.generate_grid(4, 4);

    D.writeToFile();

	return 0;
}
