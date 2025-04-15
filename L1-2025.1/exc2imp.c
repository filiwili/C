//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exc2int.h"

Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->tamanho = 0;
    return lista;
}

int inserir_final(Lista* lista, Aluno novo) {
    if (lista->tamanho >= MAX_ALUNOS) {
        printf("Erro: Lista cheia. Não é possível adicionar mais alunos.\n");
        return 0;
    }
    lista->alunos[lista->tamanho] = novo;
    lista->tamanho++;
    return 1;
}

void imprimir_lista(Lista* lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        printf("RA: %s | Disciplina: %s | Nota: %.2f | Faltas: %d\n",
               lista->alunos[i].ra, lista->alunos[i].disciplina, lista->alunos[i].nota, lista->alunos[i].faltas);
    }
}

int remover_disciplina(Lista* lista, const char* sigla) {
    int removidos = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->alunos[i].disciplina, sigla) == 0) {
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->alunos[j] = lista->alunos[j + 1];
            }
            lista->tamanho--;
            removidos++;
            i--;
        }
    }
    return removidos;
}

int existe_disciplina(Lista* lista, const char* sigla) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->alunos[i].disciplina, sigla) == 0) {
            return 1;
        }
    }
    return 0;
}

void liberar_lista(Lista* lista) {
    free(lista);
}

void to_upper_str(char* str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32;
        }
        str++;
    }
}

int validar_ra(const char* ra) {
    if (strlen(ra) != 13) {
        printf("Erro: RA deve ter exatamente 13 caracteres.\n");
        return 0;
    }
    return 1;
}

int validar_nota(float nota) {
    if (nota < 0 || nota > 10) {
        printf("Erro: Nota deve estar entre 0 e 10.\n");
        return 0;
    }
    return 1;
}

int validar_faltas(int faltas) {
    if (faltas < 0) {
        printf("Erro: Faltas não podem ser negativas.\n");
        return 0;
    }
    return 1;
}
