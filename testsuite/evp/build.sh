#!/bin/bash -ex

[ $# -ne 1 ] && exit 1

id=${1,,}

docker build \
  --build-arg http_proxy=http://nieltansah:39189509@cache.itb.ac.id:8080 \
  --build-arg https_proxy=http://nieltansah:39189509@cache.itb.ac.id:8080 \
  --build-arg evp="$id" \
  -t "dieharder-$id" .
docker run -d --name "dieharder-$id-1" "dieharder-$id"
