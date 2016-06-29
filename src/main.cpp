#include <iostream>
#include <gdal.h>
#include "country_shape.h"

using namespace std;
using namespace std::experimental;

int main(int argc,char **argv)
{
    GDALAllRegister();
    OGRRegisterAll();

    // Load-all shapefiles
    CountryShape *cs = new CountryShape();

    optional<Country> c = cs->get_country_with_coord(48.8534100f, 2.3488000f);
    if (c) {
        cout << c.value().to_json().dump() << endl;
    } else {
        // 404
        cout << "{\"error\": \"country not found\"}" << endl;
    }

    // dealloc stuff
    delete cs;

    return EXIT_SUCCESS;
}