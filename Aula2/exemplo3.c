#include <stdio.h>
#include <math.h>

struct Pessoa
{
  char Nome[100];
  int Idade;
  float Altura;
  float Peso;
} typedef Pessoa;

int main()
{
  Pessoa X = CadastrarPessoa();

  ExibirPessoa(X);

    return 0;
}

Pessoa CadastrarPessoa()
{

  Pessoa P;
  printf("Nome: ");
  scanf("%s", P.Nome);

  printf("Idade: ");
  scanf("%d", &P.Idade);

  printf("Altura: ");
  scanf("%f", &P.Altura);

  printf("Peso: ");
  scanf("%f", &P.Peso);
};

void ExibirPessoa(Pessoa X)
{
  printf("%s %d %.2f %.2f\n", X.Nome, X.Idade, X.Altura, X.Peso);
};

float CalcularIMC(Pessoa X)
{
  float IMC = X.Peso / pow(X.Altura, 2);
}