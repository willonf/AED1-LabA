#include <stdio.h>
#define N 10
//Alterar a tag para 0 faz com que o programa funcione com caracteres
#define TAG 1

void let(char imagem[][N], int X, int Y, char c);
void clear(char imagem[][N], int l, int c);
void imprime(char imagem[][N], int l, int c);
void init(char imagem[][N], int l, int c);

int main()
{
    char comandoChar, imagem[N][N];
    int linha, coluna, comandoInt;

    if (TAG)
    {
        scanf("%d", &comandoInt);

        if (comandoChar == 'I')
        {
            printf("Linha e Coluna: ");
            scanf("%d%d ", &linha, &coluna);
            linha++;
            coluna++;
            init(imagem, linha, coluna);
        }
    }
    else
    {
        comandoChar = getchar();
    }
    if (TAG)
    {
        comandoInt != 9;
    }
    else
    {
        comandoChar != 'X';
    }


        while (if (TAG) comandoInt != 9 else comandoChar != 'X')
    {
        imprime(imagem, linha, coluna);
        printf("Comando: ");
        scanf("%c", &comando);

        if (comando == 'C')
            clear(imagem, linha, coluna);
        if (comando == 'L')
        {
            char caracter;
            int x, y;
            printf("X&Y: ");
            scanf("%d%d", &x, &y);
            printf("Catacter: ");
            caracter = getchar();
            let(imagem, x, y, caracter);
        }
    }
}

void let(char imagem[][N], int X, int Y, char c)
{
    imagem[X][Y] = c;
}

void clear(char imagem[][N], int l, int c)
{
    for (int i = 1; i < l; i++)
        for (int j = 1; j < c; j++)
            imagem[i][j] = 'O';
}

void imprime(char imagem[][N], int l, int c)
{
    for (int i = 1; i < l; i++)
    {
        for (int j = 1; j < c; j++)
            printf("%c", imagem[i][j]);
        printf("\n");
    }
}

void init(char imagem[][N], int l, int c)
{
    for (int i = 1; i < l; i++)
        for (int j = 1; j < c; j++)
            imagem[i][j] = 'O';
}