FROM ubuntu:disco

RUN apt-get update && \
  apt-get install -y dieharder gcc libssl-dev

WORKDIR /app
COPY ./ ./

ARG evp=$evp
RUN gcc -Wall -O3 -D_EVP=EVP_$evp -o gen gen.c -lssl -lcrypto
CMD ./gen | dieharder -a -g200
