#!/bin/bash

docker build -t server_image .
docker run -itd -p 80:80 -p 443:443 --name=server_container server_image:latest
docker exec -it server_container bash