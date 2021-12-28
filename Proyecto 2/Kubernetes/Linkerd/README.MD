# Linkerd
## Instalar

```
#FROM: https://linkerd.io/2.11/getting-started/

curl -fsL https://run.linkerd.io/install | sh

export PATH=$PATH:$HOME/.linkerd2/bin

linkerd check --pre

linkerd install | kubectl apply -f -
```

## Instalar el Dashboard
```
 linkerd viz install | kubectl apply -f -
```

## Instalar el Ingress Controller
Ver instrucciones en la seccion de Kubernetes

## Injecatar Linkerd en el Ingress controller
```
kubectl -n nginx-ingress get deployment nginx-ingress-ingress-nginx-controller -o yaml | linkerd inject --ingress --skip-inbound-ports 443 --skip-outbound-ports 443 - | kubectl apply -f -

kubectl describe pods nginx-ingress-ingress-nginx-controller-64665dd6bc-dgkj4 -n nginx-ingress | grep "linkerd.io/inject: ingress"
```

## Hacer los Deployments y los Servicios
```
kubectl create -f ns.yaml
kubectl create -f dummy.yaml
kubectl create -f blue.yaml
kubectl create -f green.yaml
kubectl create -f traffic-splitter.yaml
```

## Injectar Linkerd en los Deployments
```
kubectl -n minamespace get deploy -o yaml | linkerd inject - | kubectl apply -f -
```

## Ver el Dashboard
```
linkerd viz dashboard
```