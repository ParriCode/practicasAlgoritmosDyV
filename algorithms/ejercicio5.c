/**
 * @file ejercicio5.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Implementación de un algoritmo que calcula el sumatorio de los elementos de un vector sin tener en cuenta el 
 * máximo ni el mínimo
 * @version 0.1
 * @date 2025-02-26
 * 
 */


 #include "ejercicio5.h"
#include <stdio.h>

/**
 * 
 */
int suma_matriz_nxn_entre_valores_clasico(imatriz2d v,int n,  int a, int b){
    int contador = 0;
    for(int i = 0; i < n;++i ){
        for(int j = 0; j< n;++j){
            if(v[i][j] >= a ||  v[i][j] <= b){
                --contador;
            }
        }
    }
    return contador;
}


int i = 0;
/**
 * @brief Sumar los elementos de una matriz entre2 valores
 * @param n tamaño de la matriz
 * @param m , primer elemento de la columna
 * @param a , primer valor
 * @param b segundo valor
 * 
 */
int suma_matriz_nxn_entre_valores(imatriz2d v, int n,int m,  int a, int b){
    if(n <= 1){
      //  printf("i = %d, n = %d , m = %d, v= %d\n", i , n, m,v);
        if(v[0][m] <= b && v[0][m] >= a){
            return 1;
        }else{return 0;}
    }else{    
        int s = 0;
        s+= suma_matriz_nxn_entre_valores(v       ,n/2 , m, a , b );
        s+= suma_matriz_nxn_entre_valores(v       ,n/2 , m+ n/2, a , b);
        s+= suma_matriz_nxn_entre_valores(v+n/2   ,n/2 , m, a , b );
        s+= suma_matriz_nxn_entre_valores(v+n/2   ,n/2 ,m+n/2, a, b);
    
        return s;
    }
}