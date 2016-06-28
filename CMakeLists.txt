cmake_minimum_required(VERSION 3.5)
project(geolocator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGDAL")

set(SOURCE_FILES main.cpp country.cpp country.h country_shape.cpp country_shape.h tools.cpp tools.h)
add_executable(geolocator ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release)

