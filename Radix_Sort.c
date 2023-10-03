#include <stdio.h>
#include <stdlib.h>

// Função Max identifica o maior valor dentro de um vetor
int max(int*v, int n){
    int aux = v[0];
    for (int i = 0; i < n; i++){
        if (v[i] > aux)
            aux = v[i];
    }
    return aux;
}

// Função Conting Sort que reorganiza o vetor com base na cada decimal dada pelo parâmetro Div
void conting_sort(int *v, int n, int div, int *temp){
    int l;
    int count = 0;
    for (int i = 0; i < 10; i++){
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

//Função Principal Radix Sort
void radix_sort(int *v, int n){
    int k, div= 1; // K é um contador que conta quantas vezes deverá ser feito o conting sort e Div é a posicao do algarismo que é usado para o conting sort
    k = max(v, n); // K é o maior valor do vetor que vai sendo reduzido até ser menor que 1
    int *temp = malloc(sizeof(int)*n); //vetor temporário que reorganiza os elementos do vetor V para depois aplica-los no vetor V
    while (k >= 1){ 
        conting_sort(v, n , div, temp); // Conting sort repete - se enquanto k for inteiro
        div *= 10; // div é multiplicado por 10 para que o proximo conting sort organize os elementos baseados no algarismo seguinte
        k /= 10; // k é reduzido por 10 para diminuir em um o numero de casas decimais a serem reorganizadas
    }
    free(temp); // libera o espaço ocupado pelo vetor temporário
}

// Função que imprime cada elemento do vetor
void imprimir(int *v, int n){
    for (int i = 0;i < n; i++){
        printf("%d\n", v[i]);
    }
}

int main(){
    int tam;
    scanf("");
    int v[5];
    for (int i = 0; i < 5; i++){
        scanf("%d", &v[i]);
    }
    imprimir(v,5);
}