#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct aluno Aluno;
struct aluno
{
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};

float calculaMedia(float p1, float p2, float p3) {
    float media = (p1 + p2 + p3) / 3;
    return media;
}

float media_turma(int n, Aluno **turmas, char turma) {
    float media;
    float soma = 0; 
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if(turmas[i]->turma == turma){
            soma += calculaMedia(turmas[i]->p1, turmas[i]->p2, turmas[i]->p3);
            cont++;
        }
    }
    media = soma/cont;
    if(!cont){
        return 0.0;
    }
    return media;
}

void main() {
    int n, t;
    char turma;
    Aluno **alunos;
    float media;
    scanf("%d", &n);
    alunos = malloc(n * sizeof(Aluno *));
    if (alunos == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        alunos[i] = malloc(sizeof(Aluno));
        if (alunos[i] == NULL)
        {
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", alunos[i]->nome);
        scanf("%s%*c", alunos[i]->matricula);
        scanf("%c", &alunos[i]->turma);
        scanf("%f", &alunos[i]->p1);
        scanf("%f", &alunos[i]->p2);
        scanf("%f", &alunos[i]->p3);
    }

    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        scanf("%*c%c", &turma);
        media = media_turma(n, alunos, turma);
        printf("%.2f\n", media);
    }

    for (int i = 0; i < n; i++) {
        free(alunos[i]);
    }
    free(alunos);
}
