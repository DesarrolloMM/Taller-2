#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo{
    char nombre[10];
    struct nodo * siguiente;
}lista;


void inserta(char nombre[] , lista **l){

    for (int i = 0; nombre[i] != '\0'; i++)
    {
        nombre[i] = tolower(nombre[i]);
    }

    if(*l == NULL){
        *l = (lista *)malloc(sizeof(lista));
        strcpy((*l)->nombre, nombre);
        (*l)->siguiente = NULL;
    }
    else{
            if ( strcmp((*l)->nombre, nombre) == 0){
                printf("El nombre %s ya existe en la lista\n", nombre);
            }
            else{
                lista *nuevo = (lista *)malloc(sizeof(lista));
                strcpy(nuevo->nombre, nombre);
                nuevo->siguiente = *l;
                *l = nuevo;
            }
    }
};

void suprime(){};

void miembro (){};

void mostrar (lista *l){
    if (l != NULL)
    {
        printf("%s\n",l->nombre);
        mostrar(l->siguiente);
    }
};

int main (){
    lista * chicos_buenos = NULL;
    lista * chicos_malos = NULL;    
    char nombre[10] = "MARCOS";
    char nombre2[10] = "MarCoS";
    char nombre3[10] = "Carlos";
    char nombre4[10] = "Javier";

    char nombre5[10] = "Azul";
    char nombre6[10] = "Catorce";
    char nombre7[10] = "Brian";
    
    

    inserta(nombre,&chicos_buenos);
    inserta(nombre2,&chicos_buenos);
    inserta(nombre3,&chicos_buenos);
    inserta(nombre4,&chicos_buenos);
    inserta(nombre4,&chicos_buenos);

    inserta(nombre5,&chicos_malos);
    inserta(nombre6,&chicos_malos);
    inserta(nombre7,&chicos_malos);
    inserta(nombre7,&chicos_malos);


    printf("Chisos Buenoos: \n");
    mostrar(chicos_buenos);
    printf("Chicos Malos:\n");
    mostrar(chicos_malos);

    return 0;
}