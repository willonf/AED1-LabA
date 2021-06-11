#!/bin/bash
clear
echo "Iniciando o executável..."
gcc -c main.c
gcc -c TorreDeHanoi.c
gcc -o TP2 *.o
rm -rf *.o
./TP2.exe
