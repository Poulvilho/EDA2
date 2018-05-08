#include <stdio.h>
#include <stdlib.h>

int main(){

    int notas[7]= {100, 50, 20, 10, 5, 2, 1};
    int moedas[5] = {50, 25, 10, 5, 1};
    int i = 0, inteiro = 0, decimal = 0, aux[7], aux2[5];

    int tamanho_moedas = sizeof moedas / sizeof *moedas;
    int tamanho_notas = sizeof notas / sizeof *notas;

    printf("Insira o valor do troco: Ex:(00,00)\n");
    scanf("%d,%d", &inteiro, &decimal);

    for (i; i < tamanho_notas; i++) {
        aux[i] = inteiro/notas[i];
        inteiro = inteiro % notas[i];
    }

    for (i = 0; i < tamanho_moedas; i++) {
        aux2[i] = decimal/moedas[i];
        decimal = decimal % moedas[i];
    }
    printf("Foram utilizadas as seguintes notas e moedas para o troco:\n");
    for (i = 0; i < tamanho_notas; i++){
        printf("%d notas de $%d \n", aux[i], notas[i]);
    }
    printf("\n");
    for (i = 0; i < tamanho_moedas; i++){
        printf("%d moedas de ¢%d \n", aux2[i], moedas[i]);
    }

return 0;

}