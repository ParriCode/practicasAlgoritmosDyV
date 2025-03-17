/**
 * @file ejercicio4.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Implementación de un algoritmo que calcula el sumatorio de los elementos de un vector sin tener en cuenta el 
 * máximo ni el mínimo
 * @version 0.1
 * @date 2025-02-26
 * 
 */

#include "ejercicio4.h"

/**
 * @brief Sumar elementos de un vector sin tener en cuenta el mínimo y el máximo
 * @return suma sin máximos ni mínimos
 */
int sumaMM_clasico(int * v, int a, int b){
    int countmin = 0;
    int countmax = 0;
    int min = 0x70000000;
    int max = 0x80000000;
    int sum = 0;
    for(int i = a; i < b; ++i){
        sum += v[i];
        
        if(v[i] == min){++countmin;}
        if(v[i] == max){++countmax;}
        if(v[i] < min){
            countmin = 1; //número de veces que aparece el mínimo
            min = v[i];
        }
        if(v[i] > max){
            countmax = 1; //numero de veces que aparece el máximo
            max = v[i];
        }
        
    }
    return sum - countmax*max - countmin*min;

}
/**
 * 
 */
int sumaMM(int *v, int a , int b){
    if(a>= b){
        return v[a];
    }else{
        int m = (a+b)/2;
        int s1 = 0;
        int s2 = 0;
        s1 = sumaMM(v, a , m);
        s2 = sumaMM(v, m+1 ,b);
        
    }
}