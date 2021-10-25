#!/bin/bash

set -e

./build-mailio.sh
./build-httplib.sh
./build-json.sh
./build-uuid.sh
./build-gsl.sh
