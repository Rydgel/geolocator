#ifndef GEOLOCATOR_SOCKETSERVER_H
#define GEOLOCATOR_SOCKETSERVER_H

#include <functional>
#include <cstdio>
#include <iostream>
#include <asio.hpp>
#include "SocketSession.h"
#include "CountryShape.h"
#include "RegionShape.h"
#include "Protocol.h"


class SocketServer
{
private:
    asio::local::stream_protocol::acceptor acceptor_;
    asio::local::stream_protocol::socket socket_;
    std::atomic<int> currentLimit;
    // gdal things
    CountryShape cs_;
    RegionShape rs_;
    Protocol protocol_;
    void doAccept();
public:
    SocketServer(asio::io_service& io_service, const std::string& file);
};


#endif //GEOLOCATOR_SOCKETSERVER_H
