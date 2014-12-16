#include "Curvebase.hpp"

class Domain {
public:
    Domain(Curvebase&, Curvebase&, Curvebase&, Curvebase&);

    void generate_grid ();
    // more members

private:
    Curvebase *sides[4];
    // more members
};
