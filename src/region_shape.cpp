#include "region_shape.h"
#include <iostream>
#include <sstream>
#include "tools.h"

using namespace std;
using namespace std::experimental;

std::mutex mtxRegion;


RegionShape::RegionShape()
{
    const char* filename = "resources/ne_10m_admin_1_states_provinces/ne_10m_admin_1_states_provinces.shp";

    poDataset = OGRSFDriverRegistrar::Open(filename, false);

    if (poDataset == nullptr) {
        cout << "Can't open shapefile" << endl;
        exit(EXIT_FAILURE);
    }
}

optional<Region> RegionShape::get_region_with_coord(double latitude, double longitude)
{
    const string point = tools::coord_to_point(latitude, longitude);
    ostringstream sqlStream;
    sqlStream << "SELECT name, region, iso_a2, objectid_1, woe_id "
              << "FROM ne_10m_admin_1_states_provinces "
              << "WHERE ST_Intersects(GeomFromText('" << point << "'), geometry)";

    std::lock_guard<std::mutex> lock(mtxRegion);
    OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
    // just in case
    layer->ResetReading();

    OGRFeature *feature = layer->GetNextFeature();

    if (feature == nullptr) { return nullopt; }

    Region r(feature);
    OGRFeature::DestroyFeature(feature);
    optional<Region> oR(r);

    poDataset->ReleaseResultSet(layer);

    return oR;
}

RegionShape::~RegionShape()
{
    OGRReleaseDataSource(poDataset);
}
