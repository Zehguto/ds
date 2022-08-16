#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep

// função para calcular o tempo

// struct para vetor

struct vetor
{
    int max_size; // numero máximo de elementos
    int size;     // quantidade atual de elementos
    float *data;  // vetor de floats
} vetor;

// funação printa o vetor
void imprime(int vetor[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
// função cria vetor
int *aloca_vetor(int size)
{
    int *vec;
    vec = (int *)malloc(size * sizeof(int));
    return vec;
}

// funções do merge
void merge(int vetor[], int esquerdo, int meio, int direito, int tam)
{
    int i, j, k; // auxiliares

    int n1 = meio - esquerdo + 1; // +1 por causa do indice 0
    int n2 = direito - meio;      // indice da direita apenas

    int vetorL[n1], vetorR[n2];

    for (i = 0; i < n1; i++)
    {
        vetorL[i] = vetor[esquerdo + i];
    }
    for (j = 0; j < n2; j++)
    {
        vetorR[j] = vetor[meio + j + 1];
    }
    i = 0; // erro estava aqui aparentemente entrei com i,j=0; apos mudança funcionou.
    j = 0;
    k = esquerdo;

    while (i < n1 && j < n2)
    {
        if (vetorL[i] <= vetorR[j])
        {
            imprime(vetor, tam);
            vetor[k] = vetorL[i];
            i++;
        }
        else
        {
            vetor[k] = vetorR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        imprime(vetor, tam);
        vetor[k] = vetorL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        imprime(vetor, tam);
        vetor[k] = vetorR[j];
        j++;
        k++;
    }
}

void merge_sort(int vetor[], int esquerdo, int direito)
{
    if (esquerdo < direito)
    {
        int meio = esquerdo + (direito - esquerdo) / 2;
        merge_sort(vetor, esquerdo, meio);
        merge_sort(vetor, meio + 1, direito);
        merge(vetor, esquerdo, meio, direito);
    }
}
// função desaloca vetor