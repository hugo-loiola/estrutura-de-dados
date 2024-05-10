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

Fracao multiplicarFracao(Fracao f, Fracao g);

Fracao dividirFracao(Fracao f, Fracao g);

void mostrarFracao(Fracao f);

// Main
int main()
{
    Fracao X = criarFracao(3, 4);
    Fracao Y = criarFracao(1, 4);
    Fracao Soma = somarFracoes(X, Y);
    Fracao Subtracao = subtrairFracao(X, Y);
    Fracao Multiplicacao = multiplicarFracao(X, Y);
    Fracao Divisao = dividirFracao(X, Y);
    mostrarFracao(Soma);
    mostrarFracao(Subtracao);
    mostrarFracao(Multiplicacao);
    mostrarFracao(Divisao);

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

    if (f.Den != g.Den)
    {
        R.Num = (f.Num * g.Den) + (g.Num * f.Den);
        R.Den = f.Den * g.Den;
    }
    else
    {
        R.Num = f.Num + g.Num;
        R.Den = f.Den;
    }
    return (R);
}

Fracao subtrairFracao(Fracao f, Fracao g)
{
    Fracao R;

    if (g.Den != f.Den)
    {
        R.Num = (f.Num * g.Den) - (g.Num * f.Den);
        R.Den = f.Den * g.Den;
    }
    else
    {
        R.Num = f.Num - g.Num;
        R.Den = f.Den;
    }
    return (R);
}

Fracao multiplicarFracao(Fracao f, Fracao g)
{
    Fracao R;
    R.Num = f.Num * g.Num;
    R.Den = f.Den * g.Den;
    return (R);
}

Fracao dividirFracao(Fracao f, Fracao g)
{
    Fracao R;
    R.Num = f.Num * g.Den;
    R.Den = f.Den * g.Num;
    return (R);
}

void mostrarFracao(Fracao f)
{
    printf("%d/%d\n", f.Num, f.Den);
}