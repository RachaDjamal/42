#!/bin/bash

mv /usr/share/wordpress /var/www/html/
service php7.3-fpm start
service mysql start
service nginx start