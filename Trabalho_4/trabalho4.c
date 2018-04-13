#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct pessoa {
    char nome[50];
    char code[7];
} PESSOA;

typedef struct arvore {
    PESSOA pessoa;
    struct arvore *esquerda; 
    struct arvore *direita; 
} ARVORE;

void menu() {
    printf("\n\t\tTrabalho EDA2\n");
    printf("\n1- Cadastrar uma pessoa\n");
    printf("2- Listar pessoas\n");
    printf("3- Pesquisar pessoa\n");
    printf("4- Ordenar pessoas por Shell Sort (Crescente)\n");
    printf("5- Ordenar pessoas por Quick Sort (Decrescente)\n");
    printf("0- Fechar programa\n");
    printf("\n\tSelecione a opcao desejada: ");
}

void inserir(ARVORE **raiz, PESSOA novoNo) {
    if ((*raiz) == NULL) {
        strcpy((*raiz)->pessoa.code, novoNo.code);
        strcpy((*raiz)->pessoa.nome, novoNo.nome);
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else if (strcmp((*raiz)->pessoa.code, novoNo.code) <= 0) {
        inserir(&(*raiz)->esquerda, novoNo);
    } else {
        inserir(&(*raiz)->direita, novoNo);
    }
}

void cadastrarPessoa(ARVORE **raiz) {
    printf("\n\tCadastro de Pessoa\n");
    PESSOA novoNo;
    printf("Nome (sem espacos): ");
    scanf("%s", novoNo.nome);
    printf("Codigo de 6 digitos: ");
    scanf("%s", novoNo.code);

    inserir(&(*raiz), novoNo);
}

void listar_inOrdem(ARVORE* raiz) {
   if(raiz != NULL) {
       listar_inOrdem(raiz->esquerda);
       printf("%s\t%s\n", raiz->pessoa.code, raiz->pessoa.nome);
       listar_inOrdem(raiz->direita);
   } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
   }

}

void salvaArquivo(ARVORE **raiz) {
    FILE* file = fopen("pessoas.txt", "w");
    if ((*raiz)->esquerda != NULL) {
        salvaArquivo(&(*raiz)->esquerda);
    }

    fprintf(file, "%s %s\n", (*raiz)->pessoa.code, (*raiz)->pessoa.nome);

    if ((*raiz)->direita != NULL) {
        salvaArquivo(&(*raiz)->direita);
    }
}
int main() {
    ARVORE* raiz = NULL;
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        while (!feof(file)) {
            PESSOA novoNo;
            fscanf(file, "%s %s\n", novoNo.code, novoNo.nome);
            inserir(&raiz, novoNo);
        }
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
    }
    
    int opc;
    do {
        menu();
        scanf("%d", &opc);
        switch (opc) {
            case 0:
                break;

            case 1:
                cadastrarPessoa(&raiz);
                break;

            case 2:
                printf("Codigo:\tNome:\n");
                listar_inOrdem(raiz);
                break;

            case 3:
                //pesquisarPessoa();
                break;

            case 4:
                //contar_tempo(opc);
                break;  

            case 5:
                //contar_tempo(opc);
                break;  

            default:
                printf("\nDIGITE UMA OPCAO VALIDA!!");
                break;
        }
    } while (opc);

    while (raiz!= NULL) {
        salvaArquivo(&raiz);
    }

    return 0;
}
