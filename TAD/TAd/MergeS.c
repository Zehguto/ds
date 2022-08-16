
#include "sort.h"

int main()
{
    int tam;

    // Lendo o tamanho do vetor
    printf("Digite um tamanho");
    scanf("%d", &tam);

    int vetor[tam];
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % tam;
    }

    imprime(vetor, tam);
    merge_sort(vetor, 0, tam - 1);
    imprime(vetor, tam);
}
