FROM debian:buster

COPY /srcs/install_script.sh .
COPY /srcs/launch_script.sh .
COPY /srcs/wordpress /var/www/html
COPY /srcs/phpmyadmin /var/www/html

RUN sh install_script.sh
RUN		echo "daemon off;" >> /etc/nginx/nginx.conf

ENTRYPOINT sh launch_script.sh