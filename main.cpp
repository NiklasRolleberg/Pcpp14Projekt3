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


	return 0;
}
