#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila{
  struct elemento *inicio;
  struct elemento *final;
};

struct elemento{
  int valor;
  struct elemento *prox;
};

typedef struct elemento elem;

Fila* criafila(){
  Fila* fi = (Fila*)malloc(sizeof(Fila));
  if( fi != NULL ){
    fi->final = NULL;
    fi->inicio = NULL;
  }
  return fi;
};

void liberafila(Fila* fi){
  if(fi != NULL){
    elem  *no;
    while(fi->inicio != NULL){
      no = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(no);
    }
  }
};

int tamanhofila(Fila* fi){
  if(fi == NULL) return 0;
  int cont = 0;
  elem* no = fi->inicio;
  while(no != NULL){
      cont ++;
      no = no->prox;
  }
  return cont;
};

void imprimefila(Fila* fi){
  int aux = tamanhofila(fi);
  elem* no = fi->inicio;
  while(aux > 0){
    printf("Valor do no: %d\n",no->valor);
    no = no->prox;
    aux--;
  }
};

int buscapos(Fila* fi, int valorb){
  if(fi != NULL){
    int cont = 0;
    elem* no = fi->inicio;
    while(no != NULL || no->valor == valorb){
      if(no->valor == valorb)
        return cont;
      else{
        no = no->prox;
        cont++;
      }
    }
  }
  return -1;
};

int inserefila(Fila* fi, int valorin){
  if(fi == NULL) return 0;
  elem* no = (elem*)malloc(sizeof(elem));
  if(no == NULL) return 0;
  no->valor = valorin;
  no->prox = NULL;
  if(fi->final == NULL)
    fi->inicio = no;
  else
    fi->final->prox = no;
  fi->final = no;
  return 1;
};

int removefila(Fila* fi){
  if(fi == NULL) return 0;
  if(fi->inicio == NULL) return 0;
  elem *no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  if(fi->inicio == NULL) fi->final = NULL;
  free(no);
  return 1;
}

int main(void) {
  Fila* juju = criafila();
  int aux, deucerto;
  char choice;
  do{
    printf("1-Insere arquivos na fila. \n");
    printf("2-Remove arquivos da fila. \n");
    printf("3-Consulta posicao na fila. \n");
    printf("4-Imprime fila. \n");
    printf("5-Parar programa. \n");
    printf("Escolha alguma opcao: %c\n");
    scanf("\n%c",&choice);
    switch(choice){
      case '1': printf("Qual numero deseja inserir? \n");
                scanf("%d",&aux);
                deucerto = inserefila(juju,aux);
                if(deucerto == 1) printf("Arquivo inserido com sucesso. \n");
                else printf("Falha na insercao. \n");
                break;
      case '2': deucerto = removefila(juju);
                if(deucerto == 1) printf("Arquivo removido com sucesso. \n");
                else printf("Falha na remocao. \n");
                break;
      case '3': printf("Qual numero deseja buscar? \n");
                scanf("%d",&aux);
                deucerto = buscapos(juju, aux);
                printf("Posicao do valor buscado na fila: %d\n",deucerto);
                break;
      case '4': imprimefila(juju);
                break;
      default: printf("Opcao invalida.\n");
    }; 
  }while(choice != '5');
  return 0;
}