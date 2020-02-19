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
RUN apt-get -y install php7.3-mysql
RUN apt-get -y install mariadb-server
RUN apt-get -y install wordpress
RUN apt-get -y install vim
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz

#copying all stuff in var/www/html
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN rm -rf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ /var/www/html/phpmyadmin
RUN cp -r /var/www/html/phpmyadmin /usr/share
RUN mv /usr/share/wordpress /var/www/html/

RUN mkdir -p /var/lib/phpmyadmin/tmp
RUN chown -R www-data:www-data /var/lib/phpmyadmin

#Copying the phpmyadmin/nginx/wordpress/index config
COPY srcs/default /etc/nginx/sites-available/
COPY srcs/default /etc/nginx/sites-enabled/
COPY srcs/config.inc.php var/www/html/phpmyadmin/
COPY srcs/config.inc.php usr/share/phpmyadmin/
COPY srcs/wp-config.php var/www/html/wordpress/

RUN chown -R www-data:www-data var/www/html

#Copying the launching script
COPY srcs/launch_script.sh .

#Deleting useless stuff from /html
RUN rm -rf /var/www/html/index.html
COPY srcs/index.html /var/www/html/
COPY srcs/smallet /var/www/html/smallet

#setup nginx daemon off
RUN	echo "daemon off;" >> /etc/nginx/nginx.conf

#Setup mysql database
RUN service mysql start && \
		echo "CREATE DATABASE wordpress;" | mysql -u root && \
		echo "CREATE USER 'user'@'localhost' IDENTIFIED BY 'password';"  | mysql -u root && \
        echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'user'@'localhost';" | mysql -u root && \
        #echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'user'@'localhost';" | mysql -u root && \
        echo "FLUSH PRIVILEGES;" | mysql -u root

#running up all services
CMD sh launch_script.sh