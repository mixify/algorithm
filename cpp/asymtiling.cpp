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
// int asymtiling(int pos)
// {
//
// }

void solve_problem(int case_num)
{
    cin>>N;
    int tile[101];
    int asym_tile;
    tile[1] = 1;
    tile[2] = 2;
    for (int i = 3; i <= N; ++i) {
        tile[i] = tile[i-2]+tile[i-1];
        tile[i]%=1000000007;
    }
    if(N==0)
    {
        printf("0\n");
        return;
    }
    if(N%2)
        asym_tile = tile[N] - tile[N/2];
    else
        asym_tile = tile[N] - tile[N/2+1];
    if(asym_tile < 0)
        asym_tile+=1000000007;
    printf("%d\n", asym_tile);
    // asymtiling(0);
}
