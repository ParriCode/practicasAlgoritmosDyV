/**
 * @file ejercicio7.h
 * @brief Dado un Arbol binario , determinar si es un heap
 * @version 0.1
 * @date 2025-03-20
 */

 #ifndef __EJERCICIO7_H__
 #define __EJERCICIO7_H__
 #include <stdbool.h>
 /**
  * @brief Determinar si un arbol binario es un heap o no
  * 
  * @param v Vector que comprobar
  * @param a Índice inicial del rango a considerar.
  * @param b Índice final 
  * @return true si es un heap , false sino
  */
bool esHeap(int *v, int a , int b);
 
 #endif // __EJERCICIO6_H__