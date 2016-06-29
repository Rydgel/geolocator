#include <iostream>
#include <gdal.h>

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>

#include "country_shape.h"
#include "tools.h"

using namespace std;
using namespace std::experimental;


class Server : public cppcms::application
{
private:
    CountryShape *country_shape;
public:
    Server(cppcms::service &srv, CountryShape *cs) : cppcms::application(srv)
    {
        country_shape = cs;

        dispatcher().assign("/country/([-+]?[0-9]*\\.?[0-9]+/[-+]?[0-9]*\\.?[0-9]+)", &Server::country, this, 1);
        mapper().assign("country", "/country/{1}/{2}");
    }
    virtual void country(std::string coord);
};

void Server::country(std::string coord)
{
    vector<string> coordV = tools::split(coord, '/');
    double latitude = atof(coordV.at(0).c_str());
    double longitude = atof(coordV.at(1).c_str());

    optional<Country> c = country_shape->get_country_with_coord(latitude, longitude);

    if (c) {
        response().out()
        << c.value().to_json().dump();
    } else {
        // 404
        response().out()
        << "{\"error\": \"country not found\"}";
    }
}

int main(int argc, char **argv)
{
    GDALAllRegister();
    OGRRegisterAll();

    // Load-all shapefiles
    CountryShape *cs = new CountryShape();

    try {
        cppcms::service srv(argc, argv);
        booster::intrusive_ptr<Server> c = new Server(srv, cs);
        srv.applications_pool().mount(c);
        srv.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    // dealloc stuff
    delete cs;

    return EXIT_SUCCESS;
}