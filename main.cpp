#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"

using namespace std;

int main()
{
	cout << "HEJSAN"<< endl;

	cout << "curve test" << std::endl;
	//Curve test(true);
	Line test(0,0,0,1);
    cout << "points on curve" << std::endl;
    int n=10;
    double steg = 1./(n-1);
    for(int i=0;i<n;i++)
        std::cout << "\n\ns=" << i*steg << " point: (" << test.x(i*steg) << ")," << std::endl;// test.y(i*steg) << ")" << std::endl;

	return 0;
}
