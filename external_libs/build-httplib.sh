#!/bin/bash

set -e

DEST_DIR=$SDK_INC/httplib
mkdir -p $DEST_DIR

cp -v cpp-httplib/httplib.h $DEST_DIR
