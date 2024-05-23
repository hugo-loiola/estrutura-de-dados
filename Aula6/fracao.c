//
// Created by hugo on 22/05/24.
//
#include <stdio.h>
#include "fracao.h"

Fracao criarFracao(int numerador, int denominador)
{
    Fracao f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;
}

// Função para somar duas frações
Fracao somarFracao(Fracao a, Fracao b)
{
    Fracao resultado;
    resultado.numerador = (a.numerador * b.denominador) + (b.numerador * a.denominador);
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

// Função para subtrair duas frações
Fracao subtrairFracao(Fracao a, Fracao b)
{
    Fracao resultado;
    resultado.numerador = (a.numerador * b.denominador) - (b.numerador * a.denominador);
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

// Função para multiplicar duas frações
Fracao multiplicarFracao(Fracao a, Fracao b)
{
    Fracao resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

// Função para dividir duas frações
Fracao dividirFracao(Fracao a, Fracao b)
{
    Fracao resultado;
    resultado.numerador = a.numerador * b.denominador;
    resultado.denominador = a.denominador * b.numerador;
    return resultado;
}

// Função para simplificar uma fração
Fracao simplificarFracao(Fracao f)
{
    int gcd = mdc(f.numerador, f.denominador);
    f.numerador /= gcd;
    f.denominador /= gcd;
    return f;
}

// Função para calcular o máximo divisor comum (MDG) de dois números
int mdc(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}