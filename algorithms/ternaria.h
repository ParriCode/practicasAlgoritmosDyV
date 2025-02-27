#ifndef __TERNARIA_H__
#define __TERNARIA_H__




/**
 * @brief Busqueda ternaria de un elemento dado un vector ordenado
 * @pre El vector Debe estar ordenado
 * @param v vector ordenado
 * @param a Comienzo del vector
 * @param b Final del vector
 * @param ele elemento a buscar
 * @post posicion del elemento encontrado
 */
int ternaria_rec(int v[], int a, int b, int ele);

int ternaria(int v[] , int tam, int ele);
#endif
