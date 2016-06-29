#ifndef GEOLOCATOR_TOOLS_H
#define GEOLOCATOR_TOOLS_H

#include <string>
#include <vector>

using namespace std;


class tools
{
public:
    static string coord_to_point(double latitude, double longitude);

    static vector<string> &split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    static vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }
};


#endif //GEOLOCATOR_TOOLS_H
