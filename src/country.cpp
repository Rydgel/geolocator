#include "country.h"


Country::Country(OGRFeature *feature)
{
    m_name = feature->GetFieldAsString(0);
    m_name_long = feature->GetFieldAsString(1);
    m_formal_en = feature->GetFieldAsString(2);
    m_wb_a2 = feature->GetFieldAsString(3);
    m_wb_a3 = feature->GetFieldAsString(4);
    m_continent = feature->GetFieldAsString(5);
    m_region_un = feature->GetFieldAsString(6);
    m_subregion = feature->GetFieldAsString(7);
    m_region_wb = feature->GetFieldAsString(8);
}

string Country::to_json() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.Key("name");
    writer.String(m_name.c_str());
    writer.Key("name_long");
    writer.String(m_name_long.c_str());
    writer.Key("formal_en");
    writer.String(m_formal_en.c_str());
    writer.Key("wb_a2");
    writer.String(m_wb_a2.c_str());
    writer.Key("wb_a3");
    writer.String(m_wb_a3.c_str());
    writer.Key("continent");
    writer.String(m_continent.c_str());
    writer.Key("region_un");
    writer.String(m_region_un.c_str());
    writer.Key("subregion");
    writer.String(m_subregion.c_str());
    writer.Key("region_wb");
    writer.String(m_region_wb.c_str());
    writer.EndObject();

    return s.GetString();
}

