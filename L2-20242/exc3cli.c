//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc3int.h"

int main() {
    TNo *A = NULL, *B = NULL;
    int valor;

    printf("Montando a árvore A (insira valores inteiros, ou qualquer número negativo para terminar):\n");
    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor < 0) break;
        A = InsereNo(A, valor);
    }

    printf("\nMontando a árvore B (insira valores inteiros, ou qualquer número negativo para terminar):\n");
    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor < 0) break;
        B = InsereNo(B, valor);
    }

    printf("\nÁrvore A na notação textual:\n");
    ImprimeArvoreInfixa(A);
    printf("\n");

    printf("\nÁrvore B na notação textual:\n");
    ImprimeArvoreInfixa(B);
    printf("\n");

    if (SaoEquivalentes(A, B)) {
        printf("\nAs árvores A e B são equivalentes.\n");
    } else {
        printf("\nAs árvores A e B não são equivalentes.\n");
    }

    LiberaArvore(A);
    LiberaArvore(B);

    return 0;
}
