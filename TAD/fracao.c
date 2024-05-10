#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Num;
    int Den;
} Fracao;
// Funçoes
Fracao criarFracao(int N, int D);
float calcularDecimal(Fracao f);
Fracao somarFracoes(Fracao f, Fracao g);
Fracao subtrairFracao(Fracao f, Fracao g);
void mostrarFracao(Fracao f);

int main()
{
    Fracao X = criarFracao(5, 6);
    Fracao Y = criarFracao(4, 9);
    Fracao Soma = somarFracoes(X, Y);
    mostrarFracao(Soma);
    return 0;
}

Fracao criarFracao(int N, int D) // Analogia ao método construtor do java
{
    Fracao f;
    f.Num = N;
    f.Den = D;
    return (f);
}

float calcularDecimal(Fracao f)
{
    return (f.Num / f.Den);
}

Fracao somarFracoes(Fracao f, Fracao g)
{
    Fracao R;
    R.Num = (f.Num * g.Den) + (g.Num * f.Den);
    R.Den = f.Den * g.Den;
    return (R);
}

Fracao subtrairFracao(Fracao f, Fracao g)
{
    Fracao R;
    R.Num = (f.Num * g.Den) - (g.Num * f.Den);
    R.Den = f.Den * g.Den;
    return (R);
}

void mostrarFracao(Fracao f)
{
    printf("%d/%d", f.Num, f.Den);
}