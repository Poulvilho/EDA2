#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int vector[], int i, int j){

    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;

}

void Merge(int vector[], int start, int middle, int end, int vector_size){

  int i = start, j = middle + 1, k = start;

  int *vector_aux = (int*)malloc(vector_size * sizeof(int));
  int y = 0;

  while(y < vector_size){
    vector_aux[y] = vector[y];
    y++;
  }

  while(i <= middle && j <= end){
    if(vector_aux[i] < vector_aux[j]){
      vector[k] = vector_aux[i];
      i++;
    }
    else{
      vector[k] = vector_aux[j];
      j++;
    }
    k++;
  }

  while(i <= middle){
    vector[k] = vector_aux[i];
    i++;
    k++;
  }

  while(j <= end){
    vector[k] = vector_aux[j];
    j++;
    k++;
  }

  free(vector_aux);
}

void MergeSortRecursivo(int vector[], int start, int end, int vector_size){
  if(start < end){
    int middle = (start + end)/2;

    MergeSortRecursivo(vector,start,middle,vector_size);
    MergeSortRecursivo(vector,middle+1,end,vector_size);
    Merge(vector,start,middle,end,vector_size);
  }
}

void MergeSortIterativo(int vector[], int vector_size){
  int i = 0, subEnd = 0, slot = 2,middle, end = vector_size - 1;

  while(slot/2 <= vector_size){
    for(i = 0; i < vector_size; i+= slot){
      subEnd = i + (slot - 1);
      middle = (i + subEnd)/2;
      if(subEnd > end){
        subEnd = end;
      }

      Merge(vector,i,middle,subEnd,vector_size);
    }
    slot = slot*2;
  }
}

int main(){

  int qtd_numero = 0, i = 0, numero_vetor = 0;  
  printf("Insira a quantidade de numeros que deseja ordenar: \n");
  scanf("%d", &qtd_numero);
  
  int vector[qtd_numero];

  int vector_size = qtd_numero;
  printf("Insira os numeros que deseja ordenar: \n");
  for(i=0; i <= vector_size -1; i++) {
    scanf("%d", &numero_vetor);
    vector[i] = numero_vetor;
  }

  printf("\nVetor:\n\n[ ");

  for(i = 0;i <= vector_size -1;i++){
    printf("%d ",vector[i]);
  }
  printf("]\n\n");

  MergeSortIterativo(vector,vector_size);

  printf("\nVetor Ordenado:\n\n[ ");

  for(i = 0;i <= vector_size -1;i++){
    printf("%d ",vector[i]);
  }
  printf("]\n\n");

  return 0;

}