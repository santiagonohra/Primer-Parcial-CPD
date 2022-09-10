/**********************************************************
 * Fecha: 9 de Agosto de 2022
 * Autor: Santiago Nohra Nieto
 * Materia: Computacion Paralela y Distribuida
 * Tema: Construccion Benchmark Multiplicacion de Matrices
 * Docente: John Corredor, PhD.
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "mm_lib.h"

/*
Clase de Agosto 16 de 2022
Se requiere reservar un espacio de memoria, para ser
depues usado por las matrices
1024 bytes * 1024 bytes * 64 bytes * 3 matrices
*/
#define DATA_SIZE (1024*1024*64*3)

static int MEM_CHUNK[DATA_SIZE];

/*
 * Se declaran las variables globales
 * 

*/

int *matrizA, *matrizB, *matrizC;   //Matrices de doubles
int Num_Hilos;                         //Cantidad de hilos
int N;                                 //Dimension de la matriz

/* argc = argument count //// argv = argument vector */
/* En **argv al poner dos *, representa un apuntador */

int main(int argc, char **argv){
    
    N = (int) atof(argv[1]);
    
    
    /* Inicializacion de matrices con apuntadores de memoria,
    no es necesario poner el tamanio al ser punteros */

    matrizA = MEM_CHUNK;
    matrizB = matrizA + N*N;
    matrizC = matrizB + N*N;
    inicializar_matrices_int_rnd(matrizA,matrizB,matrizC,N);
    
    /*Impresion matrices a y b 
    printf("Matriz A\n-------\n");
    imprimir_matriz_int(matrizA, N);
    printf("Matriz B\n-------\n");
    imprimir_matriz_int(matrizB, N);*/

    /* Multiplicacion de matrices clasica (a x b)
    punto_prueba_inicial();
    multiplicar_matriz_clasica_regular(matrizA, matrizB, matrizC, N);
    punto_prueba_final();

    printf("Matriz C = A x B\n----------\n");
    imprimir_matriz_int(matrizC, N);*/


    punto_prueba_inicial();
    multiplicar_matriz_clasica_int(matrizA, matrizB, matrizC, N);
    punto_prueba_final();
/*
    printf("Matriz C = A x B\n----------\n");
    imprimir_matriz_int(matrizC, N);
    */
    return 0;
}







