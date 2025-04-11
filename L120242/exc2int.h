//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#ifndef EXC2INT_H
#define EXC2INT_H

typedef struct cidade {
    char nome[31];
    int populacao;
    float area, pib, idh;
} Cidade;

typedef struct {
    Cidade* cidades;
    int tamanho;
    int capacidade;
} ListaCidades;

void criar_lista(ListaCidades* lista, int capacidade);
void inserir_cidade(ListaCidades* lista, char* nome, int populacao, float area, float pib, float idh);
void imprimir_lista(ListaCidades* lista);
void imprimir_lista_reversa(ListaCidades* lista);
int excluir_cidades(ListaCidades* lista, float idh);

#endif