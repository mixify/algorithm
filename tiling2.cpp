#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int N;
int cache[101];
// int square[2][100];

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}
// int tiling(int pos)
// {
//     int &ret = cache[pos];
//     if(ret!=-1) return ret;
//     if(pos == 1)
//         return 1;
// }

void solve_problem(int case_num)
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        if(i==0)
            cache[i] = 1;
        else if(i==1)
            cache[i] = 2;
        else
            cache[i] = (cache[i-1] + cache[i-2]) % 1000000007;
    }
    printf("%d\n", cache[N-1]);
    // printf("%d\n", tiling(N));
}

