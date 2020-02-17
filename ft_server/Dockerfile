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
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz

#copying all stuff in var/www/html
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN rm -rf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ /var/www/html/phpmyadmin
RUN mv /usr/share/wordpress /var/www/html/

#Copying the launching script
COPY srcs/launch_script.sh .

#setup nginx daemon off
RUN	echo "daemon off;" >> /etc/nginx/nginx.conf

#running up all services
CMD sh launch_script.sh