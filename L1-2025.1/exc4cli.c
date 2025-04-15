//FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <string.h>
#include "exc4int.h"

int main() {
    char palavra[MAX_LEN + 1];

    while (1) {
        printf("Informe a palavra (ou FIM para encerrar): ");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        if (strcmp(palavra, "FIM") == 0) {
            break;
        }

        if (!palavra_valida(palavra)) {
            printf("Entrada invalida. Digite apenas letras sem espacos.\n");
            continue;
        }

        if (verificar_palindromo(palavra)) {
            printf("%s: Palindromo.\n", palavra);
        } else {
            printf("%s: Nao eh palindromo.\n", palavra);
        }
    }

    return 0;
}
