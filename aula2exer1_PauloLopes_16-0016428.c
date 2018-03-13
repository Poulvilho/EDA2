#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[50];
    char CPF[12];
    int qtdeCarros;
} PESSOA;

typedef struct carro {
    char chassi[18];
    char placa[8];
    char dono[12];
} CARRO;

void menu() {
    printf("\n\t\tBanco de Dados dos Carros\n");
    printf("\n1- Cadastrar uma pessoa\n");
    printf("2- Listar pessoas\n");
    printf("3- Listar carros\n");
    printf("4- Pesquisar pessoa\n");
    printf("0- Fechar programa\n");
    printf("\n\tSelecione a opcao desejada: ");
}

void quickSortPessoa(PESSOA *a, int n) {   ///Array e tamanho
    int i, j;
    PESSOA p, t; ///Var. de controle
    if (n < 2) ///Parada da recursão
        return;

    p = a[n/2];

    for (i = 0, j = n - 1;; i++, j--){   ///Incrementa e decrementa
        while (strcmp(a[i].nome, p.nome) < 0) ///Incrementa comparando com o pivo
            i++;
        while (strcmp(p.nome, a[j].nome) < 0) ///Incrementa comparando com o pivo
            j--;
        if (i >= j) ///Verifica o cruzamento dos extremos
            break;

        t = a[i]; ///Troca o [i] com o [j]
        a[i] = a[j];
        a[j] = t;
    }
    quickSortPessoa(a, i); ///Chama recursivamente os sub-vetores
    quickSortPessoa(a + i, n - i);
}

void ordenaPessoa() {
    FILE* file = fopen("pessoas.txt", "r");
    int lines;
    int i;
    PESSOA *pessoas;

    if(file != NULL){
        pessoas = (PESSOA *) malloc(sizeof(PESSOA));
        for (i = 0; !feof(file); i++) {
            fscanf(file, "%s %d %s\n", pessoas[i].CPF, &pessoas[i].qtdeCarros,
                pessoas[i].nome);
            pessoas = (PESSOA *) realloc(pessoas, (i + 2) * sizeof(PESSOA));
            lines = i + 1;
        }
        fclose(file);

        quickSortPessoa(pessoas, lines);

        FILE* file = fopen("pessoas.txt", "w");
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s %d %s\n", pessoas[i].CPF, pessoas[i].qtdeCarros,
                pessoas[i].nome);
        }
        fclose(file);
        free(pessoas);
    } else {
        //Nothing to do.
    }
}

void quickSortCarro(CARRO *a, int n) {   ///Array e tamanho
    int i, j;
    CARRO p, t; ///Var. de controle
    if (n < 2) ///Parada da recursão
        return;

    p = a[n/2];

    for (i = 0, j = n - 1;; i++, j--){   ///Incrementa e decrementa
        while (strcmp(a[i].chassi, p.chassi) < 0) ///Incrementa comparando com o pivo
            i++;
        while (strcmp(p.chassi, a[j].chassi) < 0) ///Incrementa comparando com o pivo
            j--;
        if (i >= j) ///Verifica o cruzamento dos extremos
            break;

        t = a[i]; ///Troca o [i] com o [j]
        a[i] = a[j];
        a[j] = t;
    }
    quickSortCarro(a, i); ///Chama recursivamente os sub-vetores
    quickSortCarro(a + i, n - i);
}

void ordenaCarro() {
    FILE* file = fopen("carros.txt", "r");
    int lines;
    int i;
    CARRO* carros;

    if(file != NULL){
        carros = (CARRO *) malloc(sizeof(CARRO));
        for (i = 0; !feof(file); i++) {
            fscanf(file, "%s %s %s\n", carros[i].chassi, carros[i].placa,
                carros[i].dono);
            carros = (CARRO *) realloc(carros, (i + 2) * sizeof(CARRO));
            lines = i + 1;
        }
        fclose(file);

        quickSortCarro(carros, lines);

        FILE* file = fopen("carros.txt", "w");
        for (int i = 0; i < lines; i++) {
            fprintf(file, "%s %s %s\n", carros[i].chassi, carros[i].placa,
                carros[i].dono);
        }
        fclose(file);
        free(carros);
    } else {
        //Nothing to do.
    }
}

void cadastrarCarro(char CPF[]) {
    CARRO novoCarro;
    printf("\nChassi do carro: ");
    scanf("%s", novoCarro.chassi);
    printf("Placa do carro: ");
    scanf("%s", novoCarro.placa);
    strcpy(novoCarro.dono, CPF);

    FILE* file = fopen("carros.txt", "a");
    fprintf(file, "%s %s %s\n", novoCarro.chassi, novoCarro.placa,
        novoCarro.dono);
    fclose(file);
    ordenaCarro();
}

void cadastrarPessoa() {
    printf("\n\tCadastro de Pessoa\n");
    PESSOA novaPessoa;
    printf("Nome (sem espacos): ");
    scanf("%s", novaPessoa.nome);

    printf("CPF (apenas numeros): ");
    scanf("%s", novaPessoa.CPF);

    printf("\nQuantos carros ele possui: ");
    scanf("%d", &novaPessoa.qtdeCarros);

    FILE* file = fopen("pessoas.txt", "a");
    fprintf(file, "%s %d %s\n", novaPessoa.CPF, novaPessoa.qtdeCarros,
        novaPessoa.nome);
    fclose(file);
    ordenaPessoa();

    for (int i = 0; i < novaPessoa.qtdeCarros; i++) {
        cadastrarCarro(novaPessoa.CPF);
    }
}

void listarPessoas() {
    printf("\nCPF\t\tCarros\tNome\n");
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        PESSOA pessoa;
        while (!feof(file)) {
            fscanf(file, "%s %d %s\n", pessoa.CPF, &pessoa.qtdeCarros,
                pessoa.nome);
            printf("%s\t%d\t%s\n", pessoa.CPF, pessoa.qtdeCarros, pessoa.nome);
        }
        fclose(file);
    } else {
        printf("\nERRO OU NENHUMA PESSOA CADASTRADA\n");
    }
}

void listarCarros() {
    printf("\nChassi\t\t\tPlaca\tCPF do Dono\n");
    FILE* file = fopen("carros.txt", "r");
    if (file != NULL) {
        CARRO carro;
        while (!feof(file)) {
            fscanf(file, "%s %s %s\n", carro.chassi, carro.placa, carro.dono);
            printf("%s\t%s\t%s\n", carro.chassi, carro.placa, carro.dono);
        }
        fclose(file);
    } else {
        printf("\nERRO OU NENHUM CARRO CADASTRADO\n");
    }
}

void pesquisarPessoa() {
    printf("\nDigite o CPF da pessoa que deseja procurar: ");
    char CPFDesejado[11];
    scanf("%s", CPFDesejado);
    FILE* file = fopen("pessoas.txt", "r");
    if (file != NULL) {
        int existe = 0;
        PESSOA pessoa;
        while (!feof(file)) {
            fscanf(file, "%s %d %s\n", pessoa.CPF, &pessoa.qtdeCarros,
                pessoa.nome);
            if (strcmp(CPFDesejado, pessoa.CPF) == 0) {
                printf("\nNome: %s\n", pessoa.nome);
                printf("CPF: %s\n", pessoa.CPF);
                printf("Quantos Carros possui: %d\n", pessoa.qtdeCarros);

                if (pessoa.qtdeCarros >0) {
                    FILE* fileCarros = fopen("carros.txt", "r");
                    if (fileCarros != NULL) {
                        CARRO carro;
                        while (!feof(fileCarros)) {
                            fscanf(fileCarros, "%s %s %s\n", carro.chassi,
                                carro.placa, carro.dono);
                            if (strcmp(carro.dono, pessoa.CPF) == 0) {
                                printf("\nChassi do seu Carro: %s", carro.chassi);
                                printf("\nPlaca: %s\n", carro.placa);
                            }
                        }
                    } else {
                        printf("\nERRO OU CARRO NAO CADASTRADO!\n");
                    }
                }

                existe = 1;
            } else {
                //Nothing to do.
            }
        }
        if (!existe) {
            printf("\nCPF NAO CADASTRADO!\n");
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
                listarCarros();
                break;

            case 4:
                pesquisarPessoa();
                break;

            default:
                printf("\nDIGITE UMA OPCAO VALIDA!!");
                break;
        }
    } while (opc);

    return 0;
}