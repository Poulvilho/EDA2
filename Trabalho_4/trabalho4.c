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
    struct arvore* esquerda; 
    struct arvore* direita; 
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

ARVORE* inserir(ARVORE* raiz, ARVORE* novoNo) {
    if (raiz == NULL) {
        raiz = novoNo;
    } else if (strcmp(raiz.pessoa.code, novoNo.pessoa.code) <= 0) {
        raiz.esquerda = inserir(raiz.esquerda, novoNo);
    } else {
        raiz.direita = inserir(raiz.direita, novoNo);
    }
}

void cadastrarPessoa(ARVORE* raiz) {
    printf("\n\tCadastro de Pessoa\n");
    ARVORE novoNo;
    printf("Nome (sem espacos): ");
    scanf("%s", novoNo.pessoa.nome);
    printf("Codigo de 6 digitos: ");
    scanf("%s", novoNo.pessoa.code);
    novoNo.esquerda = NULL;  
    novoNo.direita = NULL;

    inserir(raiz, novoNo);
}

void salvaArquivo() {
    FILE* file = fopen("pessoas.txt", "%s %s\n", novoNo.code, novoNo. nome);
    if (raiz.esquerda != NULL) {
        raiz = salvaArquivo(raiz.esquerda);
    }
    fprintf(file, "%s\n", );
    if ()
    {
        /* code */
    }
}
int main() {
    ARVORE* raiz = NULL;
    FILE* file = fopen("pessoas.txt", "r");
    while (!EOF(file)) {
        ARVORE* novoNo;
        scanf(file, "%s %s", novoNo.pessoa.code, novoNo.pessoa.nome);
        raiz = inserir(raiz, novoNo);
    }
    
    int opc;
    do {
        menu();
        scanf("%d", &opc);
        switch (opc) {
            case 0:
                break;

            case 1:
                cadastrarPessoa(raiz);
                break;

            case 2:
                //listarPessoas();
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
        salvaArquivo();
    }

    return 0;
}
