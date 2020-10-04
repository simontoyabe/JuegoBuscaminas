#include "modular.h"

int main(){
  void imprimir_tablero(int tablero[][15], int perder);	//definición funciones a utilizar (no arrojan ningún resultado)
  void colocar_bombas(int minas[][15], int bum);
  void frases_1(int buscar);
  void frases_2(int numero);
  int buscaminas[RENGLON][COLUMNA] = {0}, i, j;	  // definición de la estructura inicial en 0
  int nivel, bombas;                                    //bombas aleatorias y nivel
  int gameStatus, gameCounter = 0, victoria;            //control del juego
  int tiradas, frases;                                  //estadísticas del juego
  float rating;					  // Para conocer el porcentaje de avance que tuvo el usuario en el juego
  char salida;						  // Para determinar si el usuario desea seguir jugando

  do{
       system("clear");				  //Limpieza de la terminal
       printf("\n -Juego Buscaminas- \n\n");
       printf("Tienes 10 bombas en el primer nivel y cada que subas de nivel te agregaremos 5 más.\n\n");
      
       printf("~Ingresa el nivel que quieres jugar:\n");
       printf("%d.-Nivel 1\n%d.-Nivel 2\n%d.-Nivel 3\n%d.-Nivel 4\n%d.-Nivel 5\n", 1, 2, 3, 4, 5);
      

       scanf("%d", &nivel);				//Leer nivel que desea jugar el usuario
       fflush(stdin);					//Limpieza del buffer
       switch(nivel){					//De acuerdo al nivel se determinan la cantidad de bombas
      
           case 1: bombas = 10;
                   break;
                  
           case 2: bombas = 15;
                   break;
                  
           case 3: bombas = 20;
                   break;
                  
           case 4: bombas = 25;
                   break;
                  
           case 5: bombas = 30;
                   break;
                  
           default: printf("Seleccion inválida, inténtalo de nuevo.\n\n");  //En caso de que el usuario ingrese un valor que no esté entre 1-5
                    break;                 
                    
       }
        
       srand(time(NULL));  //Instrucción que inicializa el generador de números aleatorios
      
       colocar_bombas(buscaminas, bombas); // Llamado a la función colocar bombas
      
       tiradas = 0; //Este contador lleva cuenta del numero de tiradas en el juego
      
       do{
           system("clear");
           printf("\n-Buscaminas-\n\n");
          
           imprimir_tablero(buscaminas, gameStatus);           //Generar en la terminal el tablero buscaminas para comenzar
          
           printf("\n"); 
          
           printf("*Ingrese el valor para i (fila): ");	 //Pedir posición de la fila
           scanf("%d",&i);					 //Leer posición de la fila
           fflush(stdin);					 //Limpiar buffer
           printf("*Ingrese el valor para j (columna): ");	 //Pedir posición de la columna
           scanf("%d",&j);					 //Leer posición de la columna
           fflush(stdin);					 //Limpiar buffer
          
           if(buscaminas[i][j] == 3){                 	 //Determinar si se ha seleccionado una posición de una mina             
               gameStatus = -1;				 //Asignar un valor al estado del juego
               tiradas++;					 //Aumentar cantidad de intentos
               printf("\n-Buscaminas-\n\n");
               imprimir_tablero(buscaminas, gameStatus);	 //Imprimir tablero con la ubicación de las minas
               printf("¡¡¡Perdiste, tocaste una bomba y el juego ha terminado!! \n");
              	getchar();              
           }
           else
           {
               buscaminas[i][j] = 1;				 //Ubicar los unos en las posiciones solicitadas
               gameCounter++;			
               tiradas++;
           }
           if(gameCounter == (225 - bombas) )			 //Dar mensaje de victoria cuando se llenan todos los espacios donde no hay bombas
           {
               victoria = 1;
               system("clear");
               printf("\nBuscaminas-\n\n");
               imprimir_tablero(buscaminas, gameStatus);
               printf("¡¡¡Has ganado, felicidades!!!");
      	       getchar();
           }       
          
              
       }while(gameStatus != -1 || victoria == 1);			//Salir del juego porque se perdió o se ganó
      
       rating = (gameCounter)*100 / 225;        			//Porcentaje del juego que avanzó antes de perder o ganar
      
       printf("\n-Buscaminas-  Estadisticas del juego.\n\n");
       printf("El porcentaje del nivel que superaste fue: %.2f  \n", rating);
       printf("*No. de tiradas %d.\n\n", tiradas);
      
       frases = 1 + rand() % 4;  					//Se reproduce un valor aleatorio entre 1 y 4, con el cual se selecciona una de las frases
       
       if(gameStatus == -1){     					//Frases para cuando se perdió el juego
         frases_2(frases);
         }
       else if(victoria == 1){	  				//Frases para cuando se ganó el juego
         frases_1(frases);
         }
      
       printf("\n\n");
      
       printf("¿Quieres volver a jugar(S/N)?: ");			//Preguntar al usuario si desea seguir jugando
       scanf("%c", &salida);    					//Almacena respuesta del usuario
       fflush(stdin);							//Limpiar buffer
       salida = tolower(salida); 					//Convierte salida del usuario en un carácter en minúscula
       if (salida == 's') {						//Reiniciar el tablero del juego en caso de que quiera seguir jugando
        for(i = 0; i <= RENGLON - 1; i++){
           for(j = 0; j <= COLUMNA - 1; j++){
           	buscaminas[i][j] = 0;
           }
       }
       }   
       gameCounter = 0;         					//Se reinician los valores para el contador del número de aciertos
       gameStatus = 1;		 					// Se cambia el valor de GameStatus a un valor diferente de -1 para comenzar otro nivel
      
      
  }while(salida == 's');     						//Esto se ejecutará siempre y cuando el usuario halla respondido que si quiere seguir jugando     
  
  printf("\n -Buscaminas-\n\n");
  printf("\nCréditos\n Simón Montoya Bedoya y Juan Manuel Gómez.\nVuelve pronto...\n");
  
  return (0);
}

