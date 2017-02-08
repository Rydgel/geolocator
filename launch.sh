#!/usr/bin/env bash

SOCK_NAME="geoloc.sock"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd ${DIR}

GDAL_DATA=share ${DIR}/geolocator /tmp/${SOCK_NAME}