cmake_minimum_required(VERSION 3.5)
project(geolocator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror -O3")

set(SOURCE_FILES src/main.cpp lib/json.hpp src/country.cpp src/country.h src/country_shape.cpp src/country_shape.h src/tools.cpp src/tools.h)

add_executable(geolocator ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(GDAL)
IF (GDAL_FOUND)
    include_directories(${GDAL_INCLUDE_DIR})
    target_link_libraries (geolocator ${GDAL_LIBRARIES})
endif()

find_package(CPPCMS)
IF (CPPCMS_FOUND)
    include_directories(${CPPCMS_INCLUDE_DIR})
    target_link_libraries (geolocator ${CPPCMS_LIBRARIES})
    target_link_libraries (geolocator ${BOOSTER_LIBRARIES})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release)

