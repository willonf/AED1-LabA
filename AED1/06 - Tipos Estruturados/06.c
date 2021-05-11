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

double calculaMedia(float p1, float p2, float p3){
  double media = (p1 + p2 + p3) / 3.0;
  return media;
}

void imprime_aprovados(int n, Aluno **turmas)
{
  double media = 0;
  for (int i = 0; i < n; i++) {
    media = calculaMedia((*turmas[i]).p1, (*turmas[i]).p2, (*turmas[i]).p3);
    if (media >= 6.0) {
      printf("%s\n", turmas[i]->nome);
      printf("%s\n", turmas[i]->matricula);
      printf("%c\n", turmas[i]->turma);
      printf("%.2f\n", media);
      printf("\n");
    }
    media = 0;
  }
}


void main() {
  int n;
  Aluno **alunos;
  scanf("%d", &n);
  alunos = malloc(n * sizeof(Aluno*));
  if(alunos == NULL) {
        exit(1);
  }

  for (int i = 0; i < n; i++) {
    alunos[i] = malloc(sizeof(Aluno));
    if(alunos[i] == NULL) {
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

  imprime_aprovados(n, alunos);

  for (int i = 0; i < n; i++) {
    free(alunos[i]);
  }
  free(alunos);
}

