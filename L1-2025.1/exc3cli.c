//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include "exc3int.h"

int main() {
    No* lista1 = criar_lista();
    No* lista2 = criar_lista();
    No* lista_soma = NULL;
    float valor;

    printf("Informe os valores para a Lista 1 (valor negativo encerra):\n");
    while (1) {
        printf("Digite um valor: ");
        if (!validar_entrada(&valor)) {
            break;
        }
        lista1 = inserir_final(lista1, valor);
    }

    printf("Informe os valores para a Lista 2 (valor negativo encerra):\n");
    while (1) {
        printf("Digite um valor: ");
        if (!validar_entrada(&valor)) {
            break;
        }
        lista2 = inserir_final(lista2, valor);
    }

    printf("\nLista 1: ");
    imprimir_lista(lista1);
    printf("Lista 2: ");
    imprimir_lista(lista2);

    lista_soma = somar_listas(lista1, lista2);

    printf("\nLista 3 (Soma das listas 1 e 2): ");
    imprimir_lista(lista_soma);

    liberar_lista(lista1);
    liberar_lista(lista2);
    liberar_lista(lista_soma);

    printf("\nPrograma encerrado.\n");
    return 0;
}
