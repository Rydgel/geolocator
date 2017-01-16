#include "WoeData.h"

WoeData::WoeData(OGRFeature *feature)
{
    m_name = feature->GetFieldAsString(0);
    m_region = feature->GetFieldAsString(1);
    m_iso_a2 = feature->GetFieldAsString(2);
    m_objectid_1 = feature->GetFieldAsString(3);
}

string WoeData::toJson()
{
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.Key("name");
    writer.String(m_name.c_str());
    writer.Key("region");
    writer.String(m_region.c_str());
    writer.Key("iso_a2");
    writer.String(m_iso_a2.c_str());
    writer.Key("objectid_1");
    writer.String(m_objectid_1.c_str());
    writer.EndObject();

    return s.GetString();
}
