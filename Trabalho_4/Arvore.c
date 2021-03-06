#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador = 0;

typedef struct Arv {
  int numero;
  struct Arv *esq;
  struct Arv *dir;
  int fator;
} arv;

arv Criar_Arvore () {
  arv *novo;
  novo = malloc (sizeof(arv));
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

int maior(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int Altura(arv *raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        return 1 + maior(Altura(raiz->esq), Altura(raiz->dir));
    }
}
/*int Altura(arv *raiz) {
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
*/
// void FB(arv *raiz) {
//   int fator;

//   if(raiz != NULL) {
//     FB(raiz->esq);
//     FB(raiz->dir);
//     fator = Altura(raiz->esq) - Altura(raiz->dir);

//     if(fator > 1 || fator < -1)
//       printf("Arvore desbalanceada! \n");
//     else
//       printf("Arvore Balanceada!\n");
//   }
// }

void rot_dir(arv *r) {
  arv* b = r;
  arv* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->fator = 0;
  b->fator = 0;
  r = a;
}

void rot_esq(arv *raiz) {
  arv* a = raiz;
  arv* b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  a->fator = 0;
  b->fator = 0;
  raiz = b;
}

void rot_dir_esq(arv *r) {
     arv *a = r;
     arv *c = a->dir;
     arv *b = c->esq;
     c->esq = b->dir;
     a->dir = b->esq;
     b->esq = a;
     b->dir = c;
     if(b->fator == -1){
       a->fator = 0;
       c->fator = 1;
     }
     else if(b->fator == 0){
       a->fator = 0;
       c->fator = 0;
     }
     else if(b->fator == 1){
       a->fator = -1;
       c->fator = 0;
     }
     b->fator = 0;
     r = b;
}

void rot_esq_dir(arv *raiz) {
     arv *c = raiz;
     arv *a = c->esq;
     arv *b = a->dir;
     c->esq = b->dir;
     a->dir = b->esq;
     b->esq = a;
     b->dir = c;
     if(b->fator == -1){
       a->fator = 0;
       c->fator = 1;
     }
     else if(b->fator == 0){
       a->fator = 0;
       c->fator = 0;
     }
     else if(b->fator == 1){
       a->fator = -1;
       c->fator = 0;
     }
     b->fator = 0;
     raiz = b;
}

arv *Balanceia(arv *raiz){
  printf("oioio\n");

    (raiz)->fator = Altura((raiz)->esq) - Altura((raiz)->dir);

    if((raiz)->fator == 2 && (raiz)->esq->fator == -1){
        rot_esq_dir(&(*raiz));
    }
    else if((raiz)->fator == 2 && (raiz)->esq->fator == 1){
        rot_dir(&(*raiz));
        contador++;    }
    else if((raiz)->fator == -2 && (raiz)->dir->fator == 1){
        rot_dir_esq(&(*raiz));
    }
    else if ((raiz)->fator == -2 && (raiz)->dir->fator == -1) {
        rot_esq(&(*raiz));
    }
    return raiz;
}

arv *Inserir( arv *raiz, int num) {
  arv *novo;

  if(raiz == NULL) {
    novo = malloc (sizeof(arv));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->numero = num;
    novo->fator = 0;
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
  raiz = Balanceia(raiz);

  return raiz;
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
        Balanceia(raiz);
      default:
        printf("Opção Inválida!\n");
      break;

    }

  }while(1); 

} 
