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
vector<int> coin;

int cache[10000][100];
int solve(int current,int prev)
{
    int &ret = cache[current][prev];
    if(ret!=-1) return ret;
    if(current==M) return ret = 1;
    if(current>M) return ret = 0;
    ret=0;
    for (int i = 0; i < coin.size(); ++i)
    {
        if(coin[i]>=coin[prev])
            ret+=solve(current+coin[i],i);
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int cases;
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; coin.push_back(in);
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", solve(0,0));
    return 0;
}

