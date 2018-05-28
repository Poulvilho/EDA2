#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void Merge(int vector[], int start, int middle, int end, int vector_size) {
    int i = start, j = middle + 1, k = start;
    int *vector_aux = (int*)malloc(vector_size * sizeof(int));
    int y = 0;

    while(y < vector_size) {
        vector_aux[y] = vector[y];
        y++;
    }

    while(i <= middle && j <= end) {
        if(vector_aux[i] < vector_aux[j]) {
            vector[k] = vector_aux[i];
            i++;
        } else {
            vector[k] = vector_aux[j];
            j++;
        }
        k++;
    }

    while(i <= middle) {
        vector[k] = vector_aux[i];
        i++;
        k++;
    }

    while(j <= end) {
        vector[k] = vector_aux[j];
        j++;
        k++;
    }

    free(vector_aux);
}

void MergeSortIterativo(int vector[], int vector_size) {
    int subEnd = 0, slot = 2, middle, end = vector_size - 1;

    printf("Vetor Ordenando\n");

    while(slot / 2 <= vector_size) {
        for(int i = 0; i < vector_size; i += slot) {
            subEnd = i + (slot - 1);
            middle = (i + subEnd) / 2;
            if(subEnd > end) {
                subEnd = end;
            }
            Merge(vector, i, middle, subEnd, vector_size);
        }
        printf("\n[ ");
        for(int i = 0; i <= vector_size -1; i++){
            printf("%d ",vector[i]);
        }
        printf("]\n\n");

        slot *= 2;
    }
}

void lerNumeros(int option) {
    printf("\nInsira a quantidade de numeros que deseja ordenar: ");
    int qtd_numero = 0, numero_vetor = 0;
    scanf("%d", &qtd_numero);
  
    int vector[qtd_numero];
    int vector_size = qtd_numero;

    switch(option) {
        case 1:
            printf("Insira os numeros que deseja ordenar: \n");
            for(int i = 0; i <= vector_size - 1; i++) {
                scanf("%d", &numero_vetor);
                vector[i] = numero_vetor;
            }
        break;

        case 2:
            for(int i = 0; i <= vector_size - 1; i++) {
                vector[i] = rand() % 100;
            }
        break;
    }

    printf("\nVetor:\n\n[ ");

    for(int i = 0; i <= vector_size - 1; i++){
        printf("%d ",vector[i]);
    }
    printf("]\n\n");

    MergeSortIterativo(vector,vector_size);

    printf("Vetor Ordenado:\n\n[ ");

    for(int i = 0; i <= vector_size - 1; i++){
        printf("%d ",vector[i]);
    }
    printf("]\n\n");
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
