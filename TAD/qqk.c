#include "TAD_sort.h"

int main()
{
    double time_spent = 0.0;

    long int tamanho;
    printf("Tamanho: ");
    scanf("%ld", &tamanho);
    Float_Vector *vetor = alocavetor(tamanho);

    imprimeVetor(vetor, tamanho);

    quick_sort(vetor, 0, tamanho - 1, tamanho);
    clock_t begin = clock();

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f seconds", time_spent);
    free(vetor);

    return 0;
}

// OBS TENTEI MUITO FAZER FUNCIONAR DESSE JEITO.