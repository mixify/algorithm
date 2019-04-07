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

int forest[501][501];
int cache[501][501];
using namespace std;
int N;

int eat(int y, int x, int leaves)
{
    int &ret = cache[y][x];

    if(leaves >= forest[y][x])
        return 0;
    leaves = forest[y][x];
    if(ret!=-1) return ret;

    return ret = 1 + max(max(eat(y,x-1,leaves),eat(y,x+1,leaves)),max(eat(y-1,x,leaves),eat(y+1,x,leaves)));
}

int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d",&forest[i][j]);
        }
    }

    memset(cache,-1,sizeof(cache));

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans = max(ans,eat(i,j,0));
        }
    }
    printf("%d\n", ans);
    return 0;
}

