#include <stdio.h>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    int N,M, seed;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &seed);
    srand(seed);
    printf("%d\n", N);
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                char cch = 'A' + rand()%26;
                printf("%c",cch);
            }
            printf("\n");
        }
        printf("%d\n",M);
        for (int i = 0; i < M; ++i)
        {
            int size = (int)rand()%9+1;
            for (int j = 0; j < size; ++j) {
                char cch = 'A' + rand()%25;
                printf("%c",cch);
            }
            printf("\n");
        }
    }

    return 0;
}
