#include "country.h"


Country::Country(OGRFeature *feature)
{
    m_name = feature->GetFieldAsString(0);
    m_nameLong = feature->GetFieldAsString(1);
    m_formalEn = feature->GetFieldAsString(2);
    m_wbA2 = feature->GetFieldAsString(3);
    m_wbA3 = feature->GetFieldAsString(4);
    m_continent = feature->GetFieldAsString(5);
    m_regionUn = feature->GetFieldAsString(6);
    m_subregion = feature->GetFieldAsString(7);
    m_regionWb = feature->GetFieldAsString(8);
}

json Country::toJson() {
    return {
            { "name", m_name },
            { "name_long", m_nameLong },
            { "formal_en", m_formalEn },
            { "wb_a2", m_wbA2 },
            { "wb_a3", m_wbA3 },
            { "continent", m_continent },
            { "region_un", m_regionUn },
            { "subregion", m_subregion },
            { "region_wb", m_regionWb }
    };
}

