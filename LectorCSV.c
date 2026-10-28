#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo{
    char marca[10];
    char modelo[10];
    char estado[10];
    struct nodo *siguiente;
}autos;

void insertar(){}

void eliminar (){}

int  leerArchivo(FILE * archivo){
        char linea[100] = {0};
        char primero[100], segundo[100], tercero[100] = {0};
        archivo = fopen("prueba.csv","r");
        int cont = 0;
        if(archivo == NULL){
        printf("No se pudo abrir el CSV: %s\n", "prueba.csv");    
        exit(EXIT_FAILURE);
    }

    while (/*(fgets(linea, 100, archivo))!= NULL*/ fscanf(archivo, "%s,%s,%s\r\n",primero,segundo,tercero)!=4)
    {
        printf("%s\n", primero);
        printf("%s\n", segundo);
        printf("%s\n", tercero);
        //fgets(primero, 100, );
        if(feof(archivo)){
            printf("Fin del archivo\n");
            fclose(archivo);
        }
        if(cont++ == 7){
            exit(1);
        }

    }
    return EXIT_SUCCESS;
}

void contarLineas(FILE * archivo){
    printf("SALIDA\n");
}

int main (){
    FILE * archivo;
    leerArchivo(archivo);
    contarLineas(archivo);
 return EXIT_SUCCESS;
}