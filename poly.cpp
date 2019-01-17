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

int cache[101][101][101];
void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

int poly(int idx, int allocate, int amount)
{
    int &ret = cache[idx][allocate][amount];
    if(ret != -1) return ret;
    if(allocate == N)
        return 1;
    if(allocate > N)
        return 0;
    // if(idx >= N) return 0;
    ret = 0;
    for (int i = 1; i <= N-idx; ++i) {
        if(amount>0)
            ret += (amount + i -1) * poly(idx+1,allocate+i, i);
        else
            ret += poly(idx+1,allocate+i, i);
        ret %= 10000000;
    }
    // printf("%d,%d => %d\n",idx,allocate,ret);
    return ret;
}
void solve_problem(int case_num)
{
    cin>>N;
    memset(cache, -1, sizeof(cache));
    printf("%d\n", poly(0,0, 0));
}
