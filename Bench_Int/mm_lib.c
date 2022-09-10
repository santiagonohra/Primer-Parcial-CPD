/**********************************************************
 * Fecha: 9 de Agosto de 2022
 * Autor: Santiago Nohra Nieto
 * Materia: Computacion Paralela y Distribuida
 * Tema: Construccion Benchmark Multiplicacion de Matrices
 * Docente: John Corredor, PhD.
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

/* Archivo de funciones del proyecto */

/* Hacemos una estructura */

struct timespec inicio_cuenta, fin_cuenta;

/* Funcion evaluacion inicio de tiempo */

void punto_prueba_inicial()
{
    clock_gettime(CLOCK_MONOTONIC, &inicio_cuenta);
}

/* Funcion evaluacion final de tiempo, impresion de resultados */

void punto_prueba_final()
{
    double tiempo_total;
    clock_gettime(CLOCK_MONOTONIC, &fin_cuenta);
    tiempo_total = (fin_cuenta.tv_sec - inicio_cuenta.tv_sec) * 1e9;
    tiempo_total = (tiempo_total + fin_cuenta.tv_nsec - inicio_cuenta.tv_nsec) * 1e-9;
    printf("%f\n", tiempo_total);
}

/* Funcion para crear aleatorios Int */
int random_int()
{
    int min = 0, max = 9;
    static int flag = -1;
    if ((flag = (flag < 0)))
    {
        /* Semilla para que el numero aleatorio no se repita */
        srand(time(NULL) + getpid());
    }
    if (min > max)
    {
        return errno = EDOM, NAN;
    }
    return min + (int)rand() / ((int)RAND_MAX / (max - min));
}

/* Funcion inicializadora aleatoria */
void inicializar_matrices_int_rnd(int *matrizA, int *matrizB, int *matrizC, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrizA[i + j * N] = random_int();
            matrizB[i + j * N] = random_int();
            matrizC[i + j * N] = 0;
        }
    }
}

/*Se implementa la multiplicacion de matrices con dimensiones iguales*/

/*Se inicializan las matrices con numeros aleatorios*/

void inicializar_matrices_int(int *matrizA, int *matrizB, int *matrizC, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrizA[i + j * N] = 2 * (i + j);
            matrizB[i + j * N] = 2 * i + 3 * j;
            matrizC[i + j * N] = 0;
        }
    }
}

/* Funcion impresion de matrices */

void imprimir_matriz_int(int *matriz, int N)
{
    if (N < 5)
    {
        int i, j;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf(" %d", matriz[j + i * N]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

/*
 * Multiplicar matrices regularmente
 * Benchmark 01
 */
/*
void multiplicar_matriz_clasica_regular(int *matrizA, int *matrizB, int *matrizC, int N)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            int suma = 0;
            for (k = 0; k < N; k++)
            {
                suma += matrizA[j + k * N] * matrizB[k + i * N];
            }
            matrizC[j + i * N] = suma;
        }
    }
}*/

/*
 * Multiplicar matrices con punteros
 * Benchmark 02
 */
void multiplicar_matriz_clasica_int(int *matrizA, int *matrizB, int *matrizC, int N)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            int suma = 0;
            /* Punteros Auxiliares */
            int *pA, *pB;
            pA = matrizA + (i * N);
            pB = matrizB + j;
            for (k = 0; k < N; k++, pA++, pB += N)
            {
                suma += (*pA * *pB);
                /*matrizA[j+k*N] * matrizB[k+i*N];*/
            }
            matrizC[j + i * N] = suma;
        }
    }
}