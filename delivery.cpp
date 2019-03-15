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
int N;
vector<int> stuff;
int cache[3001][3001];
int pay_truck, pay_heli;
int total_cost(int x, int y)
{
    int &ret = cache[x][y];
    if(ret!=-1) return ret;
    if(x==y) return ret = stuff[x];

    ret = INT_MAX;
    for (int k = x; k < y; ++k) {
        ret = min(ret, );
    }

    return ret;
}

int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; stuff.push_back(in);
    }

    cin>>pay_truck>>pay_heli;
    memset(cache,-1,sizeof(cache));
    printf("%d\n", total_cost(0,N-1));
    return 0;
}
