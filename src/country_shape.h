#ifndef GEOLOCATOR_COUNTRY_SHAPE_H
#define GEOLOCATOR_COUNTRY_SHAPE_H

#include <ogr_api.h>
#include <ogrsf_frmts.h>
#include <experimental/optional>
#include "country.h"

using namespace std::experimental;


class CountryShape
{
private:
    // GDAL file handler
    OGRDataSource *poDataset;

public:
    CountryShape();
    optional<Country> get_country_with_coord(double latitude, double longitude);
    ~CountryShape();
};


#endif //GEOLOCATOR_COUNTRY_H
