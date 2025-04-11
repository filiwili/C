//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO 20

typedef struct {
    char delimitador;
} Elemento;

typedef struct {
    Elemento* elementos;
    int topo;
    int capacidade;
} Pilha;

void criarPilha(Pilha* pilha, int capacidade) {
    pilha->elementos = (Elemento*) malloc(capacidade * sizeof(Elemento));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

void empilhar(Pilha* pilha, char delimitador) {
    if (pilha->topo < pilha->capacidade - 1) {
        pilha->elementos[++pilha->topo].delimitador = delimitador;
    } else {
        printf("Pilha cheia!\n");
        exit(1);
    }
}

char desempilhar(Pilha* pilha) {
    if (pilha->topo >= 0) {
        return pilha->elementos[pilha->topo--].delimitador;
    } else {
        printf("Pilha vazia!\n");
        exit(1);
    }
}

int verificarDelimitadores(char delimitadorAbertura, char delimitadorFechamento) {
    if ((delimitadorAbertura == '(' && delimitadorFechamento == ')') ||
        (delimitadorAbertura == '[' && delimitadorFechamento == ']') ||
        (delimitadorAbertura == '{' && delimitadorFechamento == '}')) {
        return 1;
    } else {
        return 0;
    }
}

int verificarExpressao(char* expressao) {
    Pilha pilha;
    criarPilha(&pilha, MAX_TAMANHO);

    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(&pilha, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (pilha.topo < 0) {
                printf("Expressão inválida!\n");
                return 0;
            }
            char delimitadorAbertura = desempilhar(&pilha);
            if (!verificarDelimitadores(delimitadorAbertura, expressao[i])) {
                printf("Expressão inválida!\n");
                return 0;
            }
        }
    }

    if (pilha.topo < 0) {
        printf("Expressão válida!\n");
        return 1;
    } else {
        printf("Expressão inválida!\n");
        return 0;
    }
}

int main() {
    char expressao[MAX_TAMANHO + 1];

    printf("Digite uma expressão aritmética: ");
    fgets(expressao, MAX_TAMANHO + 1, stdin);
    expressao[strlen(expressao) - 1] = '\0'; // remover o caractere de nova linha

    verificarExpressao(expressao);

    return 0;
}