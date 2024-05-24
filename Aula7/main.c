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

    free(A->Array);
    free(A);
    return 0;
}