#include <stdio.h>
#include <cstring>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int num;
// int cache[101][101][1000];
int cache[1000001];
int solve1(int num, int d3_count, int d2_count, int m_count);
int solve2(int n, int d3_count, int d2_count, int m_count);
int main(int argc, char *argv[])
{
    cin>>num;
    memset(cache, -1, sizeof(cache));
    printf("%d\n",solve2(num, 0,0,0) );
    return 0;
}

// int solve1(int n, int d3_count, int d2_count, int m_count)
// {
//     int &ret = cache[d3_count][d2_count][m_count];
//     if(ret!=-1) return ret;
//     // int ret;
//     if(n < 1)
//         return ret = 1000000;
//     if(n == 1)
//         return ret = d3_count + d2_count + m_count;
//
//     int c1 = 1000000, c2 = 1000000, c3 = 1000000;
//     if(n%3==0)
//         c1 = solve(n/3,d3_count+1, d2_count, m_count);
//     if(n%2==0)
//         c2 = solve(n/2,d3_count, d2_count+1, m_count);
//     if(m_count < 1000)
//         c3 = solve(n-1,d3_count, d2_count, m_count+1);
//
//
//     return ret = min(min(c1,c2),c3);
// }
int solve2(int n, int d3_count, int d2_count, int m_count)
{
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;
    for (int i = 4; i <= n; ++i) {
        // int &ret = cache[i];
        int r1 = 1000, r2 = 1000, r3 = 1000;
        if(i%2==0)
            r1 = cache[i/2]+1;
        if(i%3==0)
            r2 = cache[i/3]+1;
        r3 = cache[i-1]+1;
        // printf("%d => %d %d %d\n", i,r1,r2,r3);
        cache[i] = min(min(r1,r2),r3);
    }
    return cache[n];
}
