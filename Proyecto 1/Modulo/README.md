# Modulo


Compilar archivo

```
make all
```

Insertar modulo
```
sudo insmod ejemplo_modulo.ko
```

Verificar mensaje de insersion
```
dmesg
```


Verificar informacion de los procesos en el directorio proc/
```
cd /proc/
```

Para saber todos los procesos que existen deberìa de aparecer en el primer lugar
```
lsmod
```

Obtener los mensajes de entrada y salida del modulo
```
dmesg
```

Obtener el archivo que se debiò escribir
```
cat ejemplo_modulo
```

Para eliminar el modulo 
```
sudo rmmod ejemplo_modulo
```
## License

Bajo licencia GLP.

