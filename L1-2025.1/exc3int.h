//FILIPE DE MOURA AFFONSO
#ifndef EXC3INT_H
#define EXC3INT_H

typedef struct no {
    float valor;
    struct no* prox;
} No;

No* criar_lista();
No* inserir_final(No* lista, float valor);
void imprimir_lista(No* lista);
void liberar_lista(No* lista);
No* somar_listas(No* lista1, No* lista2);
int validar_entrada(float* valor);

#endif
