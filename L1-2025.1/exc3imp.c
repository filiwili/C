//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc3int.h"

No* criar_lista() {
    return NULL;
}

No* inserir_final(No* lista, float valor) {
    No* no = (No*)malloc(sizeof(No));
    if (!no) {
        printf("Erro de memória!\n");
        exit(1);
    }
    no->valor = valor;
    no->prox = NULL;

    if (lista == NULL) {
        return no;
    }

    No* temp = lista;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = no;
    return lista;
}

void imprimir_lista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* temp = lista;
    while (temp != NULL) {
        printf("%.2f ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void liberar_lista(No* lista) {
    No* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

No* somar_listas(No* lista1, No* lista2) {
    No* lista_soma = NULL;
    No* temp1 = lista1;
    No* temp2 = lista2;

    while (temp1 != NULL || temp2 != NULL) {
        float soma = 0;
        if (temp1 != NULL) {
            soma += temp1->valor;
            temp1 = temp1->prox;
        }
        if (temp2 != NULL) {
            soma += temp2->valor;
            temp2 = temp2->prox;
        }

        lista_soma = inserir_final(lista_soma, soma);
    }

    return lista_soma;
}

int validar_entrada(float* valor) {
    char buffer[100];
    int valid = 0;

    while (!valid) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%f", valor) == 1) {
                if (*valor < 0) {
                    return 0;
                }
                return 1;
            }
        }

        printf("Entrada inválida. Digite um número positivo.\n");
    }
    return 0;
}
