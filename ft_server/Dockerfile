FROM debian:buster

COPY /srcs/install_script.sh .
COPY /srcs/launch_script.sh .

RUN sh install_script.sh
RUN		echo "daemon off;" >> /etc/nginx/nginx.conf

CMD sh launch_script.sh