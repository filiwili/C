//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc2int.h"

TNo* CriaNo(int valor) {
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TNo* InsereNo(TNo *raiz, int valor) {
    if (raiz == NULL) {
        return CriaNo(valor);
    }
    if (valor <= raiz->valor) {
        raiz->esq = InsereNo(raiz->esq, valor);
    } else {
        raiz->dir = InsereNo(raiz->dir, valor);
    }
    return raiz;
}

void ImprimeArvoreInfixa(TNo *raiz) {
    if (raiz == NULL) {
        printf("<>");
        return;
    }
    printf("<");
    ImprimeArvoreInfixa(raiz->esq);
    printf("%d", raiz->valor);
    ImprimeArvoreInfixa(raiz->dir);
    printf(">");
}
