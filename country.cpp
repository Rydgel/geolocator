#include "country.h"


string Country::toJson() {
    if (set) {
        return "";
    } else {
        return "{\"error\": \"country not found.\"}";
    }
}

