#ifndef GEOLOCATOR_PROTOCOLMESSAGE_H
#define GEOLOCATOR_PROTOCOLMESSAGE_H

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "../lib/optional.hpp"

using namespace rapidjson;
using namespace std::experimental;

struct ProtocolMessage
{
    std::string m_type;
    double m_latitude;
    double m_longitude;
    std::string m_codePays;
    int m_regionCode;
    int m_woeId;

    ProtocolMessage() = default;
    static optional<ProtocolMessage> fromJson(const std::string inputMessage);
    ~ProtocolMessage() = default;
};


#endif //GEOLOCATOR_PROTOCOLMESSAGE_H
