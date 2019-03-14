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
vector<int> candy_price;
vector<vector<int> > candy;

bool prime_array[500001];
// long long cache[51][500001];// [500000];
long long cache1[500001];// [500000];
long long cache2[500001];// [500000];
// cache<int,int>

void eratos(int n)
{
    if(n<=1) return;

    for (int i = 2; i <= n; ++i)
        prime_array[i] = true;
    for (int i = 2; i*i <= n; ++i) {
        if(prime_array[i])
            for (int j = i*i; j <= n; j+=i) {
                prime_array[j] = false;
            }
    }
}
// int cases = 0;
// long long D(int idx, int count, int value)
// {
//     long long &ret = cache[idx][value];
//     if(ret != -1){
//         return ret;
//     }
//     if(idx==candy.size())
//     {
//         if(prime_array[value])
//         {
//             // printf("prime : %d\n", value);
//             return ret=1;
//         }
//         else
//             return ret=0;
//     }
//     ret=D(idx+1,0,value);
//     for (int i = 0; i < candy[idx].size(); ++i) {
//         int added_value = value + candy[idx][i];
//         ret+=D(idx+1,i+1,added_value);
//     }
//     return ret;
// }
int main(int argc, char *argv[])
{
    eratos(500000);
    cin>>N;
    int sum_value = 0;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; candy_price.push_back(in);
        sum_value += in;
    }
    for (int i = 0; i < N; ++i) {
        int amount = 1;
        if(candy_price[i]==-1)
            continue;
        candy.push_back(vector<int>());
        candy[candy.size()-1].push_back(candy_price[i]);
        for (int j = i+1; j < N; ++j) {
            if(candy_price[i] == candy_price[j])
            {
                candy[candy.size()-1].push_back(candy_price[i]*(++amount));
                candy_price[j]=-1;
            }
        }
    }

    // memset(cache,-1,sizeof(cache));
    memset(cache2,0,sizeof(cache1));
    memset(cache1,0,sizeof(cache2));

    cache2[0]=1;
    for (int i = 0; i < candy.size(); ++i)
    {
        for (int j = 0; j < candy[i].size(); ++j) {
            int in = candy[i][j];
            if(i==0)
                cache2[in]++;
            else
            {
                // cache2[in]++;
                for (int k = 0; k <= sum_value; ++k) {
                    if(k-in>=0)
                        cache2[k] = cache2[k] + cache1[k-in];
                }
            }
        }
        // for (int k = 0; k <= sum_value; ++k)
        //     printf("%d ",k);
        // printf("\n-----------------------\n");
        // for (int k = 0; k <= sum_value; ++k)
        //     printf("%d ",cache2[k]);
        // printf("\n\n");
        memcpy(cache1,cache2,sizeof(cache1));
    }
    long long p_count = 0;
    for (int i = 0; i <= sum_value; ++i) {
        if(prime_array[i])
        {
            // printf("%d : %d\n", i, cache1[i]);
            p_count+=cache1[i];
        }
    }
    printf("%lld\n", p_count);
    // printf("%lld\n", D(0,0,0));
    return 0;
}
