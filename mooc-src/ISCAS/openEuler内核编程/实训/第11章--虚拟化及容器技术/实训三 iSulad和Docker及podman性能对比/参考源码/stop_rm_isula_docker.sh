docker stop $(docker ps -q)
isula stop $(isula ps -q)
docker rm $(docker ps -a -q)
isula rm $(isula ps -a -q)
