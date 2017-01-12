#include <iostream>
#include <sstream>
#include <gdal.h>
#include "country_shape.h"
#include "region_shape.h"
#include "tools.h"
#include "../lib/crow_all.h"
#include <asio.hpp>

using namespace std;
using namespace std::experimental;
using asio::ip::tcp;


int main(int argc, char **argv)
{
    // asio::io_service io_service;
    // server s(io_service, std::atoi(argv[1]));
    // io_service.run();

    GDALAllRegister();
    OGRRegisterAll();

    // Load-all shapefiles
    CountryShape cs;
    RegionShape rs;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/country/<double>/<double>")
    ([&cs](const crow::request &req, crow::response &res, double latitude, double longitude) {
        res.set_header("content-type", "application/json");
        if (optional<Country> c = cs.getCountryWithCoord(latitude, longitude)) {
            res.code = 200;
            res.write(c.value().toJson());
        } else {
            res.code = 404;
            res.write("{\"error\": \"country not found\"}");
        }
        res.end();
    });

    CROW_ROUTE(app, "/region/<double>/<double>")
    ([&rs](const crow::request &req, crow::response &res, double latitude, double longitude) {
        res.set_header("content-type", "application/json");
        if (optional<Region> r = rs.getRegionWithCoord(latitude, longitude)) {
            res.code = 200;
            res.write(r.value().toJson());
        } else {
            res.code = 404;
            res.write("{\"error\": \"region not found\"}");
        }
        res.end();
    });

    CROW_ROUTE(app, "/country/code/<string>")
    ([&rs](const crow::request &req, crow::response &res, std::string code) {
        res.set_header("content-type", "text/plain");
        if (optional<std::string> r = rs.generateCountryNameByCode(code.c_str())) {
            res.code = 200;
            res.write(r.value());
        } else {
            res.code = 404;
            res.write("{\"error\": \"country name not found\"}");
        }
        res.end();
    });

    CROW_ROUTE(app, "/region/code/<int>")
    ([&rs](const crow::request &req, crow::response &res, int code) {
        res.set_header("content-type", "text/plain");
        if (optional<std::string> r = rs.generateRegionNameByCode(code)) {
            res.code = 200;
            res.write(r.value());
        } else {
            res.code = 404;
            res.write("{\"error\": \"region name not found\"}");
        }
        res.end();
    });

    CROW_ROUTE(app, "/woedata/<int>")
    ([&rs](const crow::request &req, crow::response &res, int woeId) {
        res.set_header("content-type", "application/json");
        if (optional<WoeData> r = rs.getGeoFromWoeId(woeId)) {
            res.code = 200;
            res.write(r.value().toJson());
        } else {
            res.code = 404;
            res.write("{\"error\": \"Woedata not found\"}");
        }
        res.end();
    });

    app.port(8081).multithreaded().run();

    return EXIT_SUCCESS;
}