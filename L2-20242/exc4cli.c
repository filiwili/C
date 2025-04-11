//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc4int.h"

int main(void)
{   
    TNo *raiz = NULL, *aux, *pai;
    int numero;

    printf("Montando a árvore (insira valores inteiros, ou qualquer número negativo para terminar):\n");
    while (1)
    {   
        printf("Valor: ");
        scanf("%d", &numero);

        if (numero < 0) 
            break;

        aux = (TNo *) malloc(sizeof(TNo));
        aux->valor = numero;
        aux->dir = NULL;
        aux->esq = NULL;

        pai = AchaPai(raiz, numero);
        if (pai == NULL)
            raiz = aux;
        else
            if (numero <= pai->valor)
                pai->esq = aux;
            else
                pai->dir = aux;
    }

    if (raiz != NULL)
    {
        printf("\n\nA árvore possui %d elementos:\n", ContaNos(raiz));
        ImprimeArvore(raiz, 0);

        printf("\nSoma: %d\n", SomaNos(raiz));
        printf("Qtde nós pares: %d\n", ContaPares(raiz));

        char resposta;
        printf("\nDeseja eliminar todos os nós da árvore (s/n)? \n");
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S')
        {
            LiberaArvore(raiz);
            printf("\nÁrvore liberada da memória.\n");
        }
        else
        {
            printf("\nA árvore não foi alterada.\n");
        }
    }
    else
    {
        printf("\nNenhum nó foi inserido na árvore.\n");
    }

    return 0;
}
