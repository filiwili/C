//FILIPE DE MOURA AFFONSO
#include <string.h>
#include <ctype.h>
#include "exc4int.h"

void inicializar_pilha(Pilha* p) {
    p->topo = -1;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha* p) {
    return p->topo == MAX_LEN - 1;
}

void empilhar(Pilha* p, char c) {
    if (!pilha_cheia(p)) {
        p->dados[++(p->topo)] = c;
    }
}

char desempilhar(Pilha* p) {
    if (!pilha_vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return '\0';
}

int palavra_valida(const char* palavra) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (!isalpha((unsigned char)palavra[i])) {
            return 0;
        }
    }
    return 1;
}

int verificar_palindromo(const char* palavra) {
    Pilha p;
    inicializar_pilha(&p);
    int len = strlen(palavra);
    int meio = len / 2;
    for (int i = 0; i < meio; i++) {
        empilhar(&p, tolower(palavra[i]));
    }
    for (int i = (len % 2 == 0 ? meio : meio + 1); i < len; i++) {
        if (tolower(palavra[i]) != desempilhar(&p)) {
            return 0;
        }
    }
    return pilha_vazia(&p);
}
