FROM debian


RUN apt-get update -y && apt-get upgrade -y && apt-get install wget -y && \
		wget https://files.teamspeak-services.com/releases/server/3.10.2/teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
		apt-get install tar && \
		apt-get install bzip2 && \
		tar xvf teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
		rm teamspeak3-server_linux_amd64-3.10.2.tar.bz2

ENV		TS3SERVER_LICENSE=accept


CMD		sh teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh >> token
