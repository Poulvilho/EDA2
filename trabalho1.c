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
    //scanf(" %[^\n]s", novaPessoa.nome);
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
        int lines;
        int i, j=0;
        PESSOA *pessoa;
        int existe = 0;

        pessoa = (PESSOA *) malloc(sizeof(PESSOA));

        for (i = 0; !feof(file); i++) {
            fscanf(file, "%s %s\n", pessoa[i].code, pessoa[i].nome);
                pessoa = (PESSOA *) realloc(pessoa, (i + 2) * sizeof(PESSOA));
                lines = i + 1;
        }
        fclose(file);

        while (j < lines) {
            if (strcmp(codeDesejado, pessoa[j].code) == 0) {
                printf("\nNome: %s\n", pessoa[j].nome);
                printf("Code: %s\n", pessoa[j].code);
                existe = 1;
                PESSOA aux;
                strcpy(aux.code, pessoa[0].code);
                strcpy(aux.nome, pessoa[0].nome);

                strcpy(pessoa[0].code, pessoa[j].code);
                strcpy(pessoa[0].code, pessoa[j].nome);

                strcpy(pessoa[j].code, aux.code);
                strcpy(pessoa[j].nome, aux.nome);

            } else {
                //Nothing to do.
            }
            j++;
        }
        if (!existe) {
            printf("\nCODIGO NAO CADASTRADO!\n");
        } else {
            i=0;
            FILE* file = fopen("pessoas.txt", "w");
            while(i < j){
                fprintf(file, "%s %s\n", pessoa[j].code, pessoa[j].nome);
                i ++;
            }
            fclose(file);
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