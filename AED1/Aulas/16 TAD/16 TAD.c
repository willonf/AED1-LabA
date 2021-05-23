#include "stdio.h"
#include "str.h"


// TAD é Tipo Abstrato de Dados
// A ideia é encapsular um tipo determinado de dados e aforma concreta como esse tipo foi implementado
// Um progrma pode ser composto por vários módulos que, após compilados, geram um arquivo ".o" ou ".obj"
// O linker é utilizado para reunir todos os arquivos objeto em um programa executável
// Arquivo ".h": contém os protótipos.


void main() {

    char str[101], str1[51], str2[51];

    scanf(" %50[^\n]", str1);
    scanf(" %50[^\n]", str2);

    copia(str, str1);
    concat(str, str2);
}