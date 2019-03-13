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
    // ret = 0;
    if(idx==candy.size())
    {
        if(prime_array[value])
            return ret=1;
        else
            return ret=0;
    }

        // if(prime_array[added_value])
    ret=D(idx+1,0,value);
    for (int i = 0; i < candy[idx].size(); ++i) {
        int added_value = value + candy[idx][i];
        // if(prime_array[added_value])
        //     ret++;
        ret+=D(idx+1,i+1,added_value);
    }
    return ret;
}
// int D(int idx)
// {
//     int &ret = cache[idx];
//     if(ret!=-1) return ret;
// }
int main(int argc, char *argv[])
{
    eratos(500000);
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; candy_price.push_back(in);
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
    // for (int i = 0; i < candy.size(); ++i) {
    //     for (int j = 0; j < candy[i].size(); ++j) {
    //         printf("%d ", candy[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    memset(cache,-1,sizeof(cache));

    printf("%lld\n", D(0,0,0));
    // calc(0);
    return 0;
}
