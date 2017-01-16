#ifndef GEOLOCATOR_WOE_DATA_H
#define GEOLOCATOR_WOE_DATA_H

#include <string>
#include <ogr_feature.h>
#include "../lib/rapidjson/writer.h"
#include "../lib/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;


class WoeData
{
public:
    string m_name;
    string m_region;
    string m_iso_a2;
    string m_objectid_1;

    WoeData(OGRFeature *feature);
    string toJson();
    ~WoeData() {};
};


#endif //GEOLOCATOR_WOE_DATA_H
