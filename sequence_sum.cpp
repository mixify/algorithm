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
int cache[100000];
vector<int> sequence;

int sequence_sum(int idx)
{
    int &ret = cache[idx];
    if(idx == N-1) return ret = sequence[idx];
    if(ret!=-1) return ret;
    int sum;
    sum=ret=0;
    if(idx==0)
        for (int i = idx; i < N-1; ++i)
        {
            sum+=sequence[i];
            ret = max(sum, sum+sequence_sum(i+1));
            M = max(M,ret);
        }
    else
    {
        sum+=sequence[idx];
        ret = max(sum, sum+sequence_sum(idx+1));
        M = max(M,ret);
    }
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; sequence.push_back(in);
    }
    memset(cache,-1,sizeof(cache));
    sequence_sum(0);
    printf("%d\n", M);
    return 0;
}

