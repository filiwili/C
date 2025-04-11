//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC3INT_H
#define EXC3INT_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} TNo;

TNo* CriaNo(int valor);

TNo* InsereNo(TNo* raiz, int valor);

void LiberaArvore(TNo* raiz);

int SaoEquivalentes(TNo* A, TNo* B);

void ImprimeArvoreInfixa(TNo* raiz);

#endif
