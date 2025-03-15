
/**
 * @file merguesort.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
int n0_mergesort = 5;

#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Ordena un vector de enteros v de tamaño n mediante el algoritmo de inserción
 * @details El algoritmo consiste en recorrer el vector e insertar luego yendo hacia atrás en la posición correcta
 * @param v vector
 * @param n numero de elementos del vector
 * @post v estara ordenado de menor a mayor
 */
void insercion(int v[], int a, int b){
    int j = 0;
    for(int i = a; i < b ; ++i){
        int aux = v[i];
        int j = i -1;
        while(v[j] > aux && j >= a){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = aux;
    }
    printf("Insercion\n");
    printf(" a = %d , b = %d \n", a, b);

    for(int l = a; l < b;++l){
        printf("%d, ", v[l]);
    }
    printf("\n");

}
/**
 * @brief 
 * @pre Vectores ordenados
 * 
 * @param v puntero vector v
 * @param u puntero vector u
 * @param n Longitud de v
 * @param m Longitud de u
 * @post Vector V ordenado
 */
void merge(int v[], int u[], int a, int m , int b){
    int i , j , k ;
  //  int aux = 0x80000000;
    int pila = 0;
    j =  a;
    i = a-1;
    k = m;
    int f;
    int aux = k;
    printf("\n");
    printf(" a = %d , b = %d \n", a, b);
    for(int l = a; l < m;++l){
        printf("%d, ", v[l]);
    }
    printf("\n");
    for(int l = m; l < b;++l){
        printf("%d, ", v[l]);
    }
    printf("\n");

    while (i < b ) {
        ++i;
        printf("j = %d , i = %d , k = %d \n", j, i , k);
        for(int l = a; l < b;++l){
            printf("%d, ", v[l]);
        }
        printf("\n");
        getchar();
        if (v[j] < v[k] ) {
            if(j >= m){
                pila = v[i];
            }
            v[i] = v[j];
            ++j;
            if(j >= m){
                v[k-1] = pila;

            }
            if(j == k){
                aux = j-1;
                --j;
               // j = i+1;
            }
                

           // }
        } else if(k < b){
            pila = v[i];
            v[i] = v[k];
            v[k] = pila;
            if(j < m){
                j = k;

            }
            ++k;
        }

    }
    printf("\nMerge\n");
    for(int l = a; l < b;++l){
        printf("%d, ", v[l]);
    }
    printf("\n");
    printf("\n");

    printf("\n");

    

}
/**
 * @brief Ordenacion por metodo merguesort
 * @details n0 == 10
 * @param v 
 * @param a 
 * @param b 
 */
void mergesort(int v[], int a , int b){

   //  if(a >= b) return;
    if((b-a+1) < 15){
        insercion(v,a, b);
        return ; 
    }
    else{

        int m  = (a+b)/2; //Mitad del vector     if(a >= b) return;

        mergesort(v,a,m); //Desde v con m-n 
        mergesort(v,m,b); //u coge desde principio hasta m
        merge(v,v,a, m, b); //mergue siempre recibe el puntero bien reservado
    }
}