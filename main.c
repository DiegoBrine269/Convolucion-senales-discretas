#include <stdio.h>
#include <stdlib.h>

int origenX = 0;
int origenH = 1;

void reflejar (int h[], size_t tamano) {
    int aux = 0;

    printf("Longitud de h: %d\n", tamano);

    for(int i=0; i<=tamano/2; i++) {
        tamano--;
        aux = h[i];
        h[i] = h[tamano]; 
        h[tamano] = aux;
    }

    origenH = -origenH;
}

/**/

void desplazar(int n) {                 
    //Desplazar a la derecha
    if(n = 1){
        origenH--;
    }
    //Desplazar a la izquierda
    else if(n == -1){
        origenH++;
    }
}


int* multiplicar (int h[], size_t tamanoH, int x[], size_t tamanoX) {

    //Se define el tamaño máximo
    int max = tamanoH > tamanoX ? tamanoH : tamanoX;

    //Arreglo nuevo
    int* producto = (int*)malloc(sizeof(int) * max);

    for(int i=0; i<max; i++) {
        if(i>=tamanoH || i>=tamanoX)
            producto[i] = 0;
        else
            producto[i] = h[i] * x[i];
    }


    for(int i=0; i<max; i++){
        printf("%d, ", producto[i]);
    }

    return producto;
}


int main () {

    int x [] = {1, 2, 3, 1};
    int h [] = {1, 2, 3, 4, 5, 6, 7};

    printf("Longitud de h: %d\n", sizeof(h)/sizeof(h[0]));

    for(int i=0; i<sizeof(h)/sizeof(h[0]); i++){
        printf("%d, ", h[i]);
    }

    printf("\n");
    printf("\n");
    printf("\n");

    reflejar(h, sizeof(h)/sizeof(h[0])) ;

    for(int i=0; i<sizeof(h)/sizeof(h[0]); i++){
        printf("%d, ", h[i]);
    }


    //Multiplicación
    printf("\n");
    printf("\n");
    printf("\n");

    multiplicar(h, sizeof(h)/sizeof(h[0]), x, sizeof(x)/sizeof(x[0]));


    // for(int i=0; i<sizeof(producto)/sizeof(producto[0]); i++){
    //     printf("%d, ", producto[i]);
    // }

    return 0;
}