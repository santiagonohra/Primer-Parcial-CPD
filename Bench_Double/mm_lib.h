/**********************************************************
 * Fecha: 30 de Agosto de 2022
 * Autor: Santiago Nohra Nieto
 * Materia: Computacion Paralela y Distribuida
 * Tema: Construccion Benchmark Multiplicacion de Matrices
 * Docente: John Corredor, PhD.
 * Topico: Modulo para doubles
 ***********************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

#ifndef MM_LIB_H_INCLUDED
#define MM_LIB_H_INCLUDED

void punto_prueba_inicial();

void punto_prueba_final();

int random_double();

void inicializar_matrices_double_rnd(double *matrizA, double *matrizB, double *matrizC, int N);

void inicializar_matrices_double(double *matrizA, double *matrizB, double *matrizC, int N);

void imprimir_matriz_double(double *matriz, int N);

void multiplicar_matriz_clasica_double(double *matrizA, double *matrizB, double *matrizC, int N);

#endif