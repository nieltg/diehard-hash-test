FROM ubuntu:disco

RUN apt-get update && \
  apt-get install -y dieharder gcc

WORKDIR /app
COPY ./ ./

RUN gcc -O3 -o gen gen.c
CMD ./gen | dieharder -a -g200
