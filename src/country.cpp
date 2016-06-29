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

json Country::to_json() {
    return {
            { "name", m_name },
            { "name_long", m_name_long },
            { "formal_en", m_formal_en },
            { "wb_a2", m_wb_a2 },
            { "wb_a3", m_wb_a3 },
            { "continent", m_continent },
            { "region_un", m_region_un },
            { "subregion", m_subregion },
            { "region_wb", m_region_wb }
    };
}

