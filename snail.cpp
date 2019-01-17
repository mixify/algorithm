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
const double p_s = 0.25;
const double p_r = 0.75;
int N, M;
double cache[2002][1001];
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

double escape(int depth, int day)
{
    double &ret = cache[depth][day];
    if(ret >= 0)
        return ret;
    if(depth >= N)
        return ret = 1;
    if(day == M)
        return ret = 0;

    if((M-day) * 2 + depth < N)
        return ret = 0;

    return ret = p_s*escape(depth+1,day+1) + p_r*escape(depth+2, day+1);
}


void solve_problem(int case_num)
{
    cin>>N>>M;
    double a;
    // memset(&a, -1, sizeof(a));
    // printf("%lf\n", a);
    memset(cache, -1, sizeof(cache));
    printf("%.7lf\n",escape(0,0));
}

