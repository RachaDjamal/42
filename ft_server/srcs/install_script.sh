#!/bin/bash

apt-get -y update && apt-get -y upgrade && apt-get -y install nginx
apt-get -y install mysql-common
apt-get -y install wordpress

