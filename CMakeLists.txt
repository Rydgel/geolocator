cmake_minimum_required(VERSION 3.5)
project(geolocator)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(RAPIDJSON_USE_SSE2 ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RAPIDJSON_CXX_FLAGS} -std=c++14 -Wall -O3")

set(SOURCE_FILES src/main.cpp
        lib/optional.hpp
        lib/crow_all.h
        src/country.cpp src/country.h
        src/country_shape.cpp src/country_shape.h
        src/tools.cpp src/tools.h src/region_shape.cpp src/region_shape.h src/region.cpp src/region.h)

add_executable(geolocator ${SOURCE_FILES})

find_package(GDAL REQUIRED)
IF (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIR})
    target_link_libraries (geolocator ${GDAL_LIBRARIES})
endif()

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
find_package(Boost 1.63.0 COMPONENTS date_time filesystem system thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(geolocator ${Boost_LIBRARIES})
endif()

find_package(TcMalloc REQUIRED)
IF (TcMalloc_FOUND)
    include_directories(${TcMalloc_INCLUDE_DIR})
    target_link_libraries (geolocator ${TcMalloc_LIBRARIES})
endif()

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}.)

