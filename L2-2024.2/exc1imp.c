//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc1int.h"

TNo* CriaNo(int valor) {
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

TNo* AchaPai(TNo* r, int n) {
    if (r == NULL) return NULL;
    if (n <= r->valor)
        return (r->esq == NULL) ? r : AchaPai(r->esq, n);
    else
        return (r->dir == NULL) ? r : AchaPai(r->dir, n);
}

void ImprimeArvore(TNo* r, int n) {
    if (r != NULL) {
        for (int i = 0; i < n; i++) printf("   ");
        printf("%d\n", r->valor);
        ImprimeArvore(r->esq, n + 1);
        ImprimeArvore(r->dir, n + 1);
    }
}

int ContaNos(TNo* r) {
    return (r == NULL) ? 0 : 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

int SomaNos(TNo* r) {
    return (r == NULL) ? 0 : r->valor + SomaNos(r->esq) + SomaNos(r->dir);
}

int ContaPares(TNo* r) {
    if (r == NULL) return 0;
    return ((r->valor % 2 == 0) ? 1 : 0) + ContaPares(r->esq) + ContaPares(r->dir);
}

int MaiorValor(TNo* r) {
    if (r == NULL) return -1;
    while (r->dir != NULL) r = r->dir;
    return r->valor;
}

int MenorValor(TNo* r) {
    if (r == NULL) return -1;
    while (r->esq != NULL) r = r->esq;
    return r->valor;
}

int ContaFolhas(TNo* r) {
    if (r == NULL) return 0;
    if (r->esq == NULL && r->dir == NULL) return 1;
    return ContaFolhas(r->esq) + ContaFolhas(r->dir);
}

int Altura(TNo* r) {
    if (r == NULL) return -1;
    int altEsq = Altura(r->esq);
    int altDir = Altura(r->dir);
    return 1 + ((altEsq > altDir) ? altEsq : altDir);
}

int Busca(TNo* r, int valor) {
    if (r == NULL) return 0;
    if (r->valor == valor) return 1;
    return (valor < r->valor) ? Busca(r->esq, valor) : Busca(r->dir, valor);
}
