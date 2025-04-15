//FILIPE DE MOURA AFFONSO
#ifndef EXC1INT_H
#define EXC1INT_H

#define RA_TAM 14
#define DISC_TAM 6

typedef struct aluno {
    char ra[RA_TAM];
    char disciplina[DISC_TAM];
    float nota;
    int faltas;
    struct aluno* prox;
} Aluno;

Aluno* criar_lista();
Aluno* inserir_final(Aluno* lista, Aluno novo);
void imprimir_lista(Aluno* lista);
Aluno* remover_disciplina(Aluno* lista, const char* sigla, int* removidos);
int existe_disciplina(Aluno* lista, const char* sigla);
void liberar_lista(Aluno* lista);
void to_upper_str(char* str);

int validar_ra(const char* ra);
int validar_nota(float nota);
int validar_faltas(int faltas);

#endif