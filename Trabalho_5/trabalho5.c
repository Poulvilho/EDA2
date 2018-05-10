#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 6
#define MAX_MOEDAS 6

#define NOTAS {100, 50, 20, 10, 5, 2}
#define MOEDAS {100, 50, 25, 10, 5, 1}

int main() {

    int notas[MAX_NOTAS]= NOTAS;
    int moedas[MAX_MOEDAS] = MOEDAS;
    int inteiro = 0, decimal = 0, aux;

    printf("\tSistema de troco:\n\n");
    printf("Para o troco, temos as seguintes notas e moedas:\n");
    printf("Notas de ");
    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("%d, ", notas[i]);
    }
    printf("e moedas de ");
    for (int i = 0; i < MAX_MOEDAS; i++) {
        if(i == 0) {
            printf("1 REAL, ");
        } else if (i != MAX_MOEDAS - 1) {
            printf("%d centavos, ", moedas[i]);
        } else {
            printf("e 1 centavo.\n");
        }
    }

    printf("\n");
    printf("Insira o valor do troco: Ex:(00,00)\n");
    scanf("%d,%d", &inteiro, &decimal);

    printf("\n");
    printf("Foram utilizadas as seguintes notas e moedas para o troco:\n");
    for (int i = 0; i < MAX_NOTAS; i++) {
        aux = inteiro/notas[i];
        if (aux) {
            printf("%d notas de %d reais\n", aux, notas[i]);
        } else {
            // Nothing to do.
        }
        inteiro = inteiro % notas[i];
    }

    if (inteiro != 0) {
        aux = inteiro / 1;
        decimal += aux * 100;
    }

    printf("\n");
    for (int i = 0; i < MAX_MOEDAS; i++) {
        aux = decimal/moedas[i];
        decimal = decimal % moedas[i];
        if (aux) {
            if (i == 0) {
                printf("%d moedas de 1 REAL\n", aux);
            }
            else {
                printf("%d moedas de %d centavos\n", aux, moedas[i]);
        }
    }

return 0;
}
