#!/bin/bash

apt-get -y update && apt-get -y upgrade && apt-get -y install nginx

apt-get -y update && apt-get -y upgrade && apt-get -y install php7.3
apt-get -y update && apt-get -y upgrade && apt-get -y install php7.3-fpm
apt-get -y update && apt-get -y upgrade && apt-get -y install php7.3-mysql
apt-get -y update && apt-get -y upgrade && apt-get -y install mariadb-server
apt-get -y update && apt-get -y upgrade && apt-get -y install wordpress

