## GCloud SDK
### Instalar
```
[//]: # FROM: https://cloud.google.com/sdk/docs/quickstart#deb
sudo apt-get install apt-transport-https ca-certificates gnupg

echo "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] https://packages.cloud.google.com/apt cloud-sdk main" | sudo tee -a /etc/apt/sources.list.d/google-cloud-sdk.list

curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | sudo apt-key --keyring /usr/share/keyrings/cloud.google.gpg add -

sudo apt-get update && sudo apt-get install google-cloud-sdk
```
### Configurar gcloud sdk
```
gcloud init
```
Configurar el proyecto y la region por defecto
```
#projectID = lab-so-1
gcloud config set project lab-so-1

gcloud config set compute/zone us-central1-a
```
## Instalar Kubectl
```
sudo apt-get install kubectl
```
## Creacion de cluster de kubernetes
```
#Nombre del cluster: k8s-demo
#Numero de nodos(1): --num-nodes=1
#Tipo de VM (2 CPUs, 8GB RAM): --machine-type=n1-standard-2
#Nota: Requerimientos minimos 2 CPUs y 4GB RAM, y 3 nodos
#Networks rules (allin, allout): --tags=allin,allout
#Autenticacion con certificado: --enable-legacy-authorization --issue-client-certificate
#Habilitar el escalado automatico (Minimo de nodos 1 y maximo 3): --enable-autoscaling --min-nodes=1 --max-nodes=3

gcloud container clusters create k8s-demo --num-nodes=1 --tags=allin,allout --enable-legacy-authorization --issue-client-certificate --machine-type=n1-standard-2
```
## Obtener credenciales para Kubectl
```
#Configuracion del cluster y despues en boton Connect
gcloud container clusters get-credentials k8s-demo --zone us-central1-a --project lab-so-1
cat ~/.kube/config
```
Comanodos utiles
```
#Lista de los nodos
kubectl get nodes

#Servicios
kubectl get services <<Name>>
kubectl delete services <<Name>>

#Lista de los pods
kubectl get pods
```

## Ejemplo Pods
```
#Nombre del pod: mipod
#Imagen base (ngnix): --image=nginx
#Para que entienda que es un pod le agregamos el --restart=Never
kubectl run mipod --image=nginx --restart=Never

#Mapear el puerto 80 del contenedor al puerto 8080 local
kubectl port-forward pod/mipod 8080:80
#Acceder a http://127.0.0.1:8080
```

### LoadBalancer
Crea una maquina dedicada para exponer el servicio.
```
kubectl expose pod/mipod --target-port=80 --port=80 --type=LoadBalancer --name=mipod-svc
```
Nota: Los loadbalancer son caros

### NodePort
Exponer el servicio por un puerto del nodo en donde fue levantado el contenedor, en un puerto random de 30000 a 32000 y lo hace publico en todos los nodos del cluster
```
kubectl expose pod/mipod --port=80 --type=NodePort --name=mipod-svc
#Obtener la ip externa del nodo
kubectl get nodes -o wide
```

### Cluster IP
Crea un DNS interno para acceder a un deployment o Pod por nombre
```
```

## Ejemplo Deployments
```
kubectl create deployment app1 --image=nginx
#Aumentar replicas
kubectl scale --replicas=3 deployment/app1
```

### Exponer Deployments
```
kubectl expose deployment app1 --port=80 --target-port=80 --type=ClusterIP
kubectl expose deployment app1 --port=80 --target-port=80 --type=NodePort
kubectl expose deployment app1 --port=80 --target-port=80 --type=LoadBalancer
```

## Archivos de configuracion de Kubernetes
```
kubectl get [nodes|deployments|services|pods] nombre -o yaml > pod.yaml
kubectl create -f archivo.yaml
kubectl delete -f archivo.yaml
kubectl apply -f archivo.yaml
```

## Monitoreo
```
kubectl logs -f pod/name
kubectl logs -f deployment/name
kubectl describe deployments name
```

## HELM
El administrador de paquetes de kubernetes

https://helm.sh/docs/intro/install/

```
#Opcion 1
wget https://get.helm.sh/helm-v3.7.2-linux-amd64.tar.gz
tar -zxvf helm-v3.7.2-linux-arm64.tar.gz
mv linux-amd64/helm /usr/local/bin/helm

#Opcion 2
curl -fsSL -o get_helm.sh https://raw.githubusercontent.com/helm/helm/main/scripts/get-helm-3
chmod 700 get_helm.sh
./get_helm.sh
```
## Ingress Controller NGNIX

### Instalar el Ingress
Agregar el repositorio a HELM
```
helm repo add stable https://charts.helm.sh/stable
kubectl create namespace nginx-ingress
helm repo add ingress-nginx https://kubernetes.github.io/ingress-nginx
helm repo update
helm install nginx-ingress ingress-nginx/ingress-nginx -n nginx-ingress
#Listar
helm list -n nginx-ingress
```

### Configurar el Ingress
```
#Agregar record set con la ip del loadbalancer generado por el ingress
kubectl get all -nnginx-ingress

#Crear un service ClusterIP para el deployoment
kubectl expose deployment app1 --port=80 --target-port=80 --type=ClusterIP

#Crear la regla de ingress
kubectl create -f ingress.yaml
```