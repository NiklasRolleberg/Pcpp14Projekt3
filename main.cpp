#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"
//#include <cstdio>

using namespace std;

int main()
{
    int m = 0;
    int n = 0;
	cout << "Choose m and n\nm: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    cout << "Creating a grid " << m << " x " << n << " points" << endl;


    Curve C(true);
    //Line L0(-10, 0, 5, 0);
    Line L1(5, 3, 5, 0);
    Line L2(-10, 3, 5, 3);
    Line L3(-10, 3, -10, 0);

    Domain D = Domain(C, L1, L2, L3);
    //Domain D = Domain(L0, L1, L2, L3);
    D.generate_grid(m, n);

    D.writeToFile();

	return 0;
}
