
// Função para troca entre os numeros
int entraComTamanhovet()
{
    int numero;
    printf("Entre com o numanho do vetor: ");
    scanf("%d", &numero);
    printf("\n");
    return numero;
}
void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// função para imprimir os numeros do vetor na tela
void imprime(int vetor[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// função q verifica se será necessario realizar a troca
void bubble(int vetor[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                imprime(vetor, num);
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
    }
    imprime(vetor, num);
}
// obs: a função imprime deve vir antes para nao dar erro, ao chamar a msm no bubble
