#include <stdio.h>
#include <stdlib.h>
#define TAM 8

// Função para troca entre os numeros
void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// função q verifica se será necessario realizar a troca
void bubble(int vetor[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                imprime(vetor);
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
    }
    imprime(vetor);
}
// função para imprimir os numeros do vetor na tela
void imprime(int vetor[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// função main
int main()
{
    int vetor[TAM] = {3, 1, 5, 6, 7, 2, 2, 3};
    bubble(vetor);

    return 0;
}