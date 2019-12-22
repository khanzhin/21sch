#!/bin/sh


docker rm -f wtodd > /dev/null

docker build . > .for_run_docker

docker run --name wtodd -dit -p 9987:9987/udp -p 30033:30033/tcp -p 10011:10011 $(cat .for_run_docker | grep "Successfully built" | awk '{print$3}')

sleep 7

docker logs wtodd | grep "token" | tail -n 1 | awk '{print$1}' | pbcopy

rm .for_run_docker

echo "\033[4;36mTeamSpeak Server UP\033[0m"
echo "\033[4;36mToken in .for_run_docker\033[0m"
