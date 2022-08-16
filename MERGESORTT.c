#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 8
void imprimeVetor(int vetor[])
{
    printf("\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
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
    i = 0; // erro estava aqui aparentemente entrei com i,j=0; apos mudança funcionou.
    j = 0;
    k = esquerdo;

    while (i < n1 && j < n2)
    {
        if (vetorL[i] <= vetorR[j])
        {
            imprimeVetor(vetor);
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
        imprimeVetor(vetor);
        vetor[k] = vetorL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        imprimeVetor(vetor);
        vetor[k] = vetorR[j];
        j++;
        k++;
    }
}

void merge_sort(int vetor[TAM], int esquerdo, int direito)
{
    if (esquerdo < direito)
    {
        int meio = esquerdo + (direito - esquerdo) / 2;
        merge_sort(vetor, esquerdo, meio);
        merge_sort(vetor, meio + 1, direito);
        merge(vetor, esquerdo, meio, direito);
    }
}

int main(int argc, char **argv)
{
    int vetor[TAM] = {3, 0, 7, 1, 5, 2, 4, 6}; // colocar o TAM DO VETOR
    imprimeVetor(vetor);
    merge_sort(vetor, 0, TAM - 1);
    imprimeVetor(vetor);
    return 0;
}
