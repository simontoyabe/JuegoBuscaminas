//La siguiente funcion coloca las bombas en el tablero por medio de una
//funcion aleatoria de 0-14.Además se utiliza el valor de 3 para identificarlo luego las bombas

#include "modular.h"
void colocar_bombas(int minas[][15], int bum)
{
     int i, renglon, columna;
    
     for(i = 1; i <= bum; i++)
     {
           renglon = rand() % 14;   // Escoger un número aleatorio entre 0 y 14 el cuál define en que fila estamos
           columna = rand() % 14;   // Escoger un número aleatorio entre 0 y 14 el cuál define en que columna estamos
          	
           minas[renglon][columna] = 3;	//A cada posición en la que se ubica una bomba se le asigan el valor de 3 para identificarla
     }
}
