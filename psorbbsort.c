#include <stdlib.h>
#include <stdio.h>

int main()
{

    int vet = {7, 3, 0, 1, 3, 8, 2, 9};
    int sup;
    bbsort(vet, 8);

    return 0;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
void bbsort(int vector[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (vector[i] > vector[i + 1])
            {
                swap(&vector[i], &vector[i + 1]);
            }
        }
    }
}
void printvector()
{
    // dadadada
}