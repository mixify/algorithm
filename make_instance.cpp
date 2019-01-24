#include <stdio.h>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    int N, seed;
    scanf("%d", &N);
    scanf("%d", &seed);
    srand(seed);
    printf("%d\n", N);
    for (int i = 0; i < N; ++i)
    {
        printf("%d ",(int)rand()%1000-(int)rand()%2000);
    }
    return 0;
}
