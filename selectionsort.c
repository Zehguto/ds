#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TAM 8

void imprime(int vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
void ss(int vetor[TAM])
{
    int positioninicital, j, i;
    for (int i = 0; i < TAM; i++)
    {
        positioninicital = i;

        for (int j = i + 1; j < TAM; j++)
        {
            if (vetor[j] < vetor[positioninicital])
            {
                positioninicital = j;
            }
        }
        if (positioninicital != i)
        {
            imprime(vetor);
            swap(&vetor[i], &vetor[positioninicital]);
        }
    }
}
int main()
{
    double time_spent = 0.0;
    clock_t begin = clock();

    clock_t end = clock();

    time_spent + -(double)(end - begin) / CLOCKS_PER_SEC;
    int vetor[TAM] = {1, 2, 3, 4, 7, 0, 3, 2};
    ss(vetor);

    printf("%f seconds", time_spent);

    return 0;
}