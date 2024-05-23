//
// Created by hugo on 22/05/24.
//

#ifndef FRACAO
#define FRACAO

typedef struct
{
  int numerador;
  int denominador;
} Fracao;

Fracao criarFracao(int numerador, int denominador);

Fracao somarFracao(Fracao a, Fracao b);

Fracao subtrairFracao(Fracao a, Fracao b);

Fracao multiplicarFracao(Fracao a, Fracao b);

Fracao dividirFracao(Fracao a, Fracao b);

Fracao simplificarFracao(Fracao f);

int mdc(int a, int b);

#endif // FRACAO