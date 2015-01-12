#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"
//#include <cstdio>

using namespace std;

int main()
{
	cout << "HEJSAN"<< endl;

    Curve C(true);
    //Line L0(-10, 0, 5, 0);
    Line L1(5, 3, 5, 0);
    //Line L2(5, 3, -10, 3);
    Line L2(-10, 3, 5, 3);
    //Line L3(-10, 3, -10, 0);
    Line L3(-10, 3, -10, 0);

    Domain D = Domain(C, L1, L2, L3);
    //Domain D = Domain(L0, L1, L2, L3);
    D.check_consistency();

    //D.generate_grid(30, 150);

    //D.writeToFile();

	return 0;
}
