#include <stdio.h>
int convertir_a_binario(int numero_decimal) {
    int binario = 0;      
    int posicion = 1; //esta variable se usa para escribir el digito del binario en la posicion correcta    
    int valor = 0;          
    //Mientras el número no sea 0, seguimos dividiendo entre 2
    while (numero_decimal) {
        
        valor = numero_decimal % 2; //toma el valor del digito que va a conformar el binario
        
        //Agrega el digito al numero binario en la posicion correcta
        binario = binario + (valor * posicion);
        
        //Cambia la posicion para el siguiente digito
        posicion = posicion * 10;
        
        //Divide el número entre 2 para procesar el siguiente digito
        numero_decimal = numero_decimal / 2;
    }

    //Devuelve el número binario resultante
    printf("%i",binario);
    return binario;
}

int main(){
    int verdadero = 1;
    int numero_positivo;
    while(verdadero == 1){ //pide el numero hasta que el usuario digite uno positivo 
        printf("Escriba un numero positivo.\n");
        scanf("%i", &numero_positivo);
        if (numero_positivo > 0){
            verdadero = 0;
        }
        else if (numero_positivo < 0){
            printf("El numero debe ser positivo.\n");
        }
    }
    printf("El numero %i en binario es:\n", numero_positivo);
    convertir_a_binario(numero_positivo); //se llama la funcion anterior y se pasa como argumento el numero anterior
    printf("\n");

}
