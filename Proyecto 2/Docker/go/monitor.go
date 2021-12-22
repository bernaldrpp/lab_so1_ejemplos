package main

import (
	"fmt"
	"log"
	"net/http"
)

func endPointPrueba(w http.ResponseWriter, r *http.Request){
  fmt.Fprintf(w, "Hola desde Golang en Docker")
}

func main() {

	go fmt.Println("Server Running on port: 8080")
	http.HandleFunc("/", endPointPrueba)

	err:= http.ListenAndServe(":8080", nil)
	if err != nil{
		log.Fatal(err)
	}
}
