#include <sstream>
#include "Tools.h"

using namespace std;

string tools::coordToPoint(double latitude, double longitude)
{
    string latStr = to_string(latitude);
    string longStr = to_string(longitude);

    ostringstream out;
    out << "POINT(" << longStr << " " << latStr << ")";

    return out.str();
}

