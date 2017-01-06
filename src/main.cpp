#include <iostream>
#include <sstream>
#include <gdal.h>
#include "country_shape.h"
#include "region_shape.h"
#include "tools.h"
#include "../lib/crow_all.h"

using namespace std;
using namespace std::experimental;


int main(int argc, char **argv)
{
    GDALAllRegister();
    OGRRegisterAll();

    // Load-all shapefiles
    CountryShape cs;
    RegionShape rs;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/country/<double>/<double>")
    ([&cs](const crow::request &req, crow::response &res, double latitude, double longitude) {
        res.set_header("content-type", "application/json");
        if (optional<Country> c = cs.get_country_with_coord(latitude, longitude)) {
            res.code = 200;
            res.write(c.value().to_json());
        } else {
            res.code = 404;
            res.write("{\"error\": \"country not found\"}");
        }
        res.end();
    });

    CROW_ROUTE(app, "/region/<double>/<double>")
    ([&rs](const crow::request &req, crow::response &res, double latitude, double longitude) {
        res.set_header("content-type", "application/json");
        if (optional<Region> r = rs.get_region_with_coord(latitude, longitude)) {
            res.code = 200;
            res.write(r.value().to_json());
        } else {
            res.code = 404;
            res.write("{\"error\": \"region not found\"}");
        }
        res.end();
    });

    app.port(8081).multithreaded().run();

    return EXIT_SUCCESS;
}