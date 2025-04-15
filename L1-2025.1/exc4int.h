//FILIPE DE MOURA AFFONSO
#ifndef EXC4INT_H
#define EXC4INT_H

#define MAX_LEN 20

typedef struct pilha {
    char dados[MAX_LEN];
    int topo;
} Pilha;

void inicializar_pilha(Pilha* p);
int pilha_vazia(Pilha* p);
int pilha_cheia(Pilha* p);
void empilhar(Pilha* p, char c);
char desempilhar(Pilha* p);
int verificar_palindromo(const char* palavra);
int palavra_valida(const char* palavra);

#endif
