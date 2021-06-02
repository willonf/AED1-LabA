
#include "stdio.h"
#include "calc.h"

// TAD é Tipo Abstrato de Dados
// A ideia é encapsular um tipo determinado de dados e aforma concreta como esse tipo foi implementado
// Um progrma pode ser composto por vários módulos que, após compilados, geram um arquivo ".o" ou ".obj"
// O linker é utilizado para reunir todos os arquivos objeto em um programa executável
// Arquivo ".h": contém os protótipos.

// Recomendado:
// No arquivo .c colocamos as structs e funções
// No arquivo .h coloca-se as interfaces de structs (typedefs) e de funções

// Um TAD consiste em:
// Uma interface que indica as operações que um tipo suporta, parâmetros e resultados. Arquivo .h
// Uma implementação que indica como os dados devem ser representados e operações permitidas. Arquivo .c

// Compilação:
// gcc -c arquivoPrincipal.c
// gcc -c módulo.c
// gcc -o nomeDoPrograma arquivoPrincipal.o módulo.o ou gcc -o nomeDoPrograma *.o


void main() {
    int number1 = 10;
    int number2 = 15;

    printf("Soma: %d\n", sum(number1, number2));
    printf("Subtracao: %d\n", subtract(number1, number2));
    printf("Produto: %d\n", product(number1, number2));
}