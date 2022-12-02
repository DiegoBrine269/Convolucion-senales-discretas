#include <stdio.h>
#include <stdlib.h>

int origenX = 0;
int origenH = 1;
int suma = 0, max = 0;   

void reflejar (int h[], size_t tamano);
int* multiplicar (int h[], size_t tamanoH, int x[], size_t tamanoX);
void desplazar(int n);
void sumar(int *producto, int longitud;);


int main () {

    int x [] = {1, 2, 1, -1};
    int h [] = {1, 2, 3, 1}; //invertir: 0 0 1 2 3 1
	int* multiplicacion;
	
	//Funci�n x
	printf("Longitud de x: %d\n", sizeof(x)/sizeof(x[0]));
	for(int i=0; i<sizeof(x)/sizeof(x[0]); i++){
        printf("%d, ", x[i]);
    }
    
    // Funci�n h
	printf("\n");
    printf("Longitud de h: %d\n", sizeof(h)/sizeof(h[0]));
    for(int i=0; i<sizeof(h)/sizeof(h[0]); i++){
        printf("%d, ", h[i]);
    }
    printf("\n");
    
	// Reflexi�n 	
    reflejar(h, sizeof(h)/sizeof(h[0]));    
    printf("\n");
    
    // Desplazamiento
    desplazar(0);
    
    // Multiplicaci�n
    printf("\n");
    printf("\n");
    printf("\n");
	multiplicacion = multiplicar(h, sizeof(h)/sizeof(h[0]), x, sizeof(x)/sizeof(x[0]));
    sumar(multiplicacion, max);

    return 0;
}

// Reflejar
void reflejar (int h[], size_t tamano) {
    
	int aux = 0;
  	for (int i = 0; i < tamano / 2; i++) {	    
	    aux = h[i];	    
	    h[i] = h[tamano - i - 1];
    	h[tamano - i - 1] = aux;
  	}
  	
  	printf("Reflexion h: %d\n", tamano);
  	for(int i = 0; i< tamano; i++)
  	{
  		printf("%d, ", h[i]);
	}
  	
	origenH = -origenH;
}

// Desplazar
void desplazar(int n) {                 
    //Desplazar a la izquierda
    if(n > 0){
        origenH++;
    }
    //Desplazar a la derecha
    else if(n < 0){
        origenH--;
    }
}

// Multiplicar
int* multiplicar (int h[], size_t tamanoH, int x[], size_t tamanoX) {

    //Se define el tama�o m�ximo
    max = tamanoH > tamanoX ? tamanoH : tamanoX;

    //Arreglo nuevo
    int* producto = (int*)malloc(sizeof(int) * max);

    for(int i=0; i<max; i++) {
        if(i>=tamanoH || i>=tamanoX)
            producto[i] = 0;
        else
            producto[i] = h[i] * x[i];
    }

	printf("Multiplicaci�n de h * x: \n");
    for(int i=0; i<max; i++){
        printf("%d,", producto[i]);        
    }

    return producto;
}

// Sumar
void sumar(int* producto, int longitud){  

    for(int i = 0; i < longitud; i++){
        suma += producto[i];
    }
    printf("\n");
    printf("Suma: %i ", suma);

}
