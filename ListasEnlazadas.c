#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato; //guardamos el dato, esta caso, un entero
    struct nodo * siguiente; //puntero a otro nodo, siguiente elemento en la lista
}lista;

//lista *i es un puntero a un nodo. *i significa "guarda la direccion de memoria a un nodo"
//Se usan punteros para movernos por la memoria, sino utilizariamos copias y no sirve.
//i->dato accedemos al dato de el nodo que estamos "viendo"

void listar (lista *i){
    if (i != NULL){
        printf("Elemento := %d\n", i->dato);
        listar(i->siguiente);
    }
}

void insertar (int d, lista **i){
    if(* i == NULL){
        printf("Insertando %d en la lista\n", d);
        *i = (lista *)malloc(sizeof(lista));
        (*i)->dato = d;
        (*i)->siguiente == NULL;
    }  
    else{
        if((*i)->dato > d) {//comparacion para insertar al inicio
            printf("Insertando %d en la lista\n", d);
            lista *nuevo = (lista *)malloc(sizeof(lista));
            nuevo->dato = d;
            nuevo->siguiente = *i;
            *i = nuevo;
        }
        else if((*i)->dato < d && (*i)->siguiente != NULL && (*i)->siguiente->dato > d){ //comparar para ver si esta entre 2 nodos
            printf("Insertando %d en la lista\n", d);
            lista* nuevo = (lista *)malloc(sizeof(lista));
            nuevo->dato = d;
            nuevo->siguiente = (*i)->siguiente;
            (*i)->siguiente = nuevo;
        }
        else if((*i)->dato == d){
            printf("Ya existe el elemento %d en la lista\n", d);
        }
        else{
            insertar(d, &(*i)->siguiente);
        }
    }
} 


void eliminar (int d, lista **i){
    if(*i == NULL){
        printf("No existe el elemento a eliminar\n");
    }
    else{
        if((*i)->dato == d){
            printf("Elimino a %d\n", d);
            lista *aux = (*i);
            (*i) = (*i)->siguiente;
            free(aux);
        } 
        else if((*i)->dato < d && (*i)->siguiente != NULL &&(*i)->siguiente->dato == d){
            printf("Elimino a %d\n", d);
            lista* aux= (*i)->siguiente;
            (*i)->siguiente = (*i)->siguiente->siguiente;
            free(aux);
        }
        else{
            eliminar(d, &(*i)->siguiente);
        }
    }
}


int main (){
    lista *inicio;
    inicio = NULL;
    insertar(5, &inicio);
    insertar(15, &inicio);
    insertar(4, &inicio);
    insertar(52, &inicio);
    insertar(6, &inicio);
    insertar(23, &inicio);
    insertar(65, &inicio);
    insertar(101, &inicio);
    insertar(2, &inicio);

    printf("Listo los elemento: \n");
    listar(inicio);
    printf("Fin del listado\n");

    eliminar(5, &inicio);
    eliminar(6, &inicio);
    eliminar(4, &inicio);
    eliminar(2, &inicio);

    printf("Listo los elemento: \n");
    listar(inicio);
    printf("Fin del listado\n");

    return 0;
}