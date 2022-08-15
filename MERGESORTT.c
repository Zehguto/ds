#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 8
void imprimeVetor(int vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d \n", vetor[i]);
    }
}

void merge(int vetor[TAM], int esquerdo, int meio, int direito)
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
    i, j = 0;
    k = esquerdo;

    while (i < n1 && j < n2)
    {
        if (vetorL[i] <= vetorR[j])
        {
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
        vetor[k] = vetorL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vetor[k] = vetorL[j];
        j++;
        k++;
    }
}

void merge_sort(int vetor[TAM], int esquerdo, int direito)
{
    if (esquerdo < direito)
    {
        int meio = esquerdo + (direito - esquerdo) / 2;
        merge_sort(vetor, meio, direito);
        merge_sort(vetor, meio + 1, direito);
        merge(vetor, esquerdo, meio, direito);
    }
}

int main(int argc, char **argv)
{
    int vetor[] = {3, 0, 7, 1, 5, 2, 4, 6};
    imprimeVetor(vetor);
    merge_sort(vetor, 0, TAM);
    imprimeVetor(vetor);
    return 0;
}