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

void remove_na_playlist(char * n_musica){
    mus * aux = inicio;
    mus * lixo;
    while(n_musica != aux->nome){
        aux = aux->prox;
    }  
    if (aux == inicio){
        aux = inicio->prox;
        lixo = aux->ant;
        aux->ant = lixo->ant;
        aux = lixo->ant;
        inicio = lixo->prox;
        aux->prox = lixo->prox;
        free (lixo);
    }else
    if (aux == fim){
        aux = fim->prox;
        lixo = aux->ant;
        aux->ant = lixo->ant;
        aux = lixo->ant;
        fim = lixo->ant;
        aux->prox = lixo->prox;
        free (lixo);
        }
        else{
            aux = aux->prox;
            lixo = aux->ant;
            aux->ant = lixo->ant;
            aux = lixo->ant;
            aux->prox = lixo->prox;
            free (lixo);
        }
    }


int main(){
    add_na_playlist("Bones","Imagine Dragons",165);
    add_na_playlist("Sharks","Imagine Dragons",165);
    add_na_playlist("Beliver","Imagine Dragons",165);
    add_na_playlist("Hayloft II","Mother Mother",165);
    mus * aux = inicio->prox;
    play(4);
    remove_na_playlist("Sharks");
    printf("\n");
    play(1);
}