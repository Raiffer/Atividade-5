#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    //variaveis relacionadas ao problema
    int valor;
    struct no * prox; 
    struct no * ant; 
}NO;

typedef struct conta{
    char*nome;
    int senha;
    float saldo;
    struct no * prox;
    struct no * ant;
}cont;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


void add(int valor, int pos){
    
    if(pos >= 0  && pos <= tam){
    
        //cria um novo no na memoria e seta seus valores
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
    
        if(inicio == NULL){ //se a lista esta vazia
            inicio = novo; //constante :D
            fim = novo;
        }else if(pos == 0){
            //adicionar no inicio - constante :D
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
            
        }else if(pos == tam){ 
            //adicionar no fim - constante :D
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
        }else{
            //adicionar no meio - linear :/
            NO *aux = inicio;
            for(int i=0; i< pos; i++){
                aux = aux->prox;
            }
           // novo->prox = aux->prox;
           novo->prox = aux;
           // aux->prox = novo; 
           aux->ant->prox = novo;
           // novo->ant = aux;
           novo->ant = aux->ant;
           //novo->prox->ant = novo;
           aux->ant = novo;
        }
        tam++;
    }else{
        printf("Posicao invalida! O valor %d nao foi inserido!\n", valor);
    }
}

int len(){
    return tam;
}


void remover(int pos){
    
    if(pos >= 0 && pos < tam){
        
        if(inicio == NULL){
            printf("vazia! :/\n");
        }else if (pos == 0){ 
            //inicio da lista - constante :D
            NO *lixo = inicio;
            inicio = inicio->prox; 
            inicio->ant = NULL;
            free(lixo);
            tam--;
        
        }else if(pos == tam - 1){//fim - constante! :D

            NO *lixo = fim;
            fim = fim->ant;
            fim->prox = NULL;
            free(lixo);
            tam--;            


        }else{
            // meio! Linear :/
            NO *lixo = inicio;
            for(int i=0; i< pos; i++){
                lixo = lixo->prox;
            }

            lixo->ant->prox = lixo->prox;
            lixo->prox->ant = lixo->ant;
            free(lixo);
            tam--;
        }
        
        
    }
    
}


void imprimir(){
    printf("Imprimindo a lista...\n");
    NO *aux = inicio;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
  add(7, 0);
  add(20, 1);
  add(33, 2);
  add(14, 3);
  imprimir();
  remover(2);
  imprimir();

  return 0;
}
