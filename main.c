#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algorithms/merguesort.h"
#include "algorithms/ternaria.h"

void prueba_merguesort(int tamPrueba, int ciclos){
    printf("Se va a iniciar la prueba mergue sort , "
        "Para mayor fiabilidad de la prueba se recomienda tener el ordenador en las mejores condiciones de rencimiento posible\n");
    printf("El tamaño de la prueba será de %d elementos \n", tamPrueba);
    // Ejecutar función a medirs
    int *v = (int*)malloc(tamPrueba*sizeof(int)); //Almacenamos memoria suficiente
   // double *tiempos = (float*)malloc(TAM_PRUEBA*sizeof(double));
    for(int i = tamPrueba-1;i >= 0; --i){
        v[tamPrueba-i-1] = i; //Ponemos el vector invertido para estar siempre en el peor de los casos
    }
    double sumTiempos = 0; //Suma total de tiempos
    FILE *fp;
    fp = fopen("datos.csv", "w"); //Crear archivo de datos
    
    for(int i = 0; i < tamPrueba; ++i){ 
        clock_t start = clock();
        for(int j = 0; j < ciclos; ++j){
            mergesort(v,0,i);

        }
            // Finalizar tiempo
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  //      tiempos[i] = time_taken;
        sumTiempos += time_taken;
        fprintf(fp,"%d,%f\n",i, time_taken); //Escribir archivo en formato CSV
    }   
    fprintf(fp,"SUM,%f", sumTiempos);
    fclose(fp);

    // Calcular tiempo de ejecución en segundos

    printf("El tiempo ha sido de %f ", sumTiempos);
}

void prueba_ternaria(int tam, int ciclos){
    printf("Se va a iniciar la prueba de busqueda ternaria\n");
   // int v[] = {1,2,3,45,3245,13451};
    int v[50] = {5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101, 103};
    int pos = ternaria(v,50, 103);
    printf("La posicion es %d\n", pos);

}

int main(int argc , char *argv[]){
    int i = 0;
    int tam = 10000; // Tamaño de la prueb a
    int ciclos = 100; //ciclos que se repite la prueba
    while(i < argc){

        if(strcmp(argv[i], "--help") == 0){ //ayuda
            printf("Este proyecto se ha realizado para probar la complejidad de distintos algoritmos propuestos en la asignatura de \nDesarrollo de algoritmos del grado de ingeniería en ingenería informática de la universidad de Jaen\n");
            printf("Author: Jose Luis Parrilla Fuentes");
            printf("Version: 0.1");
            printf("Usage: algortithm [ --all ] [--mergesort ]");
        }
        if(strcmp(argv[i], "--all") == 0){
            printf("Se van a ejecutar pruebas de todos los algoritmos");
        }
        else if(strcmp(argv[i] ,"--mergesort") == 0){
            if( i< argc-1){
                tam = atoi(argv[++i]);
                if(i < argc-1) ciclos = atoi(argv[++i]);
            }
            prueba_merguesort(tam , ciclos);
        }else if(strcmp(argv[i], "--ternaria") == 0){
            if( i< argc-1){
                tam = atoi(argv[++i]);
                if(i < argc-1) ciclos = atoi(argv[++i]);
            }
            prueba_ternaria(tam , ciclos);
        }

        ++i; //incr iterador
    }
    
    printf("Finiquitado\n");
    //prueba_merguesort(10000,100);
    return  0;
}