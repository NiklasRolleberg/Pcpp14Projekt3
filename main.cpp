#include <iostream>
#include <cmath>
#include "Domain.hpp"
#include "Curvebase.hpp"
#include "Point.hpp"

using namespace std;

int main()
{
	cout << "HEJSAN"<< endl;

	/*test*/
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

    Line L1(Point(0,0), Point(0,1));
    Line L2(Point(1,0), Point(1,1));
    Line L3(Point(1,1), Point(0,1));
    Line L4(Point(0,1), Point(0,0));

    Domain D = Domain(L1, L2, L3, L4);

    D.generate_grid(2, 3);

	return 0;
}
