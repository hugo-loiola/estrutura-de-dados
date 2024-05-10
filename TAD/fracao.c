#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Num;
    int Den;
} Fracao;

Fracao criarFracao(int N, int D);

int main()
{
    Fracao X = criarFracao(2, 4);
    return 0;
}

Fracao criarFracao(int N, int D) // Analogia ao método construtor do java
{
    Fracao f;
    f.Num = N;
    f.Den = D;
    return (f);
}