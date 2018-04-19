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
    printf("0- Fechar programa\n");
    printf("\n\tSelecione a opcao desejada: ");
}

ARVORE *inserir(ARVORE *raiz, PESSOA novoNo) {
    if (raiz == NULL) {
        raiz = (ARVORE *)malloc(sizeof(ARVORE *));
        raiz->pessoa = novoNo;
        //strcpy(raiz->pessoa.code, novoNo.code);
        //strcpy(raiz->pessoa.nome, novoNo.nome);
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    } else if (strcmp(raiz->pessoa.code, novoNo.code) <= 0) {
        raiz->esquerda = inserir(raiz->esquerda, novoNo);
    } else {
        raiz->direita = inserir(raiz->direita, novoNo);
    }
    return raiz;
}

ARVORE *carregaArvore(ARVORE *raiz) {
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        PESSOA novoNo;
        while (!feof(file)) {
            fscanf(file, "%s\t%s\n", novoNo.code, novoNo.nome);
            raiz = inserir(raiz, novoNo);
            printf("%s\n", novoNo.code);
        }
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
    }

    fclose(file);
    return raiz;
}

ARVORE *cadastrarPessoa(ARVORE *raiz) {
    printf("\n\tCadastro de Pessoa\n");
    PESSOA novoNo;
    printf("Nome (sem espacos): ");
    scanf("%s", novoNo.nome);
    printf("Codigo de 6 digitos: ");
    scanf("%s", novoNo.code);
    raiz = inserir(raiz, novoNo);

    return raiz;
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

void salvaArquivo(ARVORE *raiz) {
    FILE* file = fopen("pessoas.txt", "w");
    if (raiz->esquerda != NULL) {
        salvaArquivo(raiz->esquerda);
    }

    fprintf(file, "%s %s\n", raiz->pessoa.code, raiz->pessoa.nome);

    if (raiz->direita != NULL) {
        salvaArquivo(raiz->direita);
    }
}

int main() {
    ARVORE* raiz = NULL;
    raiz = carregaArvore(raiz);

    int opc;
    do {
        menu();
        scanf("%d", &opc);
        switch (opc) {
            case 0:
                break;

            case 1:
                raiz = cadastrarPessoa(raiz);
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
        salvaArquivo(raiz);
    }

    free(raiz);
    return 0;
}
