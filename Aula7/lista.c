#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criarLista(int N)
{
    Lista *L = (Lista *)malloc(sizeof(Lista));
    if (L == NULL)
    {
        printf("ERRO: não foi possível alocar memória para a moldura da lista!\n ");
        exit(ERRO_MEMORIA);
    }

    L->Array = (Item *)malloc(N * sizeof(Item));
    if (L->Array == NULL)
    {
        printf("ERRO: não foi possível alocar memória para o vetor de itens\n ");
        free(L);
        exit(ERRO_MEMORIA);
    }
    L->Capacidade = N;
    L->Tamanho = 0;

    return L;
}

void inserirItem(Lista *L, Item E)
{
    if (L->Tamanho == L->Capacidade)
    {
        printf("ERRO: A lista está cheia!\n");
        return;
    }
    L->Array[L->Tamanho] = E;
    L->Tamanho++;
}

void exibirLista(Lista *L)
{
    for (int i = 0; i < L->Tamanho; i++)
    {
        printf("%d ", L->Array[i].Chave);
    }
}

void excluirItemFinal(Lista *L)
{
    L->Tamanho--;
}

void excluirItem(Lista *L, int Posicao)
{
    if (Posicao < 0 || Posicao >= L->Tamanho)
    {
        printf("ERRO: A posição a ser excluida é invalida!\n");
        return;
    }
    for (int i = Posicao; i < L->Tamanho; i++)
    {
        L->Array[i] = L->Array[i + 1];
    }
    L->Tamanho--;
}