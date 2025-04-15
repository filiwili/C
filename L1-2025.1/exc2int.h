//FILIPE DE MOURA AFFONSO
#ifndef EXC2INT_H
#define EXC2INT_H

#define RA_TAM 14
#define DISC_TAM 6
#define MAX_ALUNOS 100

typedef struct aluno {
    char ra[RA_TAM];
    char disciplina[DISC_TAM];
    float nota;
    int faltas;
} Aluno;

typedef struct lista {
    Aluno alunos[MAX_ALUNOS];
    int tamanho;
} Lista;

Lista* criar_lista();
int inserir_final(Lista* lista, Aluno novo);
void imprimir_lista(Lista* lista);
int remover_disciplina(Lista* lista, const char* sigla);
int existe_disciplina(Lista* lista, const char* sigla);
void liberar_lista(Lista* lista);
void to_upper_str(char* str);

int validar_ra(const char* ra);
int validar_nota(float nota);
int validar_faltas(int faltas);

#endif
