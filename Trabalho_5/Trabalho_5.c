#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int notas[7]= {100, 50, 20, 10, 5, 2, 1};
    int i = 0, troco = 0, aux[7];
    int tamanho = sizeof notas / sizeof *notas;

    printf("Insira o valor do troco:\n");
    scanf("%d",&troco);

    for (i; i < tamanho; i++) {
    /* usa seqvalor[i] para cada moeda */
        aux[i] = troco/notas[i];
        troco = troco % notas[i];
}
    printf("Foram utilizadas as seguintes notas para o troco:\n");
    for (i = 0; i < tamanho; i++){
        printf("%d notas de %d \n", aux[i], notas[i]);
    }

return 0;

}