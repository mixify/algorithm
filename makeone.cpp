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
int cache[101][101][1000];
int solve(int num, int d3_count, int d2_count, int m_count);
int main(int argc, char *argv[])
{
    cin>>num;
    memset(cache, -1, sizeof(cache));
    printf("%d\n",solve(num, 0,0,0) );
    return 0;
}

int solve(int n, int d3_count, int d2_count, int m_count)
{
    int &ret = cache[d3_count][d2_count][m_count];
    if(ret!=-1) return ret;
    // int ret;
    if(n < 1)
        return ret = 1000000;
    if(n == 1)
        return ret = d3_count + d2_count + m_count;

    int c1 = 1000000, c2 = 1000000, c3 = 1000000;
    if(n%3==0)
        c1 = solve(n/3,d3_count+1, d2_count, m_count);
    if(n%2==0)
    c2 = solve(n/2,d3_count, d2_count+1, m_count);
    if(m_count < 1000)
    c3 = solve(n-1,d3_count, d2_count, m_count+1);


    return ret = min(min(c1,c2),c3);
}
