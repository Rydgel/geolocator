#include "Protocol.h"

Protocol::Protocol(CountryShape &cs, RegionShape &rs)
: m_cs(cs)
, m_rs(rs)
{
}

const std::string Protocol::getResponse(const std::string input)
{
    auto protocolMessage = ProtocolMessage::fromJson(input);
    if (protocolMessage) {
        auto jsonObject = protocolMessage.value();
        auto type = jsonObject.m_type.c_str();
        // switch by the type
        if (strcmp(type, "COUNTRYCOORD") == 0) {
            auto latitude = jsonObject.m_latitude;
            auto longitude = jsonObject.m_longitude;
            return getCountryWithCoord(latitude, longitude);
        }

        if (strcmp(type, "REGIONCOORD") == 0) {
            auto latitude = jsonObject.m_latitude;
            auto longitude = jsonObject.m_longitude;
            return getRegionWithCoord(latitude, longitude);
        }

        if (strcmp(type, "COUNTRYNAME") == 0) {
            auto code = jsonObject.m_codePays;
            return generateCountryNameByCode(code.c_str());
        }

        if (strcmp(type, "REGIONNAME") == 0) {
            auto code = jsonObject.m_regionCode;
            return generateRegionNameByCode(code);
        }

        if (strcmp(type, "FROMWOE") == 0) {
            auto woeId = jsonObject.m_woeId;
            return getGeoFromWoeId(woeId);
        }

        // type not found
        return "NOK\n";
    } else {
        return "NOK\n";
    }
}

const std::string Protocol::getCountryWithCoord(double latitude, double longitude)
{
    if (optional<Country> c = m_cs.getCountryWithCoord(latitude, longitude)) {
        return c.value().toJson();
    }

    return "NOK\n";
}

const std::string Protocol::getRegionWithCoord(double latitude, double longitude)
{
    if (optional<Region> r = m_rs.getRegionWithCoord(latitude, longitude)) {
        return r.value().toJson();
    }

    return "NOK\n";
}

const std::string Protocol::generateCountryNameByCode(const char *code)
{
    if (optional<std::string> r = m_rs.generateCountryNameByCode(code)) {
        return r.value();
    }

    return "NOK\n";
}

const std::string Protocol::generateRegionNameByCode(int code)
{
    if (optional<std::string> r = m_rs.generateRegionNameByCode(code)) {
        return r.value();
    }

    return "NOK\n";
}

const std::string Protocol::getGeoFromWoeId(int woeId)
{
    if (optional<WoeData> r = m_rs.getGeoFromWoeId(woeId)) {
        return r.value().toJson();
    }

    return "NOK\n";
}
