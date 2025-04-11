//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <string.h>
#include "exc1int.h"

int main() {
    Cidade* inicio = NULL;
    Cidade* fim = NULL;

    char nome[31];
    int populacao;
    float area, idh, pib;

    printf("Informe os dados das cidades ou 'FIM' para encerrar:\n");
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
        inserir_cidade(&inicio, &fim, nome, populacao, area, pib, idh);
    }

    printf("\nlista original:\n");
    imprimir_lista(inicio);
    printf("\nLista original INVERTIDA:\n");
    imprimir_lista_reversa(fim);

    float idh_exclu;
    while (1) {
        printf("\nInforme o IDH para excluir cidades (ou um valor negativo para encerrar):\n");
        scanf("%f", &idh_exclu);
        if (idh_exclu < 0) {
            break;
        }
        int encontrou = excluir_cidades(&inicio, &fim, idh_exclu);
        if (encontrou) {
            printf("znLista após exclusão:\n");
            imprimir_lista(inicio);
            printf("\nLista INVERTIDA após exclusão:\n");
            imprimir_lista_reversa(fim);
        } else {
            printf("Nenhum no com valor de IDH igual ou superior ao informado foi encontrado\n");
        }
    }

    return 0;
}