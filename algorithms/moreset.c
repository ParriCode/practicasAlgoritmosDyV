#include "moreset.h"


/**
 * @brief Encontrar el elemento mayoritario de un conjunto 
 * @details El elemento mayoritario es el elemento que aparaece un número de veces estrictamente mayor que n/2 
 * @param arr vector del vector
 * @param a posicion inicial
 * @param b posicion final +1
 * @return elemento mayoritario del vector, -1 sino existe
 */
int moreset(unsigned int *arr, int a , int b){
    int el = moreset_recur( arr, a ,  b);
    int c = 0;
    if(el == -1){return -1;}
    for(int i = a; i <  b; ++i){
        if(arr[i] == el){++c;}
    }
    if(c > (b-a)/2){
        return el;
    }else{
        return -1;
    }
}

int moreset_recur(unsigned int *arr, int a , int b){
    if(b-a == 1){
    //    printf("%d arr: %u\n",c, arr[a]);
     //   ++c;
        return arr[a];
    }
    if(b-a < 1){return -1;}
    int m = (a+b) / 2;
    int ele1 = moreset(arr, a, m);
    int ele2 = moreset(arr,m, b );
    int contador1 = 0;
    int contador2 = 0;
    
    if(ele1 == ele2) {return ele1;}
    if(ele1 == -1){return ele2;}
    else if(ele2 == -1){return ele1;} 
    for(int i = a; i < b;++i){
        if(arr[i] == ele1){
            ++contador1;
       //     if(contador1/2 > (b-a)/ 2){return contador1;} //Si ya es mayoritario devolver directamente
        }else if( arr [i] == ele2){
            ++contador2;
   //         if(contador2 / 2 > (b-a)/2){return contador2;} //Si ya es mayoritario devolverlo directament
        }
    }
    if(contador1 > contador2){return ele1;}
    else{return ele2;}

}
