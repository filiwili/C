//NOME DO ALUNO: FILIPE DE MOURA AFFONSO
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no* next;
} no;

void insert(no** cabeca, int value) {
    no* newno = (no*) malloc(sizeof(no));
    newno->value = value;
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
    while (cabeca != NULL) {
        printf("%d ", cabeca->value);
        cabeca = cabeca->next;
    }
    printf("\n");
}

void exclude(no** cabeca, no* otherList) {
    no* current = *cabeca;
    no* previous = NULL;
    while (current != NULL) {
        no* temp = otherList;
        int found = 0;
        while (temp != NULL) {
            if (temp->value == current->value) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            if (previous == NULL) {
                *cabeca = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            current = previous == NULL ? *cabeca : previous->next;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    no* list1 = NULL;
    no* list2 = NULL;

    printf("Informe os valores para a lista 1, insira o valor -999 para encerrar:\n");
    int value;
    scanf("%d", &value);
    while (value != -999) {
        insert(&list1, value);
        scanf("%d", &value);
    }

    printf("Informe os valores para a lista 2, insira o valor -999 para encerrar:\n");
    scanf("%d", &value);
    while (value != -999) {
        insert(&list2, value);
        scanf("%d", &value);
    }

    printf("\nSituação inicial: ");
    printf("\nLista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);

    exclude(&list2, list1);

	printf("\nSituação final: ");
    printf("\nLista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);

    return 0;
}