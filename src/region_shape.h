#ifndef GEOLOCATOR_REGION_SHAPE_H
#define GEOLOCATOR_REGION_SHAPE_H

#include <ogr_api.h>
#include <ogrsf_frmts.h>
#include "region.h"
#include "../lib/optional.hpp"

using namespace std::experimental;

class RegionShape
{
private:
    // GDAL file handler
    OGRDataSource *poDataset;

public:
    RegionShape();
    optional<Region> get_region_with_coord(double latitude, double longitude);
    ~RegionShape();
};


#endif //GEOLOCATOR_REGION_SHAPE_H
