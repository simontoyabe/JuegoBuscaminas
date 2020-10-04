/* Juego Buscaminas UNAL

Simón Montoya Bedoya
Juan Manuel Gómez 
*/

#ifndef _MODULAR_H
#define _MODULAR_H

#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define RENGLON 15		//Se define el tamaño vertical de la cuadrícula para el juego
#define COLUMNA 15 		//Se define el tamaño horizontal de la cuadrícula para el juego

void imprimir_tablero(int tablero[][15], int perder);
void colocar_bombas(int minas[][15], int bum);
void frases_1(int buscar);
void frases_2(int numero);

#endif
