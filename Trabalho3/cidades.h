#ifndef CIDADES_H
#define CIDADES_H

typedef struct
{
    char Nome[256]; // Nome da cidade
    int Posicao;    // Posição da cidade
} Cidade;

typedef struct
{
    int N;
    int T;
    Cidade *C;
} Estrada;

Estrada *getEstrada(const char *nomeArquivo);
double calcularMenorVizinhanca(const char *nomeArquivo);
char *cidadeMenorVizinhanca(const char *nomeArquivo);

#endif