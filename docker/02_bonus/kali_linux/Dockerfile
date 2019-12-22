FROM kalilinux/kali-linux-docker
RUN apt-get -y update \
    && apt-get -y upgrade \
    && apt-get clean


RUN apt-get install python git -y \
		&& git clone https://github.com/LionSec/katoolin.git \
		&& cp katoolin/katoolin.py /usr/bin/katoolin \
		&& chmod +x /usr/bin/katoolin
