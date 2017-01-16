cmake_minimum_required(VERSION 3.5)
project(geolocator)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(RAPIDJSON_USE_SSE2 ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RAPIDJSON_CXX_FLAGS} -std=c++11 -Wall -O3")

set(SOURCE_FILES src/main.cpp
        lib/optional.hpp
        lib/crow_all.h
        src/Country.cpp src/Country.h
        src/CountryShape.cpp src/CountryShape.h
        src/Tools.cpp src/Tools.h
        src/RegionShape.cpp src/RegionShape.h
        src/Region.cpp src/Region.h
        src/WoeData.cpp src/WoeData.h
        src/SocketServer.cpp src/SocketServer.h
        src/SocketSession.cpp src/SocketSession.h
        src/HandlerAllocator.cpp src/HandlerAllocator.h
        src/Protocol.cpp src/Protocol.h src/ProtocolMessage.cpp src/ProtocolMessage.h)

add_executable(geolocator ${SOURCE_FILES})

find_package(GDAL REQUIRED)
IF (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIR})
    target_link_libraries(geolocator ${GDAL_LIBRARIES})
endif()


find_package(asio REQUIRED)

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}.)

