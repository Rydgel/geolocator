#include <iostream>
#include <sstream>
#include <gdal.h>
#include "country_shape.h"
#include "tools.h"
#include "../lib/crow_all.h"

using namespace std;
using namespace std::experimental;


int main(int argc, char **argv)
{
    GDALAllRegister();
    OGRRegisterAll();

    // Load-all shapefiles
    CountryShape *cs = new CountryShape();

    crow::SimpleApp app;

    CROW_ROUTE(app, "/country/<double>/<double>")
    ([&cs](const crow::request &req, crow::response &res, double latitude, double longitude) {
        res.set_header("content-type", "application/json");
        if (optional<Country> c = cs->get_country_with_coord(latitude, longitude)) {
            res.code = 200;
            res.write(c.value().to_json());
        } else {
            res.code = 404;
            res.write("{\"error\": \"country not found\"}");
        }
        res.end();
    });

    app.port(8080).multithreaded().run();

    // dealloc stuff
    delete cs;

    return EXIT_SUCCESS;
}