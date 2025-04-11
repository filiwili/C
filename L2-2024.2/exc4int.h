//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC4INT_H
#define EXC4INT_H

struct regNo
{  
    struct regNo *esq;
    int valor;
    struct regNo *dir;
};

typedef struct regNo TNo;

TNo *AchaPai(TNo *r, int n);
void ImprimeArvore(TNo *r, int n);
int SomaNos(TNo *r);
int ContaNos(TNo *r);
int ContaPares(TNo *r);
void LiberaArvore(TNo *r);

#endif
