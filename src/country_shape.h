#ifndef GEOLOCATOR_COUNTRY_SHAPE_H
#define GEOLOCATOR_COUNTRY_SHAPE_H

#include <ogr_api.h>
#include <ogrsf_frmts.h>
#include "country.h"


class CountryShape
{
private:
    // GDAL file handler
    OGRDataSource *poDataset;

public:
    CountryShape();
    Country getCountryWithCoord(double latitude, double longitude);
    ~CountryShape();
};


#endif //GEOLOCATOR_COUNTRY_H
