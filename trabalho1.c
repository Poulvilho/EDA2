#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[50];
    char code[7];
} PESSOA;

void menu() {
    printf("\n\t\tTrabalho EDA2\n");
    printf("\n1- Cadastrar uma pessoa\n");
    printf("2- Listar pessoas\n");
    printf("3- Pesquisar pessoa\n");
    printf("0- Fechar programa\n");
    printf("\n\tSelecione a opcao desejada: ");
}

void cadastrarPessoa() {
    printf("\n\tCadastro de Pessoa\n");
    PESSOA novaPessoa;
    printf("Nome (sem espacos): ");
    scanf("%s", novaPessoa.nome);

    printf("Codigo de 6 digitos: ");
    scanf("%s", novaPessoa.code);

    FILE* file = fopen("pessoas.txt", "a");
    fprintf(file, "%s %s\n", novaPessoa.code, novaPessoa.nome);
    fclose(file);
}

void listarPessoas() {
    printf("\nCodigo\tNome\n");
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        PESSOA pessoa;
        while (!feof(file)) {
            fscanf(file, "%s %s\n", pessoa.code, pessoa.nome);
            printf("%s\t%s\n", pessoa.code, pessoa.nome);
        }
        fclose(file);
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
    }
}

void pesquisarPessoa() {
    printf("\nDigite o codigo de 6 digitos da pessoa que deseja encontrar: ");
    char codeDesejado[7];
    scanf("%s", codeDesejado);
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        int existe = 0;
        PESSOA pessoa;
        while (!feof(file)) {
            fscanf(file, "%s %s\n", pessoa.code, pessoa.nome);
            if (strcmp(codeDesejado, pessoa.code) == 0) {
                printf("\nNome: %s\n", pessoa.nome);
                printf("Code: %s\n", pessoa.code);

                existe = 1;
            } else {
                //Nothing to do.
            }
        }
        if (!existe) {
            printf("\nCODIGO NAO CADASTRADO!\n");
        } else {
            //Nothing to do.
        }
        fclose(file);
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA!\n");
    }
}

int main() {
    int opc;
    do {
        menu();
        scanf("%d", &opc);
        switch (opc) {
            case 0:
                break;

            case 1:
                cadastrarPessoa();
                break;

            case 2:
                listarPessoas();
                break;

            case 3:
                pesquisarPessoa();
                break;

            default:
                printf("\nDIGITE UMA OPCAO VALIDA!!");
                break;
        }
    } while (opc);

    return 0;
}