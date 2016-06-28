#include "country.h"

json Country::toJson() {
    if (set) {
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
    } else {
        return { {"error", "country not found."} };
    }
}

