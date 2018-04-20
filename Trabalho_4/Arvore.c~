#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arv {
  int numero;
  struct Arv *esq;
  struct Arv *dir;
} arv;

arv Criar_Arvore () {
  arv *novo;
  novo = malloc (sizeof(arv));
}

arv *Inserir( arv *raiz, int num) {
  arv *novo;

  if(raiz == NULL) {
    novo = malloc (sizeof(arv));
    novo->numero = num;
    novo->esq = NULL;
    novo->dir = NULL;
    raiz = novo;

  }
  else{
    if(num > raiz->numero) {
      raiz->dir = Inserir(raiz->dir, num);
    }
    else {
      raiz->esq = Inserir(raiz->esq, num);
    }
  } 
  return raiz;
}

void pre_Ordem(arv *raiz) {
  if(raiz != NULL) {
    printf("%d ", raiz->numero);
    pre_Ordem(raiz->esq);
    pre_Ordem(raiz->dir);
  }
}

void Ordenado(arv *raiz) {
  if(raiz != NULL){
    Ordenado(raiz->esq);
    printf("%d ", raiz->numero);
    Ordenado(raiz->dir);
  }
}

void pos_Ordem (arv *raiz) {
  if(raiz != NULL) {
    pos_Ordem(raiz->esq);
    pos_Ordem(raiz->dir);
    printf("%d ", raiz->numero);
  }

}

arv *deletar (arv *raiz, int num) {
  arv *filho, *n_raiz;

  if (!raiz) 
    return NULL;

  if (raiz->numero == num) {
    if (raiz->dir) {
      n_raiz = filho = raiz->dir;

      while(filho->esq)
        filho = filho->esq;

      filho->esq = raiz->esq;

      free (raiz);
      return n_raiz;

    } else {
      n_raiz = raiz->esq;
      free (raiz);
      return n_raiz;
    }

  } else if (num > raiz->numero)
    raiz->dir = deletar(raiz->dir, num);
  else
    raiz->esq = deletar(raiz->esq, num);

  return raiz;
}

void Destruir (arv *raiz) {
  if(raiz !=NULL){
  Destruir(raiz->esq);
  Destruir(raiz->dir);
  free(raiz);
  }
}

void Maior_valor(arv *raiz) {
  if((raiz->dir) && (raiz->dir->numero > raiz->numero))
          Maior_valor(raiz->dir);
  else
    printf("%d", raiz->numero);
}

int Altura(arv *raiz) {
  if(raiz == NULL) {
    return -1;
  }
  else{
    int esquerda = Altura(raiz->esq);
    int direita = Altura(raiz->dir);
    if(esquerda > direita) return esquerda + 1;
    else return direita + 1;
  }
}

void FB(arv *raiz) {
  int fator;

  if(raiz != NULL) {
    FB(raiz->esq);
    FB(raiz->dir);
    fator = Altura(raiz->esq) - Altura(raiz->dir);

    if(fator > 1 || fator < -1)
      printf("Arvore desbalanceada! \n");
    else
      printf("Arvore Balanceada!\n");
  }

}

int main (void) {

  int option, num, i, N;
  arv *raiz = NULL;


  do{
    printf("\n   >>> MENU <<<  \n");
    printf("\n0.Sair\n1.Inserir\n2.Print pré-Ordem\n3.Print Ordenado\n4.Print pós-Ordem\n5.Remover\n6.Destruir\n7.Maior Valor\n8.Fator de Balanceamento\n");
    printf("\nEscolha uma opção: ");

    scanf("%d", &option);

    switch(option) {
      case 0:
        return 0;
      break;

      case 1:
        printf("Informe a quantidade de elementos a ser inserido: \n");
        scanf("%d", &N);
        printf("Informe o novo elemento\n");
        for(i = 0; i < N; i++) {
        scanf("%d", &num);
        raiz = Inserir(raiz, num);
        }
      break;

      case 2:
        pre_Ordem(raiz);
      break;

      case 3:
        Ordenado(raiz);
      break;

      case 4:
        pos_Ordem(raiz);
      break;

      case 5:
        printf("Informe o elemento a ser excluido\n");
        scanf("%d", &num);
        raiz = deletar(raiz, num);
      break;

      case 6:
        Destruir(raiz);
      break;

      case 7:
        Maior_valor(raiz);
      break;

      case 8:
        FB (raiz);
      default:
        printf("Opção Inválida!\n");
      break;

    }

  }while(1); 

} 
