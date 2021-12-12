package main

import(
	"fmt"
	"log"
	"io/ioutil"
	"os/exec"
)

func leerModuloCat(){
	fmt.Println("Leer modulo en directorio /proc ejecutando comando CAT desde la terminal\n")
	//Configuracion del comando a ejecutar
	cmd := exec.Command("sh", "-c", "cat /proc/ejemplo_modulo")
	//Ejecutar el comando
	out, err := cmd.CombinedOutput()
	
	if err != nil{
		//Si hubo errores al ejecutar el comando
		log.Fatal(err)
	}
	//Si no hubo errores al ejecutar el comando
	//Convertir a string el resultado de la ejecucion
	output := string(out[:])
	//Mostrar resultado del comando
	fmt.Println(output)
}

func leerModuloIoUtils(){
	fmt.Println("Leer modulo en directorio /proc con libreria io/ioutil\n")
	out, err := ioutil.ReadFile("/proc/ejemplo_modulo")
	if err != nil{
		//Si hubo errores al leer el archivo
		log.Fatal(err)
	}

	//Si no hubo errores al leer el archivo
	//Convertir a string el resultado
	output := string(out[:])
	//Mostrar resultado del comando
	fmt.Println(output)
}


func main(){
	leerModuloCat()
	leerModuloIoUtils()
}