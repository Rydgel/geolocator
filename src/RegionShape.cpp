#include "RegionShape.h"
#include <iostream>
#include <sstream>
#include "Tools.h"

using namespace std;
using namespace std::experimental;

// std::mutex mtxRegion;

RegionShape::RegionShape()
{
    const char* filename = "resources/ne_10m_admin_1_states_provinces/ne_10m_admin_1_states_provinces.shp";

    poDataset = OGRSFDriverRegistrar::Open(filename, false);

    if (poDataset == nullptr) {
        cout << "Can't open shapefile" << endl;
        exit(EXIT_FAILURE);
    }
}

optional<Region> RegionShape::getRegionWithCoord(double latitude, double longitude)
{
    const string point = tools::coordToPoint(latitude, longitude);

    ostringstream sqlStream;
    sqlStream << "SELECT name, region, iso_a2, objectid_1, woe_id "
              << "FROM ne_10m_admin_1_states_provinces "
              << "WHERE ST_Intersects(GeomFromText('" << point << "'), geometry)";

    // std::lock_guard<std::mutex> lock(mtxRegion);

    try {
        OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
        layer->ResetReading(); // just in case
        OGRFeature *feature = layer->GetNextFeature();
        if (feature == nullptr) { return nullopt; }
        Region r(feature);
        OGRFeature::DestroyFeature(feature);
        optional<Region> oR(r);
        poDataset->ReleaseResultSet(layer);
        return oR;
    } catch (...) {
        return nullopt;
    }
}

// todo check if you can make it static?
optional<std::string> RegionShape::generateCountryNameByCode(const char *code)
{
    // I'm not sure why, I just took what I found in the PHP code
    if (strcmp(code, "AU") == 0 || strcmp(code, "au") == 0) {
        return make_optional(string("Australia"));
    }

    ostringstream sqlStream;
    sqlStream << "SELECT admin FROM ne_10m_admin_1_states_provinces WHERE "
              << "iso_a2 = \"" << code << "\""
              << " LIMIT 1";

    // std::lock_guard<std::mutex> lock(mtxRegion);

    try {
        OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
        layer->ResetReading(); // just in case
        OGRFeature *feature = layer->GetNextFeature();
        if (feature == nullptr) { return nullopt; }
        string countryName = feature->GetFieldAsString(0);
        OGRFeature::DestroyFeature(feature);
        poDataset->ReleaseResultSet(layer);
        return make_optional(countryName);
    } catch (...) {
        return nullopt;
    }
}

optional<std::string> RegionShape::generateRegionNameByCode(int code)
{
    ostringstream sqlStream;
    sqlStream << "SELECT admin FROM ne_10m_admin_1_states_provinces WHERE objectid_1=\""
              << code
              << "\" LIMIT 1";

    // std::lock_guard<std::mutex> lock(mtxRegion);

    try {
        OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
        layer->ResetReading(); // just in case
        OGRFeature *feature = layer->GetNextFeature();
        if (feature == nullptr) { return nullopt; }
        string regionName = feature->GetFieldAsString(0);
        OGRFeature::DestroyFeature(feature);
        poDataset->ReleaseResultSet(layer);
        return make_optional(regionName);
    } catch (...) {
        return nullopt;
    }
}

optional<WoeData> RegionShape::getGeoFromWoeId(int woeId)
{
    ostringstream sqlStream;
    sqlStream << "SELECT name, region, iso_a2, objectid_1 "
              << "FROM ne_10m_admin_1_states_provinces WHERE woe_id=\""
              << woeId
              << "\" LIMIT 1";

    // std::lock_guard<std::mutex> lock(mtxRegion);

    try {
        OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
        layer->ResetReading(); // just in case
        OGRFeature *feature = layer->GetNextFeature();
        if (feature == nullptr) { return nullopt; }
        WoeData w(feature);
        OGRFeature::DestroyFeature(feature);
        optional<WoeData> oW(w);
        poDataset->ReleaseResultSet(layer);
        return oW;
    } catch (...) {
        return nullopt;
    }
}

RegionShape::~RegionShape()
{
    OGRReleaseDataSource(poDataset);
}
