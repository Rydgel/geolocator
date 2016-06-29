#include <sstream>
#include "tools.h"

using namespace std;

string tools::coord_to_point(double latitude, double longitude)
{
    string latStr = to_string(latitude);
    string longStr = to_string(longitude);

    ostringstream out;
    out << "POINT(" << longStr << " " << latStr << ")";

    return out.str();
}

