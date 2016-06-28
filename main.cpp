#include <iostream>
#include <gdal.h>
#include "country_shape.h"

using namespace std;

int main()
{
    GDALAllRegister();
    OGRRegisterAll();
    CountryShape *cs = new CountryShape();
    Country c = cs->getCountryWithCoord(48.8534100f, 2.3488000f);
    cout << c.m_name << endl;

    return EXIT_SUCCESS;
}