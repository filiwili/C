//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exc1int.h"

Aluno* criar_lista() {
    return NULL;
}

Aluno* inserir_final(Aluno* lista, Aluno novo) {
    Aluno* no = (Aluno*)malloc(sizeof(Aluno));
    if (!no) {
        printf("Erro de memória!\n");
        exit(1);
    }
    *no = novo;
    no->prox = NULL;

    if (lista == NULL) {
        return no;
    }

    Aluno* temp = lista;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = no;
    return lista;
}

void imprimir_lista(Aluno* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Aluno* temp = lista;
    while (temp != NULL) {
        printf("RA: %s | Disciplina: %s | Nota: %.2f | Faltas: %d\n",
               temp->ra, temp->disciplina, temp->nota, temp->faltas);
        temp = temp->prox;
    }
}

Aluno* remover_disciplina(Aluno* lista, const char* sigla, int* removidos) {
    Aluno* atual = lista;
    Aluno* anterior = NULL;
    *removidos = 0;

    while (atual != NULL) {
        if (strcmp(atual->disciplina, sigla) == 0) {
            Aluno* temp = atual;
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            atual = atual->prox;
            free(temp);
            (*removidos)++;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    return lista;
}

int existe_disciplina(Aluno* lista, const char* sigla) {
    while (lista != NULL) {
        if (strcmp(lista->disciplina, sigla) == 0) {
            return 1;
        }
        lista = lista->prox;
    }
    return 0;
}

void liberar_lista(Aluno* lista) {
    while (lista != NULL) {
        Aluno* temp = lista;
        lista = lista->prox;
        free(temp);
    }
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
