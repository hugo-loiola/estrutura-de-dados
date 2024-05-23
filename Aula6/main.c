#include <stdio.h>
#include "fracao.h"

int main()
{
  Fracao f1 = criarFracao(1, 2);
  Fracao f2 = criarFracao(3, 4);
  Fracao soma = somarFracao(f1, f2);
  Fracao subtracao = subtrairFracao(f1, f2);
  Fracao multiplicacao = multiplicarFracao(f1, f2);
  Fracao divisao = dividirFracao(f1, f2);
  soma = simplificarFracao(soma);
  subtracao = simplificarFracao(subtracao);
  multiplicacao = simplificarFracao(multiplicacao);
  divisao = simplificarFracao(divisao);
  printf("Soma: %d/%d\n", soma.numerador, soma.denominador);
  printf("Subtração: %d/%d\n", subtracao.numerador, subtracao.denominador);
  printf("Multiplicação: %d/%d\n", multiplicacao.numerador, multiplicacao.denominador);
  printf("Divisão: %d/%d\n", divisao.numerador, divisao.denominador);
  return 0;
}