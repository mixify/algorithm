#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;

int cache[10001];//4MB
// int solve(int current,int prev)
// {
//     int &ret = cache[current];// [prev];
//     if(current==M) return ret = 1;
//     if(current + coin[prev] > M) return ret = 0;
//     // if(ret!=-1)
//     //     return ret;
//     ret=0;
//     for (int i = prev; i < N; ++i)
//         ret+=solve(current+coin[i],i);//중복되는 것 처리 해야함..
//     return ret;
// }

int main(int argc, char *argv[])
{
    int cases;
    cin>>N>>M;
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < N; ++i) {
        int in; cin>>in;
        if(i==0)
            for (int j = 0; j <= M; j+=in)
                cache[j]++;
        else
        {
            for (int j = 0; j <= M; j++)
            {
                if(j-in>=0)
                    cache[j] = cache[j] + cache[j-in];
            }
        }
    }
    // for (int j = 0; j <= M; j++)
    // {
    //     printf("%d ", cache[j]);
    // }
    // printf("\n");
    printf("%d\n", cache[M]);
    return 0;
}

