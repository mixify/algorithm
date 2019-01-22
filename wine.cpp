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
vector<int> wine;
int cache[10001][3];
int N, M;

int solve_problem(int idx,int cnt)
{
    if(cnt>=3) return 0;
    if(idx>=N) return 0;
    if(idx==N-1) return wine[idx];
    int &ret = cache[idx][cnt];
    if(ret!=-1) return ret;
    // ret = 0;
    return ret = wine[idx] + max(solve_problem(idx+1,cnt+1), solve_problem(idx+2,1));
}
int main(int argc, char *argv[])
{
    int cases;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; wine.push_back(in);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve_problem(0,1));
    return 0;
}

