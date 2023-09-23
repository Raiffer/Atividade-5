#include <stdio.h>
#include <stdlib.h>

typedef struct conta{
    char*nome;
    int senha;
    float saldo;
    struct conta * prox;
    struct conta * ant;
}cont;

cont * inicio = NULL;
cont * fim = NULL;

void cadastrarConta(char *nome, int senha, float saldo){

    cont * novo = malloc(sizeof(cont));
    novo->nome = nome;
    novo->senha = senha;
    novo->saldo = saldo;
    novo->prox = NULL;
    novo->ant = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }else{
        cont * aux = inicio;
        while((aux->saldo > novo->saldo) && (aux->prox != NULL)){
            aux = aux->prox;
        }
        if((fim == aux) && (aux->saldo >= novo->saldo)){
            aux->prox = novo;
            novo->ant = aux;
            fim = novo;  
        }else if (inicio == aux){
            novo->prox = aux;
            aux->ant = novo;
            inicio = novo;
        }else{
            novo->prox = aux;
            novo->ant = aux->ant;  
            aux->ant = novo;
            aux = novo->ant;
            aux->prox = novo;
        }
    }
    while (inicio->ant != NULL){
        inicio = inicio->ant;
    }
} 

void imprimir(){

    printf("Imprimindo a Lista...\n");
    cont * aux = inicio;
    int count = 1;

    while(aux != NULL){
        printf("Conta %d.\n",count);
        printf("Usuario: %s\n", aux->nome);
        printf("Saldo: %f\n", aux->saldo);
        aux = aux->prox;
        count++;
    }

}

int main(){
    
    cadastrarConta("Bernardo", 1234, 564.45);
    imprimir();
    return 0;
}