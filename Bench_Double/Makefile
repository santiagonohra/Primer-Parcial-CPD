#/**********************************************************
# * Fecha: 9 de Agosto de 2022
# * Autor: Santiago Nohra Nieto
# * Materia: Computacion Paralela y Distribuida
# * Tema: Construccion Benchmark Multiplicacion de Matrices
# * Docente: John Corredor, PhD.
#***********************************************************/

GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm

PROGRS = mm_main_double mm_main_double_rnd

all: $(PROGRS)

# @ es el nombre de la comanda (funcion)

# Lo de abajo es equivalente a gcc -c Proyecto_BMI_2_main.c, gcc -c Proyecto_BMI_2_lib.c, gcc -o appIMC Proyecto_BMI_2_lib.o Proyecto_BMI_2_main.o -lm 

mm_main_double:
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_double_rnd:
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)


# Para eliminar ls

clean:
	$(RM) *.o $(PROGRS)

	