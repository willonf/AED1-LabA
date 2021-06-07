#!/bin/bash
gcc -c TP2_Willon_Ferreira_da_Silva.c
gcc -c TorreDeHanoi.c
gcc -o TP2 *.o
rm -rf *.o
./TP2.exe
