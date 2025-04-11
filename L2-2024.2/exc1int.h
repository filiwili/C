//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC1INT_H
#define EXC1INT_H

typedef struct regNo {
    struct regNo* esq;
    int valor;
    struct regNo* dir;
} TNo;

TNo* AchaPai(TNo* r, int n);
TNo* CriaNo(int valor);
void ImprimeArvore(TNo* r, int n);
int ContaNos(TNo* r);
int SomaNos(TNo* r);
int ContaPares(TNo* r);

int MaiorValor(TNo* r);
int MenorValor(TNo* r);
int ContaFolhas(TNo* r);
int Altura(TNo* r);
int Busca(TNo* r, int valor);

#endif
