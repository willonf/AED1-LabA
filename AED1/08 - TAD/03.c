#include <stdio.h>
#include <stdlib.h>

typedef struct matriz
{
    int lin;
    int col;
    float *v;
} Matriz;

Matriz *mat_cria(int m, int n);
void mat_libera(Matriz *mat);
float mat_acessa(Matriz *mat, int i, int j);
void mat_atribui(Matriz *mat, int i, int j, float value);
int mat_linhas(Matriz *mat);
int mat_colunas(Matriz *mat);
Matriz *transposta(Matriz *mat);

void main()
{
    int l, c;
    Matriz *matrix;
    Matriz *matrixTransp;
    float valor;

    scanf("%d%d", &l, &c);
    
    matrix = mat_cria(l, c);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &valor);
            mat_atribui(matrix, i, j, valor);
        }
    }

    matrixTransp = transposta(matrix);

    for (int i = 0; i < matrixTransp->lin; i++)
    {
        for (int j = 0; j < matrixTransp->col; j++)
        {
            printf("%.2f ", mat_acessa(matrixTransp, i, j));
        }
        printf("\n");
    }

    mat_libera(matrix);
    mat_libera(matrixTransp);
}

Matriz *mat_cria(int m, int n) {
    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
    if(mat->v == NULL){
        exit(1);
    }
    mat->lin = m;
    mat->col = n;

    float *v = (float *) malloc(m*n*sizeof(float));
    if(v == NULL) {
        exit(1);
    }

    mat->v = v;
    return mat;
}

void mat_libera(Matriz *mat) {
    free(mat->v);
    free(mat);
}

void mat_atribui(Matriz *mat, int i, int j, float value) {
    float *v = mat->v;
    v[i*mat->col + j] = value;
}

float mat_acessa(Matriz *mat, int i, int j) {
    return mat->v[i*mat->col + j];
}

int mat_linhas(Matriz *mat) {
    return mat->lin;
}

int mat_colunas(Matriz *mat) {
    return mat->col;
}

Matriz *transposta(Matriz *mat) {
    Matriz *transp;
    transp = mat_cria(mat->col, mat->lin);

    for(int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            transp->v[j*transp->col + i] = mat->v[i*mat->col+j];  // n = 3
        } 
    }
    return transp;
}