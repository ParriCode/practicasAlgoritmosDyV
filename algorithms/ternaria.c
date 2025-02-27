
int n0 = 1000;


/**
 * @brief Busqueda ternaria de un elemento dado un vector ordenado
 * @pre El vector Debe estar ordenado
 * @param v vector ordenado
 * @param a Comienzo del vector
 * @param b Final del vector
 * @param ele elemento a buscar
 * @post posicion del elemento encontrado
 */
int ternaria_rec(int v[], int a, int b, int ele){
    if(a == ele) return a;
  //  if(b< n0){
        
  //  }else{
        int c= (b-a)/3;
        if(ele <= v[c]){
            return ternaria_rec(v,a ,c , ele);
        }else if(ele <= v[2*c]){
            return ternaria_rec(v,c , 2*c , ele); 
        }else if(ele <= v[b]){ //Es posible que se pida un elemento fuera de rango
            return ternaria_rec(v,2*c, b , ele); //tercer segment
        }else{return -1;} // El elemento no se encuentra en el vector
  //  }


}




/**
 * @brief Inicialización del algoritmo de buqueda ternaria 
 * @pre El vector debe estar ordenado
 * @param v Vector 
 * @param tam tamaño del vector
 * @param ele elemento a buscar
 * @return posicion del elemento , -1 si no se encuentra
 */
int ternaria(int v[] , int tam, int ele){
    if(ele > v[0] && ele < v[tam-1]){ //Comprobar que el elemento se cneutnra dentro del rango del vector
        return ternaria_rec(v, 0 , tam, ele); 
    }
    else return -1 ;
}
