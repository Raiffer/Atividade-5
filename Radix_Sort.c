#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *v, int n){
    int k, div;
    k = max(v, n);
    int *temp = malloc(sizeof(int)*n);
    while (k > 0){ 
        conting_short(v, n , div, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}

void conting_short(int *v, int n, int div, int*temp){
    int l;
    for (int i = 0; i < 10; i++){
        for (int s = 0; s < n; i++){
            
        }
    }
}

int *max(int*v, int n){
    int*aux = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > aux)
            aux = v[i];
    }
    return aux;
} 