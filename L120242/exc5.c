//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char palavra[20];
    struct no* next;
} no;

void insert(no** cabeca, char* palavra) {
    no* newno = (no*) malloc(sizeof(no));
    strcpy(newno->palavra, palavra);
    newno->next = NULL;

    if (*cabeca == NULL) {
        *cabeca = newno;
    } else {
        no* current = *cabeca;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newno;
    }
}

void printList(no* cabeca) {
    printf("{ ");
    while (cabeca != NULL) {
        printf("%s ", cabeca->palavra);
        cabeca = cabeca->next;
    }
    printf("}\n");
}

no* unionSets(no* set1, no* set2) {
    no* result = NULL;
    no* current1 = set1;
    no* current2 = set2;

    while (current1 != NULL) {
        insert(&result, current1->palavra);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        int found = 0;
        no* temp = result;
        while (temp != NULL) {
            if (strcmp(temp->palavra, current2->palavra) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insert(&result, current2->palavra);
        }
        current2 = current2->next;
    }

    return result;
}

no* intersectionSets(no* set1, no* set2) {
    no* result = NULL;
    no* current1 = set1;
    no* current2 = set2;

    while (current1 != NULL) {
        int found = 0;
        no* temp = current2;
        while (temp != NULL) {
            if (strcmp(temp->palavra, current1->palavra) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            insert(&result, current1->palavra);
        }
        current1 = current1->next;
    }

    return result;
}

no* differenceSets(no* set1, no* set2) {
    no* result = NULL;
    no* current1 = set1;
    no* current2 = set2;

    while (current1 != NULL) {
        int found = 0;
        no* temp = current2;
        while (temp != NULL) {
            if (strcmp(temp->palavra, current1->palavra) == 0) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            insert(&result, current1->palavra);
        }
        current1 = current1->next;
    }

    return result;
}

int main() {
    no* set1 = NULL;
    no* set2 = NULL;

    printf("Informe as palavras do Conjunto 1, insira o símbolo '*' para encerrar:\n");
    char palavra[20];
    scanf("%s", palavra);
    while (strcmp(palavra, "*") != 0) {
        insert(&set1, palavra);
        scanf("%s", palavra);
    }

    printf("Informe as palavras do Conjunto 2, insira o símbolo '*' para encerrar:\n");
    scanf("%s", palavra);
    while (strcmp(palavra, "*") != 0) {
        insert(&set2, palavra);
        scanf("%s", palavra);
    }

    printf("\nConjunto 1:\n ");
    printList(set1);
    printf("Conjunto 2:\n ");
    printList(set2);

    no* unionResult = unionSets(set1, set2);
    printf("União dos conjuntos:\n ");
    printList(unionResult);

    no* intersectionResult = intersectionSets(set1, set2);
    printf("Intersecção dos conjuntos:\n ");
    printList(intersectionResult);

    no* differenceResult1 = differenceSets(set1, set2);
    printf("Diferença Conjunto1 - Conjunto2:\n ");
    printList(differenceResult1);

    no* differenceResult2 = differenceSets(set2, set1);
    printf("Diferença Conjunto2 - Conjunto1:\n ");
    printList(differenceResult2);

    return 0;
}