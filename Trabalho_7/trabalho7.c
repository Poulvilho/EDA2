#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maiorSubsequencia(int vector[], int qtd_numero) {
	int tamanho[qtd_numero];
	int anterior[qtd_numero];
	for (int j = 0; j < qtd_numero; j++) {
		tamanho[j] = 1;
		anterior[j] = -1;
		for (int i = 0; i < j; i++) {
			if (vector[i] <= vector[j] && 1 + tamanho[i] > tamanho[j]) {
				tamanho[j] = 1 + tamanho[i];
				anterior[j] = i;
            }
		}
	}

    printf("Vetor do Tamanho das Sequencias: \n\n[ ");
    for (int i = 0; i < qtd_numero; i++) {
        printf("%d ", tamanho[i]);
    }
    printf("]\n\n");

    printf("Vetor dos Predecessores: \n\n[ ");
    for (int i = 0; i < qtd_numero; i++) {
        printf("%d ", anterior[i]);
    }
    printf("]\n\n");

    int MSC = 0;
    for (int i = 0; i < qtd_numero; i++) {
        if (MSC < tamanho[i]) {
            MSC = tamanho[i];
        }
    }

    printf("Tamanho da Maior Subsequencia Crescente: %d\n\n", MSC);

    int posicaoMaior;
    for (posicaoMaior = 0; tamanho[posicaoMaior] != MSC; posicaoMaior++) {
    }

    int maiorSubsequencia[MSC];
    for (int i = MSC; i >= 0; i--) {
        maiorSubsequencia[i - 1] = vector[posicaoMaior];
        posicaoMaior = anterior[posicaoMaior];
    }

    printf("Maior Subsequencia Crescente: \n\n[ ");
    for (int i = 0; i < MSC; i++) {
        printf("%d ", maiorSubsequencia[i]);
    }
    printf("]\n\n");
}

void maiorSubsequenciaDecrescente(int vector[], int qtd_numero) {
    int tamanho[qtd_numero];
    int anterior[qtd_numero];
    for (int j = 0; j < qtd_numero; j++) {
        tamanho[j] = 1;
        anterior[j] = -1;
        for (int i = 0; i < j; i++) {
            if (vector[i] >= vector[j] && 1 + tamanho[i] > tamanho[j]) {
                tamanho[j] = 1 + tamanho[i];
                anterior[j] = i;
            }
        }
    }

    printf("Vetor do Tamanho das Sequencias: \n\n[ ");
    for (int i = 0; i < qtd_numero; i++) {
        printf("%d ", tamanho[i]);
    }
    printf("]\n\n");

    printf("Vetor dos Predecessores: \n\n[ ");
    for (int i = 0; i < qtd_numero; i++) {
        printf("%d ", anterior[i]);
    }
    printf("]\n\n");

    int MSC = 0;
    for (int i = 0; i < qtd_numero; i++) {
        if (MSC < tamanho[i]) {
            MSC = tamanho[i];
        }
    }

    printf("Tamanho da Maior Subsequencia Decrescente: %d\n\n", MSC);

    int posicaoMaior;
    for (posicaoMaior = 0; tamanho[posicaoMaior] != MSC; posicaoMaior++) {
    }

    int maiorSubsequencia[MSC];
    for (int i = MSC; i >= 0; i--) {
        maiorSubsequencia[i - 1] = vector[posicaoMaior];
        posicaoMaior = anterior[posicaoMaior];
    }

    printf("Maior Subsequencia Decrescente: \n\n[ ");
    for (int i = 0; i < MSC; i++) {
        printf("%d ", maiorSubsequencia[i]);
    }
    printf("]\n\n");
}

void lerNumeros(int option) {
    printf("\nInsira a quantidade de numeros que deseja colocar no vetor: ");
    int qtd_numero = 0;
    scanf("%d", &qtd_numero);
  
    int vector[qtd_numero];

    switch(option) {
        case 1:
            printf("Insira os numeros que deseja coocar no vetor: \n");
            for(int i = 0; i < qtd_numero; i++) {
                scanf("%d", &vector[i]);
            }
        break;

        case 2:
            for(int i = 0; i < qtd_numero; i++) {
                vector[i] = rand() % 100;
            }
        break;
    }

    printf("\nVetor:\n\n[ ");

    for(int i = 0; i < qtd_numero; i++){
        printf("%d ",vector[i]);
    }
    printf("]\n\n");

    do {
        printf("1 - Obter a maior Subsequencia Crescente\n");
        printf("2 - Obter a maior Subsequencia Decrescente\n");
        printf("Escolha o tipo de Subsequencia que deseja: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                maiorSubsequencia(vector, qtd_numero);
            break;

            case 2:
                maiorSubsequenciaDecrescente(vector, qtd_numero);
            break;

            default:
                printf("ENTRADA INVALIDA!\n\n");
            break;
        }
    } while (option != 1 && option != 2);
}

void menu() {
    printf("*** MENU ***\n");
    printf("0 - Sair.\n");
    printf("1 - Inserir os Números manualmente.\n");
    printf("2 - Inserir os Números aleatoriamente.\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int option = 0;  
    do {
        menu();
        scanf("%d", &option);

        switch(option) {
            case 0:
                printf("\nSaindo...\n");
            break;

            case 1 ... 2:
                lerNumeros(option);
            break;
            default:
                printf("ENTRADA INVALIDA!\n\n");
            break;
        }
    } while(option != 0 && option != 1 && option != 2);

    return 0;
}