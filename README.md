<p align="center">
<i><b>Computación Paralela y Distribuida</b></i>
<br>
<img src="https://res-5.cloudinary.com/crunchbase-production/image/upload/c_lpad,h_256,w_256,f_auto,q_auto:eco/v1455514364/pim02bzqvgz0hibsra41.png"
width="150" height="150">
</img>
<br>
<i><b>Estudiantes:</b></i>
<br>
Juan Camilo Rodriguez Fonseca
<br>
Juan Camilo de los Ríos
<br>
Johan Moreno
<br>
Santiago Nohra
<br>
<i><b>Docente:</b></i><br> John Jairo Corredor Franco, PhD.
<br>
<i><b>Tema:</b></i><br> Primer Parcial
<br>
Procesamiento de Datos de Benchmarks
<br>
<i><b>Fecha inicio:</b></i><br> 25/08/22
<br>
<i><b>Fecha entrega:</b></i><br> 12/09/22
</p>

# Overview

En este repositorio se encuentra una batería de experimentos de 4 benchmarks. Estos consisten en la multiplicación de matrices con valores enteros, enteros aleatorios, doubles y doubles aleatorios respectivamente. Los ficheros de los dos benchmarks con matrices de tipo double se encuentran en el directorio `Bench_Double/` y los dos benchmarks con matrices de tipo entero se encuentran en el directorio `Bench_Int/`.

## `Bench_Int/`

En este directorio, como se mencionó previamente, se encuentran los ficheros necesarios para la ejecución de los benchmarks con matrices de tipo entero. Se cuenta con 6 ficheros para estos benchmarks.
 * `mm_main_int.c` 
   - Contiene la función principal del benchmark con matrices de enteros definidos.
 * `mm_main_int_rnd.c`
   - Contiene la función principal del benchmark con matrices de enteros aleatorios.
 * `mm_lib.c`
   - Contiene las funciones y bibliotecas necesarias para la ejecución de los experimentos, más notablemente, las funciones de multiplicación de matrices con punteros y de inicio y fin de conteo para la ejecución de la operación.
 * `mm_lib.h`
   - Es el fichero de cabecera que permite definir las funciones de la biblioteca o módulo `mm_lib.c` que contiene todas las funciones de interés, para así simplemente ser llamado en los ficheros con la función principal.
 * `Makefile`
   - Este archivo se encarga de la compilación de los proyectos, en este se definen los argumentos de compilación, las banderas de linkeo con bibliotecas, archivos ejecutables resultantes, etc.
 * `lanzador.pl`
   - Este fichero es el responsable de ejecución de todo el experimento, es aquí donde se definen las 12 cargas entre 280 y 4800 para los experimentos, los experimentos a ejecutar e.g. `mm_main_int.c`, `mm_main_int_rnd.c`, la variable `$procesador` con el nombre del procesador del nodo de cómputo para el experimento, se hace el llamado al `Makefile` mencionado anteriormente, se ejecutan los archivos ejecutables resultantes con cada carga un total de 30 veces, y se registran los resultados en un archivo `.csv` en la carpeta `Soluciones/` para cada benchmark. Cada fichero `.csv` tiene como columnas los valores correspondientes a la carga.

## `Bench_Double/`

En este directorio, como se mencionó previamente, se encuentran los ficheros necesarios para la ejecución de los benchmarks con matrices de tipo double. Se cuenta con 6 ficheros para estos benchmarks también.
 * `mm_main_double.c` 
   - Contiene la función principal del benchmark con matrices de doubles definidos.
 * `mm_main_double_rnd.c`
   - Contiene la función principal del benchmark con matrices de doubles aleatorios.
 * `mm_lib.c`
   - Contiene las funciones y bibliotecas necesarias para la ejecución de los experimentos, más notablemente, las funciones de multiplicación de matrices con punteros y de inicio y fin de conteo para la ejecución de la operación.
 * `mm_lib.h`
   - Es el fichero de cabecera que permite definir las funciones de la biblioteca o módulo `mm_lib.c` que contiene todas las funciones de interés, para así simplemente ser llamado en los ficheros con la función principal.
 * `Makefile`
   - Este archivo se encarga de la compilación de los proyectos, en este se definen los argumentos de compilación, las banderas de linkeo con bibliotecas, archivos ejecutables resultantes, etc.
 * `lanzador.pl`
   - Este fichero es el responsable de ejecución de todo el experimento, es aquí donde se definen las 12 cargas entre 280 y 4800 para los experimentos, los experimentos a ejecutar e.g. `mm_main_double.c`, `mm_main_double_rnd.c`, la variable `$procesador` con el nombre del procesador del nodo de cómputo para el experimento, se hace el llamado al `Makefile` mencionado anteriormente, se ejecutan los archivos ejecutables resultantes con cada carga un total de 30 veces, y se registran los resultados en un archivo `.csv` en la carpeta `Soluciones/` para cada benchmark. Cada fichero `.csv` tiene como columnas los valores correspondientes a la carga.

## Outputs

Como salidas de esta batería de experimentos, en el directorio `Soluciones/` dentro de cada benchmark, se obtienen 4 archivos `.csv` para cada nodo de cómputo que se esté evaluando, cada uno de estos representa los resultados del benchmark con enteros, enteros aleatorios, doubles y doubles aleatorios respectivamente, y todos tienen la misma cantidad de columnas, que repreentan la carga de cada medida. Por último, cada `.csv` contiene un total de 30 filas, es decir, para cada benchmark se hacen 30 repeticiones por carga/columna.

# Ejecución

* Para ejecutar esta batería de experimentos con benchmarks, primeramente se recomienda profundamente usar Linux, preferiblemente Ubuntu 22.04 LTS, ya que este sistema operativo fue el utilizado por todos los autores para desarrollar el proyecto. Segundamente, es necesario tener `GCC` en su versión `11.2.0`, `GNU Make` en su versión `4.3` y `perl` en su versión `5.34.0`. 

* Para la ejecución del proyecto, solo se debe dirigir al directorio `Bench_Int/` y ejecutar el archivo `.pl` por medio del comando `./lanzador.pl`. 

* Es muy importante que se ejecute este fichero dentro del directorio especificado, ya que este es el responsable de hacer uso del `Makefile`, el registro de los archivos `.csv` y el llamado a `Bench_Double/lanzador.pl` de los benchmarks de doubles. Es decir, con solo ejecutar el archivo especificado, ya se hace todo el experimento sin necesidad de cambiar ni ejecutar nada más.
