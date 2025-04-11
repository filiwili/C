//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc4int.h"

TNo *AchaPai(TNo *r, int n)
{ 
    if (r == NULL)
        return NULL;
    else if (n <= r->valor)
        if (r->esq == NULL)
            return r;
        else
            return AchaPai(r->esq, n);
    else
        if (r->dir == NULL)
            return r;
        else
            return AchaPai(r->dir, n);
}

void ImprimeArvore(TNo *r, int n)
{ 
    int c;
    
    if (r != NULL)
    {   
        for (c = 0; c < n; c++) 
            printf("   ");
        printf("%d\n", r->valor);

        ImprimeArvore(r->esq, n + 1);
        ImprimeArvore(r->dir, n + 1);
    }
}

int SomaNos(TNo *r)
{ 
    if (r == NULL)
        return 0;
    else
        return r->valor + SomaNos(r->esq) + SomaNos(r->dir);
}

int ContaNos(TNo *r)
{ 
    if (r == NULL)
        return 0;
    else
        return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

int ContaPares(TNo *r)
{ 
    if (r == NULL)
        return 0;
    else
        if (r->valor % 2 == 0)
            return 1 + ContaPares(r->esq) + ContaPares(r->dir);
        else
            return ContaPares(r->esq) + ContaPares(r->dir);
}

void LiberaArvore(TNo *r)
{
    if (r != NULL)
    {
        LiberaArvore(r->esq);
        LiberaArvore(r->dir);
        free(r);
    }
}
