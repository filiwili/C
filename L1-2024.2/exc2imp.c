//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc2int.h"

void criar_lista(ListaCidades* lista, int capacidade) {
    lista->cidades = (Cidade*) malloc(capacidade * sizeof(Cidade));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void inserir_cidade(ListaCidades* lista, char* nome, int populacao, float area, float pib, float idh) {
    if (lista->tamanho < lista->capacidade) {
        strcpy(lista->cidades[lista->tamanho].nome, nome);
        lista->cidades[lista->tamanho].populacao = populacao;
        lista->cidades[lista->tamanho].area = area;
        lista->cidades[lista->tamanho].pib = pib;
        lista->cidades[lista->tamanho].idh = idh;
        lista->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

void imprimir_lista(ListaCidades* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Cidade: %s, População: %d, Área: %.2f, PIB: %.2f, IDH: %.2f\n",
               lista->cidades[i].nome, lista->cidades[i].populacao, lista->cidades[i].area, lista->cidades[i].pib, lista->cidades[i].idh);
    }
}

void imprimir_lista_reversa(ListaCidades* lista) {
    for (int i = lista->tamanho - 1; i >= 0; i--) {
        printf("Cidade: %s, População: %d, Área: %.2f, PIB: %.2f, IDH: %.2f\n",
               lista->cidades[i].nome, lista->cidades[i].populacao, lista->cidades[i].area, lista->cidades[i].pib, lista->cidades[i].idh);
    }
}

int excluir_cidades(ListaCidades* lista, float idh) {
    int encontrou = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->cidades[i].idh >= idh) {
            encontrou = 1;
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->cidades[j] = lista->cidades[j + 1];
            }
            lista->tamanho--;
            i--;
        }
    }
    return encontrou;
}