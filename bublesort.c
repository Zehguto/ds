#include <stdio.h>
#include <stdlib.h>
#include "bublesort.h"

// função main
int main()
{
    int num;
    num = entraComTamanhovet();
    int vetor[num];
    for (int i = 0; i < num; i++)
    {
        vetor[i] = rand() % num;
    }
    bubble(vetor, num);

    return 0;
}