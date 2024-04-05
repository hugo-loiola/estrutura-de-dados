#include <stdio.h>
#include <math.h>
#include <string.h>

struct Pessoa
{
  char Nome[100];
  int Idade;
  float Altura;
  float Peso;
} typedef Pessoa;

Pessoa CadastrarPessoa();
void ExibirPessoa(Pessoa X);
float CalcularIMC(Pessoa X);
void FazendoAniversario(Pessoa *X);

void main()
{
  Pessoa X = CadastrarPessoa();

  ExibirPessoa(X);

  FazendoAniversario(&X);

  ExibirPessoa(X);

  printf("O IMC de e igual a %.3f", CalcularIMC(X));

  return 0;
}

Pessoa CadastrarPessoa()
{

  Pessoa P;
  printf("Nome: ");
  gets(P.Nome);

  printf("Idade: ");
  scanf("%d", &P.Idade);

  printf("Altura: ");
  scanf("%f", &P.Altura);

  printf("Peso: ");
  scanf("%f", &P.Peso);
}

void ExibirPessoa(Pessoa X)
{
  printf("%s %d %.2f %.2f\n", X.Nome, X.Idade, X.Altura, X.Peso);
}

float CalcularIMC(Pessoa X)
{
  float IMC = X.Peso / pow(X.Altura, 2);
  return (IMC);
}

void FazendoAniversario(Pessoa *X)
{
  X->Idade = X->Idade + 1;

  // Usando -> no lugar de . pois X é um ponteiro da struct
}