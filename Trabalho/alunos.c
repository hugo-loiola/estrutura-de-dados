#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Nome[50];
  char Numero[20];
  char Curso[20];
  float Nota1, Nota2, Media;
  char Situacao[20];
} Aluno;

void calcularMedia(float nota1, float nota2, float *media, char *situacao[20])
{
  *media = (nota1 + nota2) / 2.0;
  *situacao = (*media >= 7.0) ? "Aprovado" : "Reprovado";
}

int main()
{
  FILE *entrada, *saida;
  Aluno X;

  entrada = fopen("DadosEntrada.csv", "r");
  saida = fopen("SituacaoFinal.csv", "w"); // "r" abre o arquivo para leitura
  if (entrada == NULL || saida == NULL)
  {
    printf("O arquivo nao pode ser aberto!\n");
    exit(1);
  }
  // Descartar a primeira linha do arquivo de entrada
  fscanf(entrada, "%*[^\n]");
  fgetc(entrada); // Lê e descarta o caractere de nova linha
  // Escrever o cabeçalho no arquivo de saída
  fprintf(saida, "Nome,Media,Situação\n");
  // Ler DadosEntrada e escrever SituacaoFinal
  while (fscanf(entrada, "%[^,],(%[^)]) %*1[^(] %*[^,],%[^,],%f,%f", X.Nome, X.Numero, X.Curso, &X.Nota1, &X.Nota2) !=
         EOF)
  {
    calcularMedia(X.Nota1, X.Nota2, &X.Media, (char **)&X.Situacao);
    fprintf(saida, "%s,%.2f,%s", X.Nome, X.Media, X.Situacao);
  }

  printf("Terminado!\n");
  // Fechar os arquivos
  fclose(entrada);
  fclose(saida);

  return 0;
}