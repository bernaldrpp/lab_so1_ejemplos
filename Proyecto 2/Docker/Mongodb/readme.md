Levantar contenedor de mongodb
```
docker run -d -p 27017:27017 --name mongodb mongo
```

Entrar al contenedor de docker y a la base de datos dentro del contenedor
```
sudo docker exec -it mongodb bash
mongo
```

Para levantar contenedor de mongo con contraseña
```
docker run -d -p 27017:27017 -e MONGO_INITDB_ROOT_USERNAME=usr -e MONGO_INITDB_ROOT_PASSWORD=pass --name mongodb mongo
```
Entrar al contenedor de docker y a la base de datos dentro del contenedor
```
sudo docker exec -it mongodb bash
mongo mongodb://usr:pass@localhost:27017
```