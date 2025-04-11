//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <string.h>
#include "exc2int.h"

int main() {
    ListaCidades lista;
    criar_lista(&lista, 100);

    char nome[31];
    int populacao;
    float area, idh, pib;

    printf("Informe os dados das cidades ou 'FIM' para encerrar):\n");
    while (1) {
        printf("Nome: ");
        scanf("%30s", nome);
        if (strcasecmp(nome, "FIM") == 0) {
            break;
        }
        printf("População: ");
        scanf("%d", &populacao);
        printf("Área: ");
        scanf("%f", &area);
        printf("PIB: ");
        scanf("%f", &pib);
        printf("IDH: ");
        scanf("%f", &idh);
        inserir_cidade(&lista, nome, populacao, area, pib, idh);
    }

    printf("\nLista original:\n");
    imprimir_lista(&lista);
    printf("\nLista original INVERTIDA:\n");
    imprimir_lista_reversa(&lista);

    float idh_exclu;
    while (1) {
        printf("\nInforme o IDH para excluir cidades (ou um valor negativo para encerrar):\n");
        scanf("%f", &idh_exclu);
        if (idh_exclu < 0) {
            break;
        }
        int encontrou = excluir_cidades(&lista, idh_exclu);
        if (encontrou) {
            printf("\nLista após exclusão:\n");
            imprimir_lista(&lista);
            printf("\nLista INVERTIDA após exclusão:\n");
            imprimir_lista_reversa(&lista);
        } else {
            printf("Nenhum nó com valor de IDH igual ou superior ao informado foi encontrado\n");
        }
    }

    return 0;
}