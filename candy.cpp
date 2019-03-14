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
long long cache[51][500001];// [500000];
// long long cache[500001];// [500000];
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
long long D(int idx, int count, int value)
{
    long long &ret = cache[idx][value];
    if(ret != -1){
        return ret;
    }
    if(idx==candy.size())
    {
        if(prime_array[value])
            return ret=1;
        else
            return ret=0;
    }
    ret=D(idx+1,0,value);
    for (int i = 0; i < candy[idx].size(); ++i) {
        int added_value = value + candy[idx][i];
        ret+=D(idx+1,i+1,added_value);
    }
    return ret;
}
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
                candy[i].push_back(candy_price[i]*(++amount));
                candy_price[j]=-1;
            }
        }
    }

    memset(cache,-1,sizeof(cache));

    // cache[0]=1;
    // for (int i = 0; i < candy.size(); ++i)
    // {
    //         for (int j = 0; j < candy[i].size(); ++j) {
    //             int in = candy[i][j];
    //             if(i==0)
    //                 cache[in]++;
    //             else
    //                 for (int k = 0; k < sum_value; ++k) {
    //                     if(k-in>=0)
    //                         cache[k] = cache[k] + cache[k-in];
    //                 }
    //         }
    //         // for (int i = 0; i < candy.size(); ++i) {
    //         //     for (int j = 0; j < candy[i].size(); ++j) {
    //         //         printf("%d ", candy[i][j]);
    //         //     }
    //         //     printf("\n");
    //         // }
    //         // printf("\n");
    //
    //
    printf("%lld\n", D(0,0,0));
    //         // calc(0);
    // }
    // for (int i = 0; i < sum_value; ++i) {
    //     printf("%d\n",cache[i]);
    // }
    return 0;
}
