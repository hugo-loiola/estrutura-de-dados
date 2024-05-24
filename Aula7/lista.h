#ifndef LISTA
#define LISTA
#define ERRO_MEMORIA 1

typedef struct
{
    int Chave;
} Item;

typedef struct
{
    int Tamanho;
    int Capacidade;
    Item *Array;

} Lista;

Lista *criarLista(int N);

void inserirItem(Lista *L, Item E);

void exibirLista(Lista *L);

void excluirItemFinal(Lista *L);

void excluirItem(Lista *L, int Posicao);
#endif