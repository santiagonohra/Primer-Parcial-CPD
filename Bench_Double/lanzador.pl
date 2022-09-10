#!/usr/bin/perl

=begin comment

Fecha: 23 de Agosto 2022
Autor: Santiago Nohra
Tema: Ejecucion automatizada de Benchmarks

=cut


#Vector para los benchmarks representa el ejecutable
@Benchmarks = ("mm_main_double", "mm_main_double_rnd");

#Vector para las cargas, tamaño de N
@Cargas = ("302", "412", "488", "564", "682", "712", "792", "838", "952", "1146", "1262", "1300");

#Numero de repeticiones (Variable)
$n = 30;

#Se almacena la ubicacion de un archivo
#$Path = q{"/home/santiago/Documents/Computacion Paralela y Distribuida/Benchmarks/Bench_PThreads/"};
$Path =q{"./"};
#Se escribe el procesador del nodo de prueba
$procesador = q{"Intel i5 - 12400 16gb ram"};

#Se itera sobre la cantidad de ejecutables (benchmarks) la cantidad de cargas (carga)
# y sobre la cantidad de repeticiones (N)

system("make all");

#Vector auxiliar de las cargas que contiene todas excepto el ultimo valor
#Para no poner coma "," despues del ultimo valor para el csv.
my @Aux = @Cargas;
pop @Aux;

foreach $exes (@Benchmarks){
    $file = "Soluciones/".$procesador."-$exes.csv";
    foreach $carga (@Aux){
        system("echo -n $carga, >> $file");
    }
    system("echo -n $Cargas[@Cargas-1] >> $file");
    system("echo >> $file");
    foreach ($i=0;$i<$n;$i++){
        foreach $carga (@Aux){
            #Se crea un fichero para almacenar los datos
            #$file = "Soluciones/".$exes."-size-".$carga.".txt";
            #print("$Path$file\n");
            system("echo -n \$\($Path$exes $carga\), >> $file");
            #print("$Path$exes $carga\n");
        }
        system("echo -n \$\($Path$exes $Cargas[@Cargas-1]\) >> $file");

        system("echo >> $file");
        close($file);
    }
}

system("make clean");


