#include <stdio.h>
#include <stdlib.h>

typedef struct musica{
    char*nome;
    char*cant;
    int secs;
    struct musica * prox;
    struct musica * ant;
}mus;

mus * inicio = NULL;
mus * fim = NULL;

void add_na_playlist(char*nome, char*cant, int secs){
    
    mus * novo = malloc(sizeof(mus));
    novo->nome = nome;
    novo->cant = cant;
    novo->secs = secs;
    novo->prox = inicio;
    novo->ant = fim;
    
    if (inicio == NULL){
        inicio = novo;
        fim = novo;
    }else {
        fim->prox = novo;
        inicio->ant = novo;
        fim = novo;
    }
}

void play(int ciclo){
    mus * aux = inicio;
    int count = 0;
    while( count < ciclo){
        printf("%s\n", aux->nome);
        aux = aux->prox;
        if(aux == inicio){
            count++;
        }
    }
}

int main(){
    add_na_playlist("Bones","Imagine Dragons",165);
    add_na_playlist("Sharks","Imagine Dragons",165);
    add_na_playlist("Beliver","Imagine Dragons",165);
    add_na_playlist("Hayloft II","Mother Mother",165);
    mus * aux = inicio->prox;
    printf("%s\n", aux->nome);
    printf("%s\n", inicio->nome);
    printf("%s\n", fim->nome);
    printf("\n");
    play(4);
}