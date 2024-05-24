#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *A = criarLista(10);

    printf("Teste N°1:\n");
    printf("O tamanho da lista é %d\n", A->Capacidade);

    printf("Teste N°2:\n");
    printf("Inserindo elementos na lista\n");
    Item E1 = {123};
    inserirItem(A, E1);
    Item E2 = {65};
    inserirItem(A, E2);
    Item E3 = {78};
    inserirItem(A, E3);
    Item E4 = {4};
    inserirItem(A, E4);
    Item E5 = {23};
    inserirItem(A, E5);
    printf("O tamanho da lista passou a ser %d.\n", A->Tamanho);

    printf("Teste N°3:\n");
    printf("Exibindo elementos da lista:\n");

    exibirLista(A);

    printf("Teste N°4:\n");
    printf("Inserindo em uma forma diferente:\n");
    inserirItem(A, (Item){88});
    exibirLista(A);

    printf("Teste N°5:\n");
    printf("Excluindo o último elemento:\n");
    excluirItemFinal(A);
    exibirLista(A);

    printf("Teste N°6:\n");
    printf("Excluindo um elemento específico na lista:\n");
    excluirItem(A, 0);
    exibirLista(A);

    // Liberar na memória o array
    free(A->Array);
    free(A);
    return 0;
}