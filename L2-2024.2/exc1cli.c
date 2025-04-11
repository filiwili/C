//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc1int.h"

int main(void) {
    TNo *raiz = NULL, *aux, *pai;
    int numero;

    printf("Informe uma sequência de inteiros para a árvore binária (valor negativo para encerrar):\n");
    while (1) {
        printf("Valor: ");
        scanf("%d", &numero);

        if (numero < 0)
            break;

        aux = CriaNo(numero);

        // Fazendo o encadeamento do novo nó
        pai = AchaPai(raiz, numero);
        if (pai == NULL)
            raiz = aux;
        else if (numero <= pai->valor)
            pai->esq = aux;
        else
            pai->dir = aux;
    }

    if (raiz == NULL) {
        printf("A árvore está vazia!\n");
        return 0;
    }

    printf("\n\nA árvore possui %d elementos:\n", ContaNos(raiz));
    ImprimeArvore(raiz, 0);

    printf("Soma dos valores: %d\n", SomaNos(raiz));
    printf("Quantidade de nós pares: %d\n", ContaPares(raiz));
    printf("Maior valor na árvore: %d\n", MaiorValor(raiz));
    printf("Menor valor na árvore: %d\n", MenorValor(raiz));
    printf("Quantidade de folhas: %d\n", ContaFolhas(raiz));
    printf("Altura da árvore: %d\n", Altura(raiz));

    printf("\nInforme um valor para pesquisa: ");
    scanf("%d", &numero);
    if (Busca(raiz, numero))
        printf("Valor %d encontrado na árvore!\n", numero);
    else
        printf("Valor %d não encontrado na árvore.\n", numero);

    return 0;
}
