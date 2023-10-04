#include <stdio.h>
#include <stdlib.h>

// Função Max identifica o maior valor dentro de um vetor
int max(int *v, int n) {
    int aux = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > aux)
            aux = v[i];
    }
    return aux;
}

// Função Conting Sort que reorganiza o vetor com base na cada decimal dada pelo parâmetro Div
void counting_sort(int *v, int n, int div, int *temp) {
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int unid = (v[i] / div) % 10;
        count[unid]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int unid = (v[i] / div) % 10;
        temp[count[unid] - 1] = v[i];
        count[unid]--;
    }

    for (int i = 0; i < n; i++) {
        v[i] = temp[i];
    }
}

//Função Principal Radix Sort
void radix_sort(int *v, int n) {
    int k, div = 1; // K é um contador que conta quantas vezes deverá ser feito o counting sort e Div é a posição do algarismo que é usado para o counting sort
    k = max(v, n); // K é o maior valor do vetor que vai sendo reduzido até ser menor que 1
    int *temp = malloc(sizeof(int) * n); // vetor temporário que reorganiza os elementos do vetor V para depois aplicá-los no vetor V

    while (k / div > 0) {
        counting_sort(v, n, div, temp); // Counting sort repete-se enquanto k/div > 0
        div *= 10; // div é multiplicado por 10 para que o próximo counting sort organize os elementos baseados no algarismo seguinte
    }

    free(temp); // libera o espaço ocupado pelo vetor temporário
}

// Função que imprime cada elemento do vetor
void imprimir(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

int main() {
    int v[5];
    printf("Digite 5 números de 4 dígitos separados por espaços:\n");
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
    }

    radix_sort(v, 5);
    
    printf("Vetor ordenado:\n");
    imprimir(v, 5);

    return 0;
}
