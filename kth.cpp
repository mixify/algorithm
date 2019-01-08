#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
    int N, K;
    vector <int> sorted;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        sorted.push_back(num);
    }
    sort(sorted.begin(),sorted.end());
    printf("%d\n", sorted[K-1]);
}

