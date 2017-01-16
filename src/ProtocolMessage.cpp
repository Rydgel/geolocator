#include "ProtocolMessage.h"

optional<ProtocolMessage> ProtocolMessage::fromJson(const std::string inputMessage)
{
    ProtocolMessage prM;

    Document d;
    d.Parse(inputMessage.c_str());

    if (!d.HasMember("type") || d["type"].IsNull()) {
        return nullopt;
    } else {
        prM.m_type = d["type"].GetString();
    }

    if (!d.HasMember("latitude")
        || !d.HasMember("longitude")
        || d["latitude"].IsNull()
        || d["longitude"].IsNull()) {
        return nullopt;
    } else {
        prM.m_latitude = d["latitude"].GetDouble();
        prM.m_longitude =  d["longitude"].GetDouble();
    }

    if (!d.HasMember("code_pays") || d["code_pays"].IsNull()) {
        return nullopt;
    } else {
        prM.m_codePays = std::string(d["code_pays"].GetString());
    }

    if (!d.HasMember("region_code") || d["region_code"].IsNull()) {
        return nullopt;
    } else {
        prM.m_regionCode = d["region_code"].GetInt();
    }

    if (!d.HasMember("woe_id") || d["woe_id"].IsNull()) {
        return nullopt;
    } else {
        prM.m_woeId = d["woe_id"].GetInt();
    }

    return make_optional(prM);
}
