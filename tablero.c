//Función para dibujar el tablero del juego buscaminas
#include "modular.h"
void imprimir_tablero(int tablero[][15], int perder)
{
     int i, j;
    
     for(i = 0; i <= RENGLON -1; i++){  	//Línea de encabezado que va entre 0 y 14
       printf("%d ", i);
     } 
     printf("\n");  				
    
     for(i = 0; i <= COLUMNA - 1; i++){	//Línea de guiones que va luego del encabezado
       if(i>9){				//Si es un número mayor a 9 se utilizarán dos guiones
        printf("-- ");
       }
       else{
        printf("- "); 	
       }
    }   
     printf("\n");
    
     for(i = 0; i <= RENGLON -1; i++)
     {
           for(j = 0; j <= COLUMNA - 1; j++){
          
             if(tablero[i][j] == 1){
             	 printf("%d ", tablero[i][j]);
             }
             else if((tablero[i][j] == 3) && (perder == -1)){
             	printf("%c ", '*');
             }
             else{
             	printf("%c ", '#');        
             }
           }
          
           printf("| %d", i);   
           printf("\n"); 
          
     }
    
        
    
}
