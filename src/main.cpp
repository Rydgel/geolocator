#include <iostream>
#include <gdal.h>
#include "country_shape.h"

using namespace std;
using namespace std::experimental;

int main(int argc,char **argv)
{
    GDALAllRegister();
    OGRRegisterAll();
    CountryShape *cs = new CountryShape();

    optional<Country> c = cs->getCountryWithCoord(48.8534100f, 2.3488000f);
    if (c) {
        cout << c.value().toJson().dump() << endl;
    } else {
        // 404
        cout << "{\"error\": \"country not found\"}" << endl;
    }

    // dealloc stuff
    delete cs;

    return EXIT_SUCCESS;
}