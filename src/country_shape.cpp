#include <iostream>
#include <sstream>
#include "country_shape.h"
#include "tools.h"

using namespace std;

CountryShape::CountryShape()
{
    const char* filename = "resources/ne_10m_admin_0_countries/ne_10m_admin_0_countries.shp";
    poDataset = OGRSFDriverRegistrar::Open(filename, false);

    if (poDataset == nullptr) {
        cout << "Can't open shapefile" << endl;
        exit(EXIT_FAILURE);
    }
}

Country CountryShape::getCountryWithCoord(double latitude, double longitude)
{
    const string point = tools::coordToPoint(latitude, longitude);
    ostringstream sqlStream;
    sqlStream << "SELECT name, name_long, formal_en, wb_a2, wb_a3, continent,"
              << "region_un, subregion, region_wb "
              << "FROM ne_10m_admin_0_countries "
              << "WHERE ST_Intersects(GeomFromText('" << point << "'), geometry)";

    OGRLayer *layer = poDataset->ExecuteSQL(sqlStream.str().c_str(), nullptr, "SQLite");
    // just in case
    layer->ResetReading();

    Country c = Country();

    for (OGRFeature *feature = layer->GetNextFeature(); feature != nullptr;
         feature = layer->GetNextFeature()) {

        c.set = true;
        c.m_name = feature->GetFieldAsString(0);
        c.m_nameLong = feature->GetFieldAsString(1);
        c.m_formalEn = feature->GetFieldAsString(2);
        c.m_wbA2 = feature->GetFieldAsString(3);
        c.m_wbA3 = feature->GetFieldAsString(4);
        c.m_continent = feature->GetFieldAsString(5);
        c.m_regionUn = feature->GetFieldAsString(6);
        c.m_subregion = feature->GetFieldAsString(7);
        c.m_regionWb = feature->GetFieldAsString(8);

        OGRFeature::DestroyFeature(feature);
    }


    return c;
}

CountryShape::~CountryShape()
{
    OGRReleaseDataSource(poDataset);
}





