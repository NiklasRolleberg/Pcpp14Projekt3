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
    cout << "points on curve" << std::endl;
    int n=10;
    double steg = 1./(n);
    for(int i=0;i<n;i++)
        std::cout << "s=" << i*steg << " point: (" << test.x(i*steg) << "," <<  test.y(i*steg) << ")" << std::endl;

	return 0;
}
