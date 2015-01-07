#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"
#include "Point.hpp"

using namespace std;

int main()
{
	cout << "HEJSAN"<< endl;

	/*test
	Point P(0.1,0.1);
	Point P1;
	Point P2;
	//Point P3;

	P1 = P;
	P2 = -P;
	P1 += P2;
    std::cout << "P1 = P: -> (" << P.X() << "," << P.Y() << ")" << std::endl;
    std::cout << "P2 = -P: -> (" << P2.X() << "," << P2.Y() << ")" << std::endl;
    std::cout << "P1 += P2: -> (" << P1.X() << "," << P1.Y() << ")" << std::endl;
    */
    Point H1(0,0);
    Point H2(1,0);
    Point H3(1,1);
    Point H4(0,1);

    Line L1(H1, H2);
    Line L2(H2, H3);
    Line L3(H3, H4);
    Line L4(H4, H1);

    /*
    std::cout << "Test innan:" << std::endl;
    std::cout << "s=0: " << L1.x(0) << "\ns=0.5: " << L1.x(0.5) << "\ns=1: "<< L1.x(1) << std::endl;

    Domain D = Domain(L1, L2, L3, L4);

    int n = 2;
    int m = 3;
    D.generate_grid(m, n);*/

    Line test(Point(0,0),Point(1,1));
    std::cout << "Length :" << test.length << std::endl;

	return 0;
}
