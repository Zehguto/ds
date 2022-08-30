#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct float_vector Float_Vector;
Float_Vector *alocavetor(long int tamanho);
void desaloca_vetor(Float_Vector **ptrvet);
void imprimeVetor(Float_Vector *ptrvet, long int tamanho);
void swap(long int *valor_a, long int *valor_b);
void quick_sort(Float_Vector *ptrvet, long int inicio, long int fim, long int tamanho);

/**
 *  @brief Estrutura dos veteores ultilizados nos algoritimos.
 *
 *  @param tam Capacidade do ptrvet
 *
 */

struct float_vector
{
    long int tamanho;
    long int size;  // numero máximo de elementos
    float *valores; // ptrvet de floats
};

/**
 *  @brief Função para alocar um ptrvet de floats.
 *
 *  @param tamanho, tipo long int, recebe o tamanho do ptrvet de floats a ser alocado;
 *
 */

Float_Vector *alocavetor(long int tamanho)
{

    Float_Vector *ptrvet = (Float_Vector *)calloc(1, sizeof(Float_Vector));
    ptrvet->tamanho = tamanho;
    ptrvet->size = 0;
    ptrvet->valores = (float *)calloc(ptrvet->tamanho, sizeof(float));
    srand(time(NULL));
    for (long int i = 0; i < tamanho; i++)
    {
        float v = rand() % tamanho;
        ptrvet->valores[ptrvet->size++] = v;
    }
    if (ptrvet != NULL)
    {
        printf("ALOCADO");
    }
    return ptrvet;
}
/*void append(Float_Vector *vector, float n)
{
    if (_isFull(vector))
    {
        // ERROR
        fprintf(stderr, "Error in append\nVector is full!");
        exit(EXIT_FAILURE);
    }
    // inserir
    vector->valores[vector->size++] = n;
}*/
/**
 *  @brief Função para desalocar um ptrvet de floats.
 *
 *  @param ptrvet, um ponteiro para o ptrvet de floats;
 *
 */

void desaloca_ptrvet(Float_Vector **ptrvet)
{
    Float_Vector *ptr = *ptrvet;
    free(ptr->valores); // Liberamos a casa do ptrvet
    free(ptr);
    *ptrvet = NULL;
    if (ptr != NULL) // Liberamos a estrutura
        printf("\nDesaloca ptrvet");
    else
        printf("\nDesaloca");
}

/**
 *  @brief Função para imprimir um ptrvet de floats.
 *
 *  @param ptrvet, um ponteiro para o ptrvet de floats;
 *
 */

void imprimeVetor(Float_Vector *ptrvet, long int tamanho)
{
    Float_Vector *ptr = ptrvet;
    long int i;
    printf("\n ");
    for (i = 0; i < tamanho; i++)
    {
        printf("| %f |", ptr->valores[i]);
    }
}

/**
 *  @brief Função para realizar o swap entre os numeros nos algoritimos.
 *
 *  @param valor_a, recebe um dos valores a ser trocado;
 *  @param valor_b, recebe um dos valores a ser trocado;
 *
 */

void swap(long int *valor_a, long int *valor_b)
{
    long int aux;
    aux = *valor_a;
    *valor_a = *valor_b;
    *valor_b = aux;
}

void quick_sort(Float_Vector *ptrvet, long int inicio, long int fim, long int tamanho)
{
    imprimeVetor(ptrvet, tamanho);
    printf("quick sort");
    long int pivo, esq, dir, meio, aux;
    Float_Vector *ptr = ptrvet;

    // Limites da esquerda e direita da região analisada
    esq = ptr->valores[inicio];
    printf("\n%ld\n", esq);

    dir = ptr->valores[fim];
    printf("\n%ld\n", dir);
    // Ajustando auxiliares do centro
    meio = (int)((esq + dir) / 2);
    pivo = ptr->valores[meio];

    while (dir > esq)
    {

        while (ptr->valores[esq] < pivo)
        {
            esq = esq + 1;
        }

        while (ptr->valores[dir] > pivo)
        {
            dir = dir - 1;
        }

        if (esq <= dir)
        {

            // Realiza uma troca
            aux = ptr->valores[esq];
            ptr->valores[esq] = ptr->valores[dir];
            ptr->valores[dir] = aux;

            // Faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;
        }
    }

    // Recursão para continuar ordenando
    if (inicio < dir)
    {
        quick_sort(ptr, inicio, dir, tamanho);
    }

    // Recursão para continuar ordenando
    if (esq < fim)
    {
        quick_sort(ptr, esq, fim, tamanho);
    }
}