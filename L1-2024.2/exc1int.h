//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC1INT_H
#define EXC1INT_H

typedef struct cidade {
    char nome[31];
    int populacao;
    float area, pib, idh;
    struct cidade* prox;
    struct cidade* ant;
} Cidade;

void inserir_cidade(Cidade** inicio, Cidade** fim, char* nome, int populacao, float area, float pib, float idh);
void imprimir_lista(Cidade* inicio);
void imprimir_lista_reversa(Cidade* fim);
int excluir_cidades(Cidade** inicio, Cidade** fim, float idh);

#endif