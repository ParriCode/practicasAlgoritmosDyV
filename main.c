#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algorithms/mergesort.h"
#include "algorithms/ternaria.h"
#include "algorithms/moreset.h"
#include "algorithms/ejercicio4.h"
#include "algorithms/ejercicio5.h"

#include "imatriz2d/imatriz2d.h"
extern int n0_ternaria;
extern int n0_mergesort;

/**
 * @brief Prueba de mergesort
 * @param tamPrueba Tamaño de la prueba
 * @param ciclos Número de ciclos
 * @param umbral Umbral
 */

void prueba_merguesort(int tamPrueba, int ciclos, int umbral){
    n0_mergesort = umbral;
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
    char filename[100];
    sprintf(filename, "../datos/mergesort_%d_%d_%d.csv", tamPrueba, ciclos, umbral);
  //  FILE *fp = fopen(filename, "w"); //Crear archivo de datos
    
   // for(int i = 0; i < tamPrueba; ++i){ 
    clock_t start = clock();
       // for(int j = 0; j < ciclos; ++j){
    mergesort(v,0,tamPrueba-1);

       // }
            // Finalizar tiempo
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  //      tiempos[i] = time_taken;
    sumTiempos += time_taken;
       // fprintf(fp,"%d,%f\n",i, time_taken); //Escribir archivo en formato CSV
   // }   
   // fprintf(fp,"SUM,%f", sumTiempos);
   // fclose(fp);

    // Calcular tiempo de ejecución en segundos

    printf("El tiempo ha sido de %f ", sumTiempos);
}


void prueba_ternaria(int tamPrueba, int ciclos, int umbral){
    n0_ternaria = umbral;
    printf("Se va a iniciar la prueba de busqueda ternaria\n");
    printf("El tamaño de la prueba será de %d elementos \n", tamPrueba);
    
    int *v = (int*)malloc(tamPrueba * sizeof(int));
    for(int i = 0; i < tamPrueba; ++i){
        v[i] = i; // Vector ordenado para la búsqueda   
    }
    
    double sumTiempos = 0;
    char filename[100];
  //  sprintf(filename, "../datos/ternaria_%d_%d_%d.csv", tamPrueba, ciclos, umbral);
   // FILE *fp = fopen(filename, "w"); // Crear archivo de datos
    
   // for(int i = 0; i < tamPrueba; ++i){
    clock_t start = clock();
    //    for(int j = 0; j < ciclos; ++j){
    ternaria(v, tamPrueba,tamPrueba/3 +3);
     //   }
        clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    sumTiempos += time_taken;
   // fprintf(fp, "%d,%f\n", i, time_taken); // Escribir archivo en formato CSV
   // }
  //  fprintf(fp, "SUM,%f", sumTiempos);
   // fclose(fp);
    
    printf("El tiempo ha sido de %f ", sumTiempos);
}

void prueba_moreset(int tamPrueba){
    printf("Se va a iniciar la prueba de moreset\n");
    printf("Este algoritmo encuentra el elemento mayoritario el cual es estrictamente mayor que n/2\n");
    printf("El tamaño de la prueba será de %d elementos \n", tamPrueba);
    
    unsigned int v[19] = {3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1};
    
    tamPrueba = 19;
    double sumTiempos = 0;
    char filename[100];
   // sprintf(filename, "../datos/moreset_%d_%d_%d.csv", tamPrueba, ciclos, umbral);
    //FILE *fp = fopen(filename, "w"); // Crear archivo de datos
    //FILE *fp = fopen(filename, "w"); // Crear archivo de datos
    //FILE *fp = fopen(filename, "w"); // Crear archivo de datos
    
   // for(int i = 0; i < tamPrueba; ++i){
        clock_t start = clock();
   //     for(int j = 0; j < ciclos; ++j){
        int elemento = moreset(v, 0,tamPrueba);
        printf("Elemento buscado: %d\n", elemento);
     //   }
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        sumTiempos += time_taken;
        
        //fprintf(fp, "%d,%f\n", i, time_taken); // Escribir archivo en formato CSV
    
   // fprintf(fp, "SUM,%f", sumTiempos);
   // fclose(fp);
    
   // printf("El tiempo ha sido de %f ", sumTiempos);
}
void prueba_sumaMM(){
    printf("Se va a iniciar la prueba de la suma de elementos de un vector menos máximo y mínimo");
    int v[8] =  {1,1,4,5,9,34,34,30};
    int suma = sumaMM_clasico(v,0,8);
    printf("El resultado de la suma es %d\n", suma);

}
/**
 * 
 */
void prueba_matrizCEEV(){
    printf("Se va a iniciar la prueba para contar los elementos de la matriz que está entre los valores dados");
    imatriz2d m = icreamatriz2d(4,4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = i * 4 + j; // Por ejemplo, llenar la matriz con valores secuenciales
        }
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ",m[i][j]); // Por ejemplo, llenar la matriz con valores secuenciales
        }
        printf("\n");
    }
    //printf("v = %d\n", &m);
    printf("\n");
    int s = suma_matriz_nxn_entre_valores(m, 4,0, 3,6);
    printf("s = %d\n" ,  s);
    ifreematriz2d(&m);
    
}
int main(int argc , char *argv[]){
    int i = 0;
    int tam = 10000; // Tamaño de la prueb a
    int ciclos = 100; //ciclos que se repite la prueba
    int umbral = 100000; // Umbral por defecto
    while(i < argc){

        if(strcmp(argv[i], "--help") == 0){ //ayuda
            printf("Este proyecto se ha realizado para probar la complejidad de distintos algoritmos propuestos en la asignatura de \nDesarrollo de algoritmos del grado de ingeniería en ingenería informática de la universidad de Jaen\n");
            printf("Author: Jose Luis Parrilla Fuentes");
            printf("Version: 0.1");
            printf("Usage: algortithm [ --all ] [--mergesort ]");
        }
        if(strcmp(argv[i], "--all") == 0){
            printf("Se van a ejecutar pruebas de todos los algoritmos");
        }else if(strcmp(argv[i],"-e")  == 0 ){
            if(i < argc -1){
                int ejercicio = atoi(argv[++i]);
                printf("ejercicio = %d\n", ejercicio);
                switch (ejercicio)
                {
                case 0:
                    /* code */
                    break;
                case 1:
                    prueba_merguesort(0,0,0);
                    break;
                case 2:
                    prueba_ternaria(0,0,0);
                    break;
                case 3:
                    prueba_moreset(0);
                    break;
                case 4:
                    printf("SUMA\n");
                    prueba_sumaMM();
                    break;
                case 5:
                    prueba_matrizCEEV();
                    break;

                default:
                    printf("ESTO NO FUFA");
                    break;
                }
            }
        }
        else if(strcmp(argv[i] ,"--mergesort") == 0){
            if( i< argc-1){
                tam = atoi(argv[++i]);
                if(i < argc-1) ciclos = atoi(argv[++i]);
                if(i < argc-1) umbral = atoi(argv[++i]);
            }
            prueba_merguesort(tam , ciclos, umbral);
        }else if(strcmp(argv[i], "--ternaria") == 0){
            if( i< argc-1){
                tam = atoi(argv[++i]);
                if(i < argc-1) ciclos = atoi(argv[++i]);
                if(i < argc-1) umbral = atoi(argv[++i]);
            }
            prueba_ternaria(tam , ciclos, umbral);
        }else if(strcmp(argv[i], "--moreset") == 0){
            if( i< argc-1){
                tam = atoi(argv[++i]);
            }
            prueba_moreset(tam);
        }else if(strcmp(argv[i], "--sumaMM") == 0){
            if(i < argc -1){
                tam = atoi(argv[++i]);
            }
            prueba_sumaMM();
        }else if(strcmp(argv[i], "--matrizEV") == 0){
            if(i < argc -1){
                tam = atoi(argv[++i]);
            }
        }

        ++i; //incr iterador
    }
    
    printf("Finiquitado\n");
    //prueba_merguesort(10000,100);
    return  0;
}