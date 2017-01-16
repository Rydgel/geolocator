#ifndef GEOLOCATOR_REGION_SHAPE_H
#define GEOLOCATOR_REGION_SHAPE_H

#include <ogr_api.h>
#include <ogrsf_frmts.h>
#include "Region.h"
#include "WoeData.h"
#include "../lib/optional.hpp"

using namespace std::experimental;

class RegionShape
{
private:
    // GDAL file handler
    OGRDataSource *poDataset;

public:
    RegionShape();
    optional<Region> getRegionWithCoord(double latitude, double longitude);
    optional<std::string> generateCountryNameByCode(const char* code);
    optional<std::string> generateRegionNameByCode(int code);
    optional<WoeData> getGeoFromWoeId(int woeId);
    ~RegionShape();
};


#endif //GEOLOCATOR_REGION_SHAPE_H
