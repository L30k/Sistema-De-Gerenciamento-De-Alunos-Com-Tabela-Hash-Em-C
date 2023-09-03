/********************************************************************************************************************************
# Sistema-De-Gerenciamento-De-Alunos-Com-Tabela-Hash-Em-C
1) Crie um programa que manipule os dados de um aluno em uma tabela hash.

  a) O cadastro de um aluno possui:
  
    • Matrícula.
    • Nome.
    • Curso.
    • Período.
  
  b) A chave utilizada na função hash é a matrícula do aluno.
  
  c) A quantidade de alunos que a instituição possui será informada pelo usuário.
  
    • O tamanho da tabela hash deve ser o próximo número primo a partir da quantidade de alunos (incluindo a quantidade).
    
  d) As seguintes funções devem ser suportadas pelo sistema:
  
    • Cadastrar um aluno.
    • Buscar um aluno.
    • Excluir um aluno.
    • Alterar os dados de um aluno.
    • Excluir todos os alunos.
    • Aumentar o número de alunos da instituição.
    
  e) O sistema deverá ser encerrado apenas quando o usuário solicitar.
********************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aluno {
    int matricula;
    char nome[64];
    char curso[64];
    int periodo;
} Aluno;

typedef struct tabela {
    int tamanho;
    int *tabela;
    Aluno **alu;
} Tabela;

Tabela *iniciarTabela(int tam);
int tamanhoDaTabela(int tam);
int buscarPosicao(int pos, int tam);

bool cadastrarAluno(Tabela *tab, Aluno *alu);
bool buscarAluno(Tabela *tab, int id);
bool excluirAluno(Tabela *tab, int id);
bool alterarDadosAluno(Tabela *tab, int id, Aluno *alu);
bool limparTabela(Tabela *tab);
void aumentarTamanhoDeAlunos(Tabela *tab, int tam);

int main() {
    int escolha;
    int tam;
    int id;
    Aluno *aux = malloc(sizeof(Aluno));

    printf("Qual o tamanho da Tabela.\n");
    scanf("%d", &tam);

    Tabela *tab = iniciarTabela(tam);

    while (true) {
        printf("1. Cadastrar um aluno.\n");
        printf("2. Buscar um aluno.\n");
        printf("3. Excluir um aluno.\n");
        printf("4. Alterar os dados de um aluno.\n");
        printf("5. Excluir todos os alunos.\n");
        printf("6. Aumentar o número de alunos da instituição.\n");
        printf("7. Finalizar programa.\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\n\nCadastrar um aluno.\n");

                printf("Qual o matricula.\n");
                scanf("%d", &aux->matricula);
                getchar();

                printf("Qual o nome.\n");
                gets(aux->nome);

                printf("Qual o curso.\n");
                gets(aux->curso);

                printf("Qual o periodo.\n");
                scanf("%d", &aux->periodo);
                getchar();

                cadastrarAluno(tab, aux);
                break;

            case 2:
                printf("\n\nBuscar um aluno.\n");
                printf("Qual o id.\n");
                scanf("%d", &id);
                getchar();

                if (buscarAluno(tab, id)) {
                    printf("Aluno encontrado.\n");
                } else {
                    printf("Aluno não encontrado.\n");
                }

                break;

            case 3:
                printf("\n\nExcluir um aluno.\n");
                printf("Qual o id.\n");
                scanf("%d", &id);
                getchar();

                if (excluirAluno(tab, id)) {
                    printf("Aluno excluído.\n");
                } else {
                    printf("Não foi possível excluir aluno.\n");
                }

                break;

            case 4:
                printf("\n\nAlterar os dados de um aluno.\n");

                printf("Qual o id.\n");
                scanf("%d", &id);
                getchar();

                printf("Qual o nome.\n");
                gets(aux->nome);

                printf("Qual o curso.\n");
                gets(aux->curso);

                printf("Qual o periodo.\n");
                scanf("%d", &aux->periodo);
                getchar();

                alterarDadosAluno(tab, id, aux);

                break;

            case 5:
                printf("\n\nExcluir todos os alunos.\n");

                limparTabela(tab);
                printf("Tabela limpa.\n");

                break;

            case 6:
                printf("\n\nAumentar o número de alunos da instituição.\n");
                printf("Qual o tamanho.\n");
                scanf("%d", &tam);
                getchar();

                aumentarTamanhoDeAlunos(tab, tam);

                break;

            case 7:
                printf("\n\nFinalizar programa.\n");
                return 0;

            default:
                printf("Valor não corresponde a nenhuma opção!\n");
        }
    }

    return 0;
}

Tabela *iniciarTabela(int tam) {
    int aux = tamanhoDaTabela(tam);
    int *tabela = (int *)malloc(aux * sizeof(int));
    Aluno **novo = (Aluno **)malloc(aux * sizeof(Aluno *));

    for (int i = 0; i < aux; i++) {
        tabela[i] = 0;
        novo[i] = NULL;
    }

    Tabela *tab = (Tabela *)malloc(sizeof(Tabela));
    tab->alu = novo;
    tab->tabela = tabela;
    tab->tamanho = aux;

    return tab;
}

int tamanhoDaTabela(int tam) {
    int primo = 0;
    for (int i = tam * 2;; i++) {
        if (i == 0 || i == 1) {
            primo = 0;
        } else {
            primo = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    primo = 0;
                    break;
                }
            }
        }

        if (primo == 1) {
            return i;
        }
    }
}

int buscarPosicao(int pos, int tam) {
    int i = pos % tam;
    return i;
}

bool cadastrarAluno(Tabela *tab, Aluno *alu) {
    int pos = buscarPosicao(alu->matricula, tab->tamanho);
    if (tab->tabela[pos] == 0) {
        tab->alu[pos] = alu;
        tab->tabela[pos] = 1;
        return true;
    } else {
        return false;
    }
}

bool buscarAluno(Tabela *tab, int id) {
    int pos = buscarPosicao(id, tab->tamanho);
    if (tab->tabela[pos] != 0) {
        return true;
    } else {
        return false;
    }
}

bool excluirAluno(Tabela *tab, int id) {
    int pos = buscarPosicao(id, tab->tamanho);
    if (tab->tabela[pos] != 0) {
        tab->alu[pos] = NULL;
        tab->tabela[pos] = 0;
        return true;
    } else {
        return false;
    }
}

bool alterarDadosAluno(Tabela *tab, int id, Aluno *alu) {
    int pos = buscarPosicao(id, tab->tamanho);
    if (tab->tabela[pos] != 0) {
        tab->alu[pos] = alu;
        return true;
    } else {
        return false;
    }
}

bool limparTabela(Tabela *tab) {
    int aux = tab->tamanho;

    for (int i = 0; i < aux; i++) {
        tab->alu[i] = NULL;
        tab->tabela[i] = 0;
    }
    return true;
}

void aumentarTamanhoDeAlunos(Tabela *tab, int tam) {
    int aux = tamanhoDaTabela(tam);

    tab->alu = (Aluno **)realloc(tab->alu, aux * sizeof(Aluno *));
    tab->tabela = (int *)realloc(tab->tabela, aux * sizeof(int));

    for (int i = tab->tamanho; i < aux; i++) {
        tab->alu[i] = NULL;
        tab->tabela[i] = 0;
    }

    tab->tamanho = aux;
}
