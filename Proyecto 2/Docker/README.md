# INSTALACION Y CONFIGURACION DE DOCKER
Ref: https://github.com/sergioarmgpl/taller-docker

## Instalar Docker
Comandos para instalar docker
```
sudo apt-get update

sudo apt-get install docker.io
```
Para verificar que la instalacion fue realizada correctamente se puede ejecutar el siguente comando
```
sudo systemctl status docker
```

## Ejecutar comando docker sin permisos de adminstrador(sudo)
Por defecto, el comando 'docker' solo puede ser ejecutado con permisos de adminstrador, si se desea correr este comando sin necesidad de agregar el prefijo 'sudo' siempre se puede relizar lo siguiente.

Se agregara el nombre de usuario el grupo docker
```
sudo usermod -aG docker ${USER}
```

Para aplicar estos cambios se debe correr:
```
su - ${USER}
```

## Crear imagen con un archivo Dockerfile
Ubicarse en el mismo nivel del archivo Dockerfile
```
docker build -t [usuario-dockerhub/][nombre-tag] .
```
Esto creara la imagen y la etiquetara con el tag que se desee, si se desea subir la imagen a dockerhub es necesario agregar el nombre de usuario seguido de la diagonal(/) antes del nombre que se le dara a la imagen.

## Subir imagen al dockerhub
Si al momento de crear la imagen se le agrego el nombre de usuario de dockerhub en el tag solamente es necesario correr el siguiente comando.
```
docker push [usuario-dockerhub/][nombre-tag]
```

## Levantar contendor
Para levantar un contendor de una imagen de docker se debe usar el comando docker run de la siguiente manera:
```
docker run -d --name [nombre-contendor] [imagen]
```
El arg -d sirve para ejecutar el contendor en segundo plano.

## Mapeo de puertos
Para mapear el puerto de un contendor a la maquina host se usa el arg -p:
```
docker run -d -p [puerto-host]:[puerto-contendor] --name [nombre-contendor] [imagen]
```

## Variables de entorno
Para agregar una variable de entorno al contendor se usa el arg -e
```
docker run -d -e [ENV-VAR]:[VALOR] --name [nombre-contendor] [imagen]
```