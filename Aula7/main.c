#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *A = criarLista(10);

    printf("Teste N°1\n");
    printf("O tamanho da lista é %d\n", A->Capacidade);
    free(A->Array);
    free(A);
    return 0;
}