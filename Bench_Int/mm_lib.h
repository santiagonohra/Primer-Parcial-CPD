/**********************************************************
 * Fecha: 9 de Agosto de 2022
 * Autor: Santiago Nohra Nieto
 * Materia: Computacion Paralela y Distribuida
 * Tema: Construccion Benchmark Multiplicacion de Matrices
 * Docente: John Corredor, PhD.
***********************************************************/


/* Archivo de header de funciones del proyecto */

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

void punto_prueba_inicial();
void punto_prueba_final();

int random_int();
void inicializar_matrices_int(int *matrizA, int *matrizB, int *matrizC, int N);
void inicializar_matrices_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N);


void imprimir_matriz_int(int *matriz, int N);
void multiplicar_matriz_clasica_int(int *matrizA, int *matrizB, int *matrizC, int N);

#endif