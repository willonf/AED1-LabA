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

void imprime_aprovados(int n, Aluno **turmas);
double media(float p1, float p2, float p3);

void main() {
  int n;
  Aluno *relacaoDeAlunos;

  scanf("%d", &n);
  relacaoDeAlunos = malloc(n * sizeof(Aluno));

  for (int i = 0; i < n; i++) {
    printf("Nome:");
    scanf("%s", relacaoDeAlunos[i].nome);
    printf("Matricula:");
    scanf("%s", relacaoDeAlunos[i].matricula);
    printf("Turma:");
    scanf("%c", &relacaoDeAlunos[i].turma);
    printf("P1:");
    scanf("%f", &relacaoDeAlunos[i].p1);
    printf("P2:");
    scanf("%f", &relacaoDeAlunos[i].p2);
    printf("P3:");
    scanf("%f", &relacaoDeAlunos[i].p3);
  }
  imprime_aprovados(n, &relacaoDeAlunos);
  free(relacaoDeAlunos);
}

double calculaMedia(float p1, float p2, float p3) {
  double media = (p1 + p2 + p3) / 3.0;
  return media;
}

void imprime_aprovados(int n, Aluno **turmas) {
  double media;
  for (int i = 0; i < n; i++)
  {
    media = calculaMedia((*turmas[i]).p1, (*turmas[i]).p2, (*turmas[i]).p3);
    if (media >= 6.0)
    {
      printf("%s\n", turmas[i]->nome);
      printf("%s\n", turmas[i]->matricula);
      printf("%c\n", turmas[i]->turma);
      printf("%.2f\n", media);
    }
  }
}