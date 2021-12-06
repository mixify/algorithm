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
    if(idx == N-1) {
        ret = sequence[idx];
        M = max(ret,M);
        return ret;
    }
    if(ret!=-1) return ret;
    int sum;
    sum=ret=-2000;
    // if(idx==0)
    // {
    //     sum=sequence[i];
    //     ret = max(sum, sum+sequence_sum(i+1));
    //     M = max(M,ret);
    // }
    // else
    // {
    sum=sequence[idx];
    ret = max(sum, sum+sequence_sum(idx+1));
    M = max(M,ret);
    // }
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; sequence.push_back(in);
    }
    M=-2000;
    memset(cache,-1,sizeof(cache));
    sequence_sum(0);
    if(N==1)
        printf("%d\n", sequence[0]);
    else
        printf("%d\n", M);
    return 0;
}

