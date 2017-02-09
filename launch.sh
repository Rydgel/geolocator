#!/usr/bin/env bash

if [ "$1" != "" ]; then
    SOCK_NAME="$1"
else
    SOCK_NAME="geoloc.sock"
fi

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

cd ${DIR}

GDAL_DATA=share ${DIR}/geolocator /tmp/${SOCK_NAME}