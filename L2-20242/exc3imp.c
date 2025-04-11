//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc3int.h"

TNo* CriaNo(int valor) {
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    if (novo) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

TNo* InsereNo(TNo* raiz, int valor) {
    if (raiz == NULL) {
        return CriaNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = InsereNo(raiz->esq, valor);
    } else {
        raiz->dir = InsereNo(raiz->dir, valor);
    }
    return raiz;
}

void LiberaArvore(TNo* raiz) {
    if (raiz) {
        LiberaArvore(raiz->esq);
        LiberaArvore(raiz->dir);
        free(raiz);
    }
}

int SaoEquivalentes(TNo* A, TNo* B) {
    if (A == NULL && B == NULL) {
        return 1;
    }
    if (A == NULL || B == NULL) {
        return 0;
    }
	
    return (A->valor == B->valor) &&
           SaoEquivalentes(A->esq, B->esq) &&
           SaoEquivalentes(A->dir, B->dir);
}

void ImprimeArvoreInfixa(TNo* raiz) {
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
