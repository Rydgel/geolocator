cmake_minimum_required(VERSION 3.5)
project(geolocator)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(RAPIDJSON_USE_SSE2 ON)

find_package(rapidjson REQUIRED)
include_directories("${RAPIDJSON_INCLUDE_DIRS}")

find_package(TcMalloc REQUIRED)
IF (TcMalloc_FOUND)
    include_directories(${TcMalloc_INCLUDE_DIR})
    target_link_libraries (geolocator ${TcMalloc_LIBRARIES})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RAPIDJSON_CXX_FLAGS} -std=c++14 -Wall -O3")

set(SOURCE_FILES src/main.cpp lib/optional.hpp lib/crow_all.h src/country.cpp src/country.h src/country_shape.cpp src/country_shape.h src/tools.cpp src/tools.h)

add_executable(geolocator ${SOURCE_FILES})

find_package(GDAL REQUIRED)
IF (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIR})
    target_link_libraries (geolocator ${GDAL_LIBRARIES})
endif()

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.60.0 COMPONENTS date_time filesystem system thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(geolocator ${Boost_LIBRARIES})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release)

