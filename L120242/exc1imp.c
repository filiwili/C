//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc1int.h"

void inserir_cidade(Cidade** inicio, Cidade** fim, char* nome, int populacao, float area, float pib, float idh) {
    Cidade* nova_cidade = (Cidade*) malloc(sizeof(Cidade));
    strcpy(nova_cidade->nome, nome);
    nova_cidade->populacao = populacao;
    nova_cidade->area = area;
    nova_cidade->pib = pib;
    nova_cidade->idh = idh;
    nova_cidade->prox = NULL;
    nova_cidade->ant = NULL;

    if (*inicio == NULL) {
        *inicio = nova_cidade;
        *fim = nova_cidade;
    } else {
        (*fim)->prox = nova_cidade;
        nova_cidade->ant = *fim;
        *fim = nova_cidade;
    }
}

void imprimir_lista(Cidade* inicio) {
    while (inicio != NULL) {
        printf("Cidade: %s, População: %d, Área: %.2f, PIB: %.2f, IDH: %.2f\n",
               inicio->nome, inicio->populacao, inicio->area, inicio->pib, inicio->idh);
        inicio = inicio->prox;
    }
}

void imprimir_lista_reversa(Cidade* fim) {
    while (fim != NULL) {
        printf("Cidade: %s, População: %d, Área: %.2f, PIB: %.2f, IDH: %.2f\n",
               fim->nome, fim->populacao, fim->area, fim->pib, fim->idh);
        fim = fim->ant;
    }
}

int excluir_cidades(Cidade** inicio, Cidade** fim, float idh) {
    Cidade* atual = *inicio;
    Cidade* proximo;
    int encontrou = 0;

    while (atual != NULL) {
        proximo = atual->prox;
        if (atual->idh >= idh) {
            encontrou = 1;
            if (atual == *inicio) {
                *inicio = proximo;
                if (*inicio == NULL) {
                    *fim = NULL;
                } else {
                    (*inicio)->ant = NULL;
                }
            } else {
                atual->ant->prox = proximo;
                if (proximo != NULL) {
                    proximo->ant = atual->ant;
                } else {
                    *fim = atual->ant;
                }
            }
            free(atual);
        }
        atual = proximo;
    }
    return encontrou; // Adicionei o return aqui
}