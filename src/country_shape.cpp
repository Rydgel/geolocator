#include <iostream>
#include <sstream>
#include "country_shape.h"
#include "tools.h"

using namespace std;
using namespace std::experimental;


CountryShape::CountryShape()
{
    const char* filename = "resources/ne_10m_admin_0_countries/ne_10m_admin_0_countries.shp";
    poDataset = OGRSFDriverRegistrar::Open(filename, false);

    if (poDataset == nullptr) {
        cout << "Can't open shapefile" << endl;
        exit(EXIT_FAILURE);
    }
}

optional<Country> CountryShape::get_country_with_coord(double latitude, double longitude)
{
    const string point = tools::coord_to_point(latitude, longitude);
    ostringstream sqlStream;
    sqlStream << "SELECT name, name_long, formal_en, wb_a2, wb_a3, continent,"
              << "region_un, subregion, region_wb "
              << "FROM ne_10m_admin_0_countries "
              << "WHERE ST_Intersects(GeomFromText('" << point << "'), geometry)";

    OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
    // just in case
    layer->ResetReading();

    OGRFeature *feature = layer->GetNextFeature();

    if (feature == nullptr) { return nullopt; }

    Country c = Country(feature);
    OGRFeature::DestroyFeature(feature);
    optional<Country> oC = c;

    return oC;
}

CountryShape::~CountryShape()
{
    OGRReleaseDataSource(poDataset);
}





