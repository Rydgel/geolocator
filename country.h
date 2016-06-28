#ifndef GEOLOCATOR_COUNTRY_H
#define GEOLOCATOR_COUNTRY_H

#include <string>

using namespace std;


class Country
{
public:
    bool set = false;
    string m_name;
    string m_nameLong;
    string m_formalEn;
    string m_wbA2;
    string m_wbA3;
    string m_continent;
    string m_regionUn;
    string m_subregion;
    string m_regionWb;

    Country() {};
    string toJson();
    ~Country() {};
};


#endif //GEOLOCATOR_COUNTRY_H
