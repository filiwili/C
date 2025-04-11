//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc2int.h"

int main() {
    TNo *raiz = NULL;
    int valor;

    printf("Informe uma sequência de inteiros para a árvore binária (valor negativo para encerrar):\n");

    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor < 0) {
            break;
        }
        raiz = InsereNo(raiz, valor);
    }

    printf("\nÁrvore na notação textual (infixa):\n");
    ImprimeArvoreInfixa(raiz);
    printf("\n");

    return 0;
}
