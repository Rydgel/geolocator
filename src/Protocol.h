#ifndef GEOLOCATOR_PROTOCOL_H
#define GEOLOCATOR_PROTOCOL_H

#include <iostream>
#include "CountryShape.h"
#include "RegionShape.h"
#include "ProtocolMessage.h"

class Protocol
{
private:
    CountryShape &m_cs;
    RegionShape &m_rs;
    // private helpers functions
    const std::string getCountryWithCoord(double latitude, double longitude);
    const std::string getRegionWithCoord(double latitude, double longitude);
    const std::string generateCountryNameByCode(const char *code);
    const std::string generateRegionNameByCode(int code);
    const std::string getGeoFromWoeId(int woeId);
public:
    Protocol(CountryShape &cs, RegionShape &rs);
    const std::string getResponse(const std::string input);
};


#endif //GEOLOCATOR_PROTOCOL_H
