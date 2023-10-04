#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    int posicao;
    struct No * prox;
    struct No * ant;
}NO;

NO * inicio = NULL;

void criar_no(int x){

    NO * novo = malloc(sizeof(NO));
    novo->valor = x;
    novo->prox = NULL;
    novo->ant = NULL;

    if (inicio == NULL)
        inicio = novo;
    else{
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
    } 
}

void counting_sort(int div){
    NO * aux = inicio;
    for (int s = 0; s < 10; s++){
        while(aux != NULL){

        }
    }
}

int main(){

}