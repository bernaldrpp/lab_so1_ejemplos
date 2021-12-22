Levantar un contenedor con redis:alpine
```
docker run -d -p 6379:6379 --name redis redis:alpine redis-server
```

Entrar al contenedor de docker y a redis por medio de redis-cli
```
sudo docker exec -it redis sh
redis-cli
```

Borrar instancia de redis sin password
```
docker stop redis
docker rm redis
```

Archivo de configuracion: 
```
mkdir redis
touch redis.conf
nano redis.conf
```
Contenido del archivo redis.conf
```
bind 0.0.0.0
requirepass labso1vac2021
```
Buscar la ip de un contenedor
```
docker inspect -f '{{.NetworkSettings.IPAddress}}' [nombre-contenedor]
```

Para levantar contenedor de redis en mv
```
sudo docker run -d -p 6379:6379 -v ~/redis:/usr/local/etc/redis --name redis redis:alpine redis-server /usr/local/etc/redis/redis.conf
```

Entrar al contenedor de redis y a redis
```
sudo docker exec -it redis sh
redis-cli -h 127.0.0.1 -p 6379 -a labso1vac2021
```