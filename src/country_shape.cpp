#include <iostream>
#include <sstream>
#include "country_shape.h"
#include "tools.h"

using namespace std;
using namespace std::experimental;


std::mutex mtxCountry;

CountryShape::CountryShape()
{
    const char* filename = "resources/ne_10m_admin_0_countries/ne_10m_admin_0_countries.shp";

    poDataset = OGRSFDriverRegistrar::Open(filename, false);

    if (poDataset == nullptr) {
        cout << "Can't open shapefile" << endl;
        exit(EXIT_FAILURE);
    }
}

optional<Country> CountryShape::getCountryWithCoord(double latitude, double longitude)
{
    const string point = tools::coordToPoint(latitude, longitude);

    ostringstream sqlStream;
    sqlStream << "SELECT name, name_long, formal_en, wb_a2, wb_a3, continent,"
              << "region_un, subregion, region_wb "
              << "FROM ne_10m_admin_0_countries "
              << "WHERE ST_Intersects(GeomFromText('" << point << "'), geometry)";

    std::lock_guard<std::mutex> lock(mtxCountry);

    try {
        OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
        layer->ResetReading(); // just in case
        OGRFeature *feature = layer->GetNextFeature();
        if (feature == nullptr) { return nullopt; }
        Country c(feature);
        OGRFeature::DestroyFeature(feature);
        optional<Country> oC(c);
        poDataset->ReleaseResultSet(layer);
        return oC;
    } catch (...) {
        return nullopt;
    }
}

CountryShape::~CountryShape()
{
    OGRReleaseDataSource(poDataset);
}

/// todo add try catches