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

void add_na_playlist(char nome, char cant, int secs){
    
    mus * novo = malloc(sizeof(mus));
    novo->nome = nome;
    novo->cant = cant;
    novo->secs = secs;
    novo->prox = fim;
    novo->ant = inicio;
    
    if (inicio == NULL){
        inicio = novo;
        fim = novo;
    }
}
