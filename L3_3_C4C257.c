#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANO 5
int encontrar_diagonal_larga(int matriz[TAMANO][TAMANO], int n){
    int k; 
    int i;
    int j;
    int maximo_matriz = 0; //variable que tomara el numero de 1s consecutivos
    int maximo1 = 0; //toma el numero de 1s consecutivos en la primera direccion
    int diagonal = 0; //guarda la cantidad 1s consecutivos por diagonal

    //Direccion1
    //De la esquina inferior izquierda a la diagona central
    for(int k = n-1; k>=0; k--){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial i
        for (i = k, j = 0; i < n; j++, i++){ 
            if (matriz[i][j] == 1){ //si el elemento que topa es un 1, aumenta la variable diagonal en +1
                diagonal++;
                if (diagonal > maximo1){ //si la cantidad de 1s encontrada es mayor al maximo actual
                    maximo1 = diagonal; //se cambia el valor del maximo actual por el valor de diagonal
                }
            }
            else{
                diagonal = 0; //si se encuentra algo diferente a 1, se reinicia el contador de 1s consecutivos
            }
        }
    }
    //De la diagonal central a la esquina superior derecha
    for (k = 1; k < n; k++){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial en j
        for ( i = 0, j = k; j<n; j++,i++){
            if (matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo1){
                    maximo1 = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //Direccion 2
    //De la esquina superior derecha a la diagonal central
    diagonal = 0; //se reinicia la variable a 0 paraa usarlo en una neuva direccion
    int maximo2 = 0; //variable que guarda el maximo de 1s consecutivos encontrados en la direccion 2
    for (k = n-1; k >= 0; k--){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial j
        for(i = 0, j = k; j < n; j++, i++){
            if (matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo2){ //si la cantidad de 1s encontrada es mayor al maximo actual, se sustituye el valor de maximo2 por el de diagonal
                    maximo2 = diagonal;
                }
            }
            else{
                diagonal = 0;
            }
        }
    }
    //De la diagonal central a la esquina inferior izquierda
    for ( k = 1; k < n; k++){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial i
        for(i = k, j = 0; i < n; i++, j++){
            if (matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo2){ //verifica si la cantidad de 1s encontrada es mayor al maximo actual
                    maximo2 = diagonal; //si se cumple, cambia el maximo actual por el valor de diagonal
                }
            }
            else{
                diagonal = 0; //si encuentra algo diferente a 1, reinicia el contador 
            }
        }
    }

    
   
    //Direccion3 
    //De la esquina inferior izquierda a la diagonal central
    diagonal = 0;
    int maximo3 = 0;
    for (k = n-1; k >= 0; k--){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial i
        for (i = k, j= n-1; i < n ; i++, j--){
            if (matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo3){ //verifica si la cantidad de 1s encontrada es mayor al maximo actual
                    maximo3 = diagonal; //si se cumple, cambia el maximo actual por el valor de la diagona
                }
            }
            else {
                diagonal = 0; //si se encuentra con algo diferente a 1, reinicia el contador 
            }

        }
    }
    //de la central a la esquina superior izquierda
    for (k = n-2; k>=0; k--){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial j
        for (i = 0, j = k; j >= 0; i++, j--){
            if (matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo3){ //si la cantidad de 1s encontrada es mayor al maximo actual
                    maximo3 = diagonal; //cambia el maximo actual con el valor de la diagonal
                }
            }
            else {
                diagonal = 0; //si se encuentra algo que no es 1, reinicia el contador
            }
        }
    }
    diagonal = 0; //reinicia el contador para empezar otra direccion
    
    //Direccion4
    //De la esquina superior izquierda a la central
    int maximo4 = 0; //variable que guarda la secuencia mayor de 1s consecutivos en esta direccion
    for (k = 0; k < n; k++){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial j
        for (i = 0, j = k; j >= 0; i++, j--){ //recorre la diagonal individual
            if(matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo4){ //verifica si el valor de diagonal es mayor al maximo actual
                    maximo4 = diagonal; //si se cumple, se sustituye el valor de maximo4 por la secuencia mayor actual
                }
            }
            else{
                diagonal = 0; //si no es un 1 el elemento, se reinicia el contador
            }
        }
    }
    //De la central a la esquina inferior derecha
    for (k = 1; k < n; k++){ //la variable k permite el paso entre diagonales mediante el control de la posicion inicial i
        for (i = k, j = n-1; i < n; i++, j--){ //recorre la diagonal individual
            if(matriz[i][j] == 1){
                diagonal++;
                if (diagonal > maximo4){  //verifica si el valor de diagonal es mayor al maximo actual
                    maximo4 = diagonal; //si se cumple, se sustituye el valor de maximo4 por la secuencia mayor actual
                }
            }
            else{
                diagonal = 0; //si el elemento actual de la diagonal no es 1, se reinicia el contador
            }
        }
    }
    
    
    //comparo los valores maximos de cada direccion para encontrar el maximo
    maximo_matriz = maximo1; //le doy el valor de uno de los maximos encontrados para compararlos con el resto
    if (maximo2 > maximo_matriz){
        maximo_matriz = maximo2;
    }
    else if (maximo3 > maximo_matriz){
        maximo_matriz = maximo3;
    }
    else if (maximo4 > maximo_matriz){
        maximo_matriz = maximo4;
    }
    printf("El numero mas grande de 1s consecutivos es:\n");
    return maximo_matriz;
    
}
int main(){ 
   srand(time(NULL)); 
   int matriz1[TAMANO][TAMANO]; //se crea una matriz del tamaño definido
   for (int i = 0; i < TAMANO; i++) { //recorre las filas de la matriz
    for (int j = 0; j < TAMANO; j++) { //recorre las columnas de la matriz
        matriz1[i][j] = rand() % 2;  //llena cada elemento de la matriz con valores de 0 o 1
        printf("%d ", matriz1[i][j]); //imprime la matriz
    }
    printf("\n");
}
   int diagonal_maxima = encontrar_diagonal_larga(matriz1,TAMANO); //se llama la funcion anterior y se pasa como argumento la matriz generada
   printf("%i\n",diagonal_maxima); //imprime el valor de la secuencia mas larga de 1s
   return 0;
}
