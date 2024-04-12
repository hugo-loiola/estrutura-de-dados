#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
    char Nome[50];
    int Quantidade;
    float Preco;

} Produto;

int main()
{
    FILE *fp;
    FILE *html;
    Produto X;
    float Total = 0.0;

    fp = fopen("dados.txt", "r");
    html = fopen("resultado.html", "w"); // "r" abre o arquivo para leitura
    if (fp == NULL || html == NULL)
    {
        printf("O arquivo nao pode ser aberto!\n");
        exit(1);
    }

    fprintf(html, "<table>\n");

    fprintf(html, "<tr>Nome</tr>");

    fprintf(html, "<tr>Quantidade</tr>");

    fprintf(html, "<tr>Preco</tr>");

    fprintf(html, "<tr>Subtotal</tr>");

    while (fscanf(fp, "%s %d %f", X.Nome, &X.Quantidade, &X.Preco) != EOF)
    {
        float Subtotal = X.Quantidade * X.Preco;
        fprintf(html, "<tr>\n");

        fprintf(html, "<td>%s</td>", X.Nome);

        fprintf(html, "<td>%d</td>", X.Quantidade);

        fprintf(html, "<td>%.2f</td>", X.Preco);

        fprintf(html, "<td>%.2f</td>", Subtotal);

        fprintf(html, "</tr>\n");

        Total = Total + Subtotal;
    }

    printf("Valor total: %.2f\n", Total);
    fprintf(html, "</table>\n");
    fclose(fp);

    return 0;
}