#include <stdio.h>
#include <stdlib.h>

int *max(int*v, int n){
    int*aux = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > aux)
            aux = v[i];
    }
    return aux;
}

void conting_sort(int *v, int n, int div, int*temp){
    int l;

    for (int i = 0; i < 10; i++){
        int count = 0;
        for (int s = 0; s < n; i++){
            int unid;
            unid = (v[s]/div)%10;
            if (unid  == s){
                temp[count] = v[s];
                count ++;
            }
        }
    }
    v = temp;
}

void radix_sort(int *v, int n){
    int k, div= 1;
    k = max(v, n);
    int *temp = malloc(sizeof(int)*n);
    while (k > 0){ 
        conting_sort(v, n , div, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}

void imprimir(int *v, int n){
    for (int i = 0;i < n; i++){
        printf("%d\n", v[i]);
    }
}

int main(){
    int * v[5];
    for (int i = 0; i < 5; i++){
        scanf("%d", &v[i]);
    }
    imprimir(v,5);
}