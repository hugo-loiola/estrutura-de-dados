#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Uso: %s <nome do arquivo de entrada>\n", argv[0]);
    return 1;
  }

  const char *nomeArquivo = argv[1];

  // Calcular a menor vizinhança
  double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
  if (menorVizinhanca < 0)
  {
    printf("Erro ao calcular a menor vizinhança.\n");
    return 1;
  }
  printf("Menor vizinhança: %.2f\n", menorVizinhanca);

  // Encontrar a cidade com a menor vizinhança
  char *cidade = cidadeMenorVizinhanca(nomeArquivo);
  if (cidade == NULL)
  {
    printf("Erro ao encontrar a cidade com a menor vizinhança.\n");
    return 1;
  }
  printf("Cidade com a menor vizinhança: %s\n", cidade);

  free(cidade);

  return 0;
}
