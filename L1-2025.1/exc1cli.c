//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exc1int.h"

int main() {
    Aluno* lista = criar_lista();
    Aluno a;
    char buffer[100];

    printf("Cadastro de alunos (RA = XXX encerra):\n");

    while (1) {
        printf("\nInforme o RA: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "XXX") == 0)
            break;

        if (!validar_ra(buffer)) continue;
        strncpy(a.ra, buffer, RA_TAM);
        a.ra[RA_TAM - 1] = '\0';

        printf("Informe a disciplina: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        to_upper_str(buffer);
        strncpy(a.disciplina, buffer, DISC_TAM);
        a.disciplina[DISC_TAM - 1] = '\0';

        printf("Informe a nota: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%f", &a.nota);

        printf("Informe as faltas: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &a.faltas);

        if (validar_nota(a.nota) && validar_faltas(a.faltas)) {
            lista = inserir_final(lista, a);
        }
    }

    printf("\n--- Lista original ---\n");
    imprimir_lista(lista);

    char sigla[DISC_TAM];

    while (1) {
        printf("\nDigite sigla da disciplina para remover (XXX para sair): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        to_upper_str(buffer);

        if (strcmp(buffer, "XXX") == 0)
            break;

        strncpy(sigla, buffer, DISC_TAM);
        sigla[DISC_TAM - 1] = '\0';

        if (!existe_disciplina(lista, sigla)) {
            printf("Erro: disciplina '%s' não encontrada.\n", sigla);
        } else {
            int removidos = 0;
            lista = remover_disciplina(lista, sigla, &removidos);
            printf(">>> %d ocorrência(s) de '%s' removida(s).\n", removidos, sigla);
            printf("--- Lista atualizada ---\n");
            imprimir_lista(lista);
        }
    }

    liberar_lista(lista);
    printf("\nPrograma encerrado.\n");
    return 0;
}
