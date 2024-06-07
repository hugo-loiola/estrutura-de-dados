# Estrada de Wakanda

### Entrada

### Saída

### Restrições

### Exemplo

### Arquivo cidades.h
```c
#ifndef CIDADES_H
#define CIDADES_H

typedef struct
{
    char Nome[256]; // Nome da cidade
    int Posicao;    // Posição da cidade
} Cidade;

typedef struct
{
    int N; // Número de cidades
    int T; // Comprimento da estrada
    Cidade *C; // Vetor de cidades
} Estrada;

Estrada *getEstrada(const char *nomeArquivo); // Inicializa cidades no TAD indicado acima
double calcularMenorVizinhanca(const char *nomeArquivo); // Retorna a menor vizinhanca
char *cidadeMenorVizinhanca(const char *nomeArquivo); // Retorna a cidade que tem menor vizinhanca

#endif
```
### Observação