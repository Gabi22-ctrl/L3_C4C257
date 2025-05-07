#include <stdio.h>
int main(){
    int n = 5; //numero de columnas y filas
    
    int matriz[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}; //matriz

    //Imprimir la matriz
    printf("\nLa matriz es:\n");
    for(int i = 0; i < n; i++) { //Recorre las filas
        for(int j = 0; j < n; j++) { //Recorre las columnas
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
        
    }

    //Direccion1
    //De la esquina inferior izquierda a la diagonal central
    printf("Dirección 1:\n");
    int contador = 2; //contador en la primera posicion de abajo, controla el paso entre diagonales y la posición i
    printf("Diagonal 1: %i\n", matriz [n-1][0]); //imprime el primer numero dela esquina inferior izquierda
    while (contador < n){ 
        int suma = 0;
        for ( int i = n-contador, j = 0; i < n; i++, j++){
            suma += matriz[i][j];
            if (i == n-1){ //en la ultima iteración, se imprime la suma de cada diagonal
                printf("Diagonal %i: %i\n",contador, suma); //la variable contador tambien indentifica el numero de la diagonal
            }

        }
        contador++; //se aumenta el contador cada iteracion
    }
    //Diagonal centrañ
    int diagonal_principal = 0;
    for ( int i = 0, j = 0; i < n; i++, j ++){ 
        diagonal_principal += matriz[i][j];
    }
    printf("Diagonal %i: %i\n", contador,diagonal_principal);
    contador++; //se aumenta el contador para seguir enumerando cada diagonal

    //De la diagonal central a la esquina superior derecha
    int contador1 = 1; //contador que permite el paso entre diagonales y controla la posicion inicial en j
    while (contador1 <= n-2){
        int suma = 0;
        for (int i = 0, j = contador1; j < n; j++, i++){
            suma += matriz[i][j];
            if (j == n-1){ //en la ultima iteracion, imprime la suma de cada diagonal
                printf("Diagonal %i: %i\n",contador,suma);
            }
        }
        contador1++;
        contador++;
    }
    
    printf("DiagonaL %i: %i\n",contador,matriz[0][n-1]);


    //Direccion 2:
    //De la esquina superior izquierda a la diagonal central
    printf("Dirección 2:\n");
    for (int i = 0; i < n; i++) { //la variable i permite el paso entre diagonales, incluyendo la central
        int suma = 0;
        for (int j = 0; j <= i; j++) { //la variable j da la posicion en i
            suma += matriz[j][i - j];
        }
        printf("Diagonal %i: %d\n",i+1,suma);
    }
    
    //De la diagonal central a la esquina inferior derecha
    int contador2 = 1; //permite el paso entre diagonales y controla la posicion inicial en j
    while(contador2 < n){
        int suma = 0;
        for (int i = n-1, j = contador2; j<n; i--, j++){ 
            suma += matriz[i][j];
            if ( j == n-1){ //en la ultima iteracion, se imprime la suma de los elementos de la diagonal
                printf("Diagonal %i: %i\n",contador2+n,suma);
            }
        }
        contador2++;

    }

    return 0;
}
    
    