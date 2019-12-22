FROM debian

RUN apt-get update -y && apt-get upgrade -y && apt-get install gcc -y && apt-get install git -y && apt-get install make -y
WORKDIR fillit/
COPY app/ .
RUN make re
RUN ./fillit tetro
