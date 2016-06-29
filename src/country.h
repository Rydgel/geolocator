#ifndef GEOLOCATOR_COUNTRY_H
#define GEOLOCATOR_COUNTRY_H

#include <string>
#include <ogr_feature.h>
#include "../lib/json.hpp"

using json = nlohmann::json;
using namespace std;


class Country
{
public:
    string m_name;
    string m_nameLong;
    string m_formalEn;
    string m_wbA2;
    string m_wbA3;
    string m_continent;
    string m_regionUn;
    string m_subregion;
    string m_regionWb;

    Country(OGRFeature *feature);
    json toJson();
    ~Country() {};
};


#endif //GEOLOCATOR_COUNTRY_H
