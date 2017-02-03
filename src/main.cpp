#include <iostream>
#include <sstream>
#include <gdal.h>
#include "Tools.h"
#include <asio.hpp>
#include "SocketServer.h"

using namespace std;
using namespace std::experimental;


int main(int argc, char **argv)
{
    // Init GDAL and OGR
    GDALAllRegister();
    OGRRegisterAll();

    const char *filePath;
    if (argv[1] != nullptr) {
        filePath = argv[1];
    } else {
        filePath = "/tmp/geoloc.sock";
    }

    std::string file(filePath);

    struct file_remover {
        file_remover(std::string f): file_(f) { std::remove(f.c_str()); }
        ~file_remover() { std::remove(file_.c_str()); }
        std::string file_;
    } remover(file);

    {
        file_remover r(file);
        // Create and run the server.
        asio::io_service io_service;
        SocketServer s(io_service, file);
        io_service.run();
    }

    return EXIT_SUCCESS;
}