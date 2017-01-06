#ifndef GEOLOCATOR_COUNTRY_H
#define GEOLOCATOR_COUNTRY_H

#include <string>
#include <ogr_feature.h>
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

class Country
{
public:
    string m_name;
    string m_name_long;
    string m_formal_en;
    string m_wb_a2;
    string m_wb_a3;
    string m_continent;
    string m_region_un;
    string m_subregion;
    string m_region_wb;

    Country(OGRFeature *feature);
    string to_json();
    ~Country() {};
};


#endif //GEOLOCATOR_COUNTRY_H
