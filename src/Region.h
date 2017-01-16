#ifndef GEOLOCATOR_REGION_H
#define GEOLOCATOR_REGION_H

#include <string>
#include <ogr_feature.h>
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

class Region
{
public:
    string m_name;
    string m_region;
    string m_iso_a2;
    string m_objectid_1;
    string m_woe_id;

    Region(OGRFeature *feature);
    string toJson();
    ~Region() {};
};


#endif //GEOLOCATOR_REGION_H
