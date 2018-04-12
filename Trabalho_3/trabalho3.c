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
    printf("4- Ordenar pessoas por Shell Sort (Crescente)\n");
    printf("5- Ordenar pessoas por Quick Sort (Decrescente)\n");
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

/*void mergeSort(PESSOA *pessoas, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho;
    PESSOA *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(pessoas, posicaoInicio, metadeTamanho);
    mergeSort(pessoas, metadeTamanho + 1, posicaoFim);
    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (PESSOA *) malloc(sizeof(PESSOA) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            strcpy(vetorTemp[k].code, pessoas[j].code);
            strcpy(vetorTemp[k].nome, pessoas[j].nome);
            j++;
            k++;
        } else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                strcpy(vetorTemp[k].code, pessoas[i].code);
                strcpy(vetorTemp[k].nome, pessoas[i].nome);
                i++;
                k++;
            } else {
                if (pessoas[i].code < pessoas[j].code) {
                    strcpy(vetorTemp[k].code, pessoas[i].code);
                    strcpy(vetorTemp[k].nome, pessoas[i].nome);
                    i++;
                    k++;
                } else {
                    strcpy(vetorTemp[k].code, pessoas[j].code);
                    strcpy(vetorTemp[k].nome, pessoas[j].nome);
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        strcpy(pessoas[i].code, vetorTemp[i - posicaoInicio].code);
        strcpy(pessoas[i].nome, vetorTemp[i - posicaoInicio].nome);
    }
    free(vetorTemp);
}

void ordena_mergeSort() {
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

        mergeSort(pessoas, 0, lines);

        FILE* file = fopen("pessoas.txt", "w");
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
        }
        fclose(file);
        free(pessoas);        
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA!\n");
    }
}
*/
void ordena_shellSort() {
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

        int i, j, gap = 1;
        PESSOA value;

        while (gap < lines) {
            gap = 3*gap+1;
        }
        while (gap > 1) {
            gap /= 3;
            for(i = gap; i < lines; i++) {
                strcpy(value.code, pessoas[i].code);
                strcpy(value.nome, pessoas[i].nome);
                j = i - gap;

                while (j >= 0 && (strcmp(value.code, pessoas[j].code) < 0)) {
                    strcpy(pessoas[j + gap].code, pessoas[j].code);
                    strcpy(pessoas[j + gap].nome, pessoas[j].nome);
                    j -= gap; 
                }
                strcpy(pessoas[j + gap].code, value.code);
                strcpy(pessoas[j + gap].nome, value.nome);
            }
        }


        FILE* file = fopen("pessoas.txt", "w");
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
        }
        fclose(file);
        free(pessoas);
    } else {
        printf("\nERRO OU NAO TEM ARQUIVO PARA ORDENAR\n");
    }
}

void quickSort(PESSOA *pessoas, int lines) {
        PESSOA meio, aux;
        int i, j;

        if(lines < 2)
            return;
         
        strcpy(meio.code, pessoas[lines/2].code);
        strcpy(meio.nome, pessoas[lines/2].nome);  

        for(i = 0, j = lines - 1;;i++, j--) {
            while((strcmp(pessoas[i].code, meio.code) > 0))
                i++;
            while((strcmp(meio.code, pessoas[j].code) > 0))
                j--;
            if(i>=j)
                break;

            strcpy(aux.code, pessoas[i].code);
            strcpy(aux.nome, pessoas[i].nome);

            strcpy(pessoas[i].code, pessoas[j].code);
            strcpy(pessoas[i].nome, pessoas[j].nome);

            strcpy(pessoas[j].code, aux.code);
            strcpy(pessoas[j].nome, aux.nome);
        }
        quickSort(pessoas, i);
        quickSort(pessoas + i, lines - i);
}

void ordena_quickSort(){
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
        
        quickSort(pessoas, lines);

        FILE* file = fopen("pessoas.txt", "w");
           for (int i = 0; i < lines; i++) {
                fprintf(file, "%s %s\n", pessoas[i].code, pessoas[i].nome);
            }
        fclose(file);
        free(pessoas);
    } else {
        printf("\nERRO OU NAO TEM ARQUIVO PARA ORDENAR\n");
    }
}

void contar_tempo(int opc) {
    clock_t Ticks[2];
    Ticks[0] = clock();
    if (opc == 4){
        ordena_shellSort();
    } else {
        ordena_quickSort();
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
