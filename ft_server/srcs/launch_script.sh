#!/bin/bash


service nginx start &
service mysql start &
service php7.3-fpm start 

#echo "CREATE DATABASE wordpress;" | mysql -u root
#mysql -u root -e "CREATE DATABASE wordpress;"
#mysql -u root -e "CREATE USER 'user'@'localhost' IDENTIFIED BY 'password';"
#mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'user'@'localhost';"
#mysql -u root -e "FLUSH PRIVILEGES;"

while [ true ]
do
        true = true
done