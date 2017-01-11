#ifndef GEOLOCATOR_REGION_SHAPE_H
#define GEOLOCATOR_REGION_SHAPE_H

#include <ogr_api.h>
#include <ogrsf_frmts.h>
#include "region.h"
#include "woe_data.h"
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
    optional<std::string> generateRegionNameByCode(const char *code);
    optional<WoeData> getGeoFromWoeId(const char *woeId);
    ~RegionShape();
};


#endif //GEOLOCATOR_REGION_SHAPE_H
