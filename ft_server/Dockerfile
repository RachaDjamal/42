#install the OS
FROM debian:buster

#get all necesary tools
RUN apt-get -y update
RUN apt-get -y upgrade 
RUN apt-get -y install wget
RUN apt-get -y install curl
RUN apt-get -y install nginx
RUN apt-get -y install php7.3
RUN apt-get -y install php7.3-fpm
RUN apt-get -y install php-mysql
RUN apt-get -y install php7.3-mbstring
RUN apt-get -y install default-mysql-server
RUN apt-get -y install wordpress
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-all-languages.tar.gz

#create default communication port
EXPOSE 80

#copying all stuff in var/www/html
RUN tar xvf phpMyAdmin-4.9.4-all-languages.tar.gz
RUN rm -rf phpMyAdmin-4.9.4-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.4-all-languages/ /var/www/html/phpmyadmin
RUN cp -r /var/www/html/phpmyadmin /usr/share
RUN mv /usr/share/wordpress /var/www/html/

#Creating phpmyadmin tmp directory
RUN mkdir -p /var/lib/phpmyadmin/tmp
RUN chown -R www-data:www-data /var/lib/phpmyadmin

#Copying the phpmyadmin/nginx/wordpress/index config
COPY srcs/default /etc/nginx/sites-available/
COPY srcs/default /etc/nginx/sites-enabled/
COPY srcs/config.inc.php var/www/html/phpmyadmin/
COPY srcs/config.inc.php usr/share/phpmyadmin/
COPY srcs/wp-config.php var/www/html/wordpress/

#Copying the launching script
COPY srcs/launch_script.sh .

#Deleting useless stuff from /html and adding mine
RUN rm -rf /var/www/html/index.nginx-debian.html
COPY srcs/index.html /var/www/html/
COPY srcs/smallet /var/www/html/smallet
RUN chown -R www-data:www-data var/www/html
RUN chown -R www-data:www-data usr/share

#setup nginx daemon off
RUN	echo "daemon off;" >> /etc/nginx/nginx.conf

#Setup SSL connections
COPY srcs/nginx-selfsigned.crt etc/ssl/certs/
COPY srcs/nginx-selfsigned.key etc/ssl/private/

#Setup mysql database
RUN service mysql start && \
        echo "CREATE DATABASE phpmyadmin;" | mysql -u root && \
		echo "CREATE USER 'pma_user'@'localhost' IDENTIFIED BY 'pma_password';"  | mysql -u root && \
        echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'pma_user'@'localhost';" | mysql -u root && \
        echo "FLUSH PRIVILEGES;" | mysql -u root && \
		echo "CREATE DATABASE wordpress;" | mysql -u root && \
		echo "CREATE USER 'user'@'localhost' IDENTIFIED BY 'password';"  | mysql -u root && \
        echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'user'@'localhost';" | mysql -u root && \
        echo "FLUSH PRIVILEGES;" | mysql -u root

#running up all services
CMD sh launch_script.sh