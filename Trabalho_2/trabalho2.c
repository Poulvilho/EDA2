#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct pessoa {
    char nome[50];
    char code[7];
} PESSOA;

void menu() {
    printf("\n\t\tTrabalho EDA2\n");
    printf("\n1- Cadastrar uma pessoa\n");
    printf("2- Listar pessoas\n");
    printf("3- Pesquisar pessoa\n");
    printf("4- Ordenar pessoas por Bubble Sort\n");
    printf("5- Ordenar pessoas por Insertion Sort\n");
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
        int lines = 0;
        PESSOA *pessoas = (PESSOA *) malloc(sizeof(PESSOA));

        for (int i = 0; !feof(file); i++) {
            fscanf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
                pessoas = (PESSOA *) realloc(pessoas, (i + 2) * sizeof(PESSOA));
                lines = i + 1;
        }
        fclose(file);

        int existe = 0;
        int posicao_inicial = 0;
        for (int i = 0; i < lines; i++) {
            if (strcmp(codeDesejado, pessoas[i].code) == 0) {
                printf("\nNome: %s\n", pessoas[i].nome);
                printf("Code: %s\n", pessoas[i].code);
                existe = 1;

                PESSOA aux;
                strcpy(aux.code, pessoas[posicao_inicial].code);
                strcpy(aux.nome, pessoas[posicao_inicial].nome);

                strcpy(pessoas[posicao_inicial].code, pessoas[i].code);
                strcpy(pessoas[posicao_inicial].nome, pessoas[i].nome);

                strcpy(pessoas[i].code, aux.code);
                strcpy(pessoas[i].nome, aux.nome);

                posicao_inicial ++;
            } else {
                //Nothing to do.
            }
        }
        if (!existe) {
            printf("\nCODIGO NAO CADASTRADO!\n");
        } else {
            FILE* file = fopen("pessoas.txt", "w");
           for (int i = 0; i < lines; i++) {
                fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
            }
            fclose(file);
        }
        free(pessoas);
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA!\n");
    }
}

void ordena_bubble() {

    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        int lines = 0;
        PESSOA *pessoas = (PESSOA *) malloc(sizeof(PESSOA));

        for (int i = 0; !feof(file); i++) {
            fscanf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
                pessoas = (PESSOA *) realloc(pessoas, (i + 2) * sizeof(PESSOA));
                lines = i + 1;
        }
        fclose(file);

        int cont = 0;
        PESSOA aux;
        do{
            cont = 0;
            for (int i = 0; i < lines - 1; i++) {
                if (strcmp(pessoas[i].code , pessoas[i+1].code) > 0) {

                    strcpy(aux.code, pessoas[i+1].code);
                    strcpy(aux.nome, pessoas[i+1].nome);

                    strcpy(pessoas[i+1].code, pessoas[i].code);
                    strcpy(pessoas[i+1].nome, pessoas[i].nome);

                    strcpy(pessoas[i].code, aux.code);
                    strcpy(pessoas[i].nome, aux.nome);
                    cont++;
                }
            }
        } while (cont != 0);

        FILE* file = fopen("pessoas.txt", "w");
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
        }
        fclose(file);
        free(pessoas);
    }
}

void ordena_insertion() {
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {

        int lines = 0;
        PESSOA *pessoas = (PESSOA *) malloc(sizeof(PESSOA));

        for (int i = 0; !feof(file); i++) {
            fscanf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
                pessoas = (PESSOA *) realloc(pessoas, (i + 2) * sizeof(PESSOA));
                lines = i + 1;
        }
        fclose(file);

        PESSOA aux;

        for(int i = 0; i < lines; i++) {
            int j = i;
            while ((j != 0) && (strcmp(pessoas[j].code, pessoas[j - 1].code) > 0)) {

                strcpy(aux.code, pessoas[j].code);
                strcpy(aux.nome, pessoas[j].nome);

                strcpy(pessoas[j].code, pessoas[j - 1].code);
                strcpy(pessoas[j].nome, pessoas[j - 1].nome);

                strcpy(pessoas[j - 1].code, aux.code);
                strcpy(pessoas[j - 1].nome, aux.nome);
                j--;
            }
        }
        FILE* file = fopen("pessoas.txt", "w");
           for (int i = 0; i < lines; i++) {
                fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
            }
        fclose(file);
        free(pessoas);
    }
}

void contar_tempo(int opc) {
    clock_t Ticks[2];
    Ticks[0] = clock();
    if (opc == 4){
        ordena_bubble();
    } else {
        ordena_insertion();
    }
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
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

            case 4:
                contar_tempo(opc);
            break;  

            case 5:
                contar_tempo(opc);
            break;  

            default:
                printf("\nDIGITE UMA OPCAO VALIDA!!");
                break;
        }
    } while (opc);

    return 0;
}