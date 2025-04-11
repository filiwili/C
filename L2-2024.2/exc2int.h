//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC2INT_H
#define EXC2INT_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} TNo;

TNo* CriaNo(int valor);
TNo* InsereNo(TNo *raiz, int valor);
void ImprimeArvoreInfixa(TNo *raiz);

#endif
