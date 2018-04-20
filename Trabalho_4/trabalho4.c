#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct pessoa {
    char nome[50];
    int code;
} PESSOA;

typedef struct arvore {
    int pessoa;
    struct arvore *esquerda; 
    struct arvore *direita; 
} ARVORE;

void menu() {
    printf("\n\t\tTrabalho EDA2\n");
    printf("\n1- Cadastrar uma pessoa\n");
    printf("2- Listar pessoas PRE ORDEM\n");
    printf("3- Listar pessoas EM ORDEM\n");
    printf("4- Listar pessoas POS ORDEM\n");
    printf("5- Pesquisar pessoa\n");
    printf("0- Fechar programa\n");
    printf("\n\tSelecione a opcao desejada: ");
}

ARVORE *inserir(ARVORE *raiz, int novoNo) {
    if (raiz == NULL) {
        raiz = (ARVORE *)malloc(sizeof(ARVORE *));
        raiz->pessoa = novoNo;
        //strcpy(raiz->pessoa.code, novoNo.code);
        //strcpy(raiz->pessoa.nome, novoNo.nome);
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    } else if (raiz->pessoa > novoNo) {
        raiz->esquerda = inserir(raiz->esquerda, novoNo);
    } else if (raiz->pessoa == novoNo ) {
        //Nothing to do.
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
            fscanf(file, "%d\t%s\n", &novoNo.code, novoNo.nome);
            raiz = inserir(raiz, novoNo.code);  
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
    printf("Codigo de 6 numeros: ");
    scanf("%d", &novoNo.code);

    FILE *file = fopen("pessoas.txt", "a");
    fprintf(file, "%d\t%s\n", novoNo.code, novoNo.nome);
    fclose (file);

    raiz = inserir(raiz, novoNo.code);

    return raiz;
}

void mostrarDado(int referencia) {
    FILE *file = fopen("pessoas.txt", "r");
    if (file != NULL){
        PESSOA pessoa;
        int encontrado = 0;
        while(!feof(file)) {
            fscanf(file, "%d\t%s", &pessoa.code, pessoa.nome);
            if (referencia == pessoa.code) {
                printf("%d\t%s\n", pessoa.code, pessoa.nome);
                encontrado = 1;
            }
        }
        if (!encontrado) {
            printf("\nPESSOA NAO ENCONTRADA\n");
        }
        fclose(file);
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
    }
}

void listar_preOrdem(ARVORE* raiz) {
   if(raiz != NULL) {
        mostrarDado(raiz->pessoa);
        listar_preOrdem(raiz->esquerda);
        listar_preOrdem(raiz->direita);
   } else {
        //Nothing to do.
   }
}

void listar_inOrdem(ARVORE* raiz) {
   if(raiz != NULL) {
        listar_inOrdem(raiz->esquerda);
        mostrarDado(raiz->pessoa);
        listar_inOrdem(raiz->direita);
   } else {
        //Nothing to do.
   }
}

void listar_posOrdem(ARVORE* raiz) {
   if(raiz != NULL) {
        mostrarDado(raiz->pessoa);
        listar_inOrdem(raiz->direita);
        listar_inOrdem(raiz->esquerda);
   } else {
        //Nothing to do.
   }
}

void pesquisarPessoa() {
    printf("Digite o codigo de 6 numeros da pessoa desejada: ");
    int codeDesejado;
    scanf("%d", &codeDesejado);
    mostrarDado(codeDesejado);
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
                if (raiz != NULL) {
                    printf("Codigo:\tNome:\n");
                    listar_preOrdem(raiz);
                } else {
                    printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
                }
                break;

            case 3:
                if (raiz != NULL) {
                    printf("Codigo:\tNome:\n");
                    listar_inOrdem(raiz);
                } else {
                    printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
                }
                break;

            case 4:
                if (raiz != NULL) {
                    printf("Codigo:\tNome:\n");
                    listar_posOrdem(raiz);
                } else {
                    printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
                }
                break;  

            case 5:
                if (raiz != NULL) {
                    pesquisarPessoa();
                } else {
                    printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
                }
                break;  

            default:
                printf("\nDIGITE UMA OPCAO VALIDA!!");
                break;
        }
    } while (opc);

    free(raiz);
    return 0;
}
