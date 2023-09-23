#include <stdio.h>
#include <stdlib.h>

typedef struct conta{
    char*nome;
    int numero;
    int senha;
    float saldo;
    struct conta * prox;
    struct conta * ant;
}cont;

cont * inicio = NULL;
cont * fim = NULL;

void cadastrarConta(char *nome, int senha,int numero, float saldo){

    cont * novo = malloc(sizeof(cont));
    novo->nome = nome;
    novo->senha = senha;
    novo->numero = numero;
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

void removerConta(int numero){
    cont * aux = inicio;
    while((aux->numero != numero) && (aux != NULL)){
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("Conta nao encontrada.\n");
    }else if (aux == inicio){
        inicio = aux->prox;
        inicio->ant = NULL;
        free(aux);
    }else if (aux == fim){
        fim = aux->ant;
        fim->prox = NULL;
        free(aux);
    }else{
        cont * lixo = aux;
        aux = lixo->prox;
        aux->ant = lixo->ant;
        aux = lixo->ant;
        aux->prox = lixo->prox;
        free(lixo);
    } 
}

void visualizar(){
    printf("Imprimindo a Lista\n");

    cont * aux = inicio;
    int count = 1;

    while(aux != NULL){
        printf("Conta %d.\n",count);
        printf("Usuario: %s\n", aux->nome);
        printf("Numero da Conta: %d\n", aux->numero);
        printf("Saldo: %.2f\n", aux->saldo);
        aux = aux->prox;
        count++;
    }
    printf("\n");

}

int main(){
    
    cadastrarConta("Bernardo", 1234,553030, 564.45);
    visualizar();
    cadastrarConta("Cecilia", 1434,53030, 1000.45);
    visualizar();
    cadastrarConta("Catarina", 1424,55610, 1230.45);
    cadastrarConta("Luiz Renato", 1134,53031, 2000.45);
    visualizar();
    removerConta(53030);
    visualizar();

    return 0;
}