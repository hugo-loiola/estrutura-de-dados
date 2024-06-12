#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cidades.h"

Estrada *getEstrada(const char *nomeArquivo)
{
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    int T, N;
    fscanf(file, "%d", &T);
    fscanf(file, "%d", &N);

    if (T < 3 || T > 1000000 || N < 2 || N > 10000)
    {
        fclose(file);
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (estrada == NULL)
    {
        perror("Erro ao alocar memória para estrada");
        fclose(file);
        return NULL;
    }

    estrada->T = T;
    estrada->N = N;
    estrada->C = (Cidade *)malloc(N * sizeof(Cidade));
    if (estrada->C == NULL)
    {
        perror("Erro ao alocar memória para cidades");
        free(estrada);
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < N; i++)
    {
        fscanf(file, "%d", &(estrada->C[i].Posicao));
        if (estrada->C[i].Posicao <= 0 || estrada->C[i].Posicao >= T)
        {
            free(estrada->C);
            free(estrada);
            fclose(file);
            return NULL;
        }
        fscanf(file, "%s", estrada->C[i].Nome);
        for (int j = 0; j < i; j++)
        {
            if (estrada->C[i].Posicao == estrada->C[j].Posicao)
            {
                free(estrada->C);
                free(estrada);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo)
{
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL)
    {
        return -1.0; // Erro ao ler o arquivo ou validação falhou
    }

    double menorVizinhanca = estrada->T;
    for (int i = 0; i < estrada->N; i++)
    {
        double vizinhanca = estrada->T;
        for (int j = 0; j < estrada->N; j++)
        {
            if (i != j)
            {
                double distancia = fabs(estrada->C[i].Posicao - estrada->C[j].Posicao) / 2.0;
                if (distancia < vizinhanca)
                {
                    vizinhanca = distancia;
                }
            }
        }
        if (vizinhanca < menorVizinhanca)
        {
            menorVizinhanca = vizinhanca;
        }
    }

    free(estrada->C);
    free(estrada);

    return menorVizinhanca;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo)
{
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL)
    {
        return NULL; // Erro ao ler o arquivo ou validação falhou
    }

    double menorVizinhanca = estrada->T;
    char *cidade = (char *)malloc(256 * sizeof(char));
    if (cidade == NULL)
    {
        perror("Erro ao alocar memória para o nome da cidade");
        free(estrada->C);
        free(estrada);
        return NULL;
    }

    for (int i = 0; i < estrada->N; i++)
    {
        double vizinhanca = estrada->T;
        for (int j = 0; j < estrada->N; j++)
        {
            if (i != j)
            {
                double distancia = fabs(estrada->C[i].Posicao - estrada->C[j].Posicao) / 2.0;
                if (distancia < vizinhanca)
                {
                    vizinhanca = distancia;
                }
            }
        }
        if (vizinhanca < menorVizinhanca)
        {
            menorVizinhanca = vizinhanca;
            strcpy(cidade, estrada->C[i].Nome);
        }
    }

    free(estrada->C);
    free(estrada);

    return cidade;
}
