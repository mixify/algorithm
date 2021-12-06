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
vector<int> stuff;

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
long long solve(int x, int y, int big)
{
    if(y>=stuff.size() || x==y) return 0;
    long long init = 0;
    for (int i = x; i < y; ++i) {
        init += big-stuff[i];
    }
    int m = -1;
    int m_idx = y+1;
    for (int i = y+1; i < stuff.size(); ++i) {
        if(stuff[i] > m)
        {
            m = stuff[i];
            m_idx = i;
        }
    }
    init += solve(y+1,m_idx,m);
    return init;
}

void solve_problem(int case_num)
{
    cin>>N;
    int m = -1;
    int m_idx;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; stuff.push_back(in);
        // if(in > m)
        // {
        //     m = in;
        //     m_idx = i;
        // }
    }
    int best = stuff[N-1];
    long long sum = 0;
    for (int i = N-2; i >= 0; --i) {
        if(best < stuff[i])
        {
            best = stuff[i];
            continue;
        }
        else
        {
            sum+=best - stuff[i];
        }
    }
    // printf("#%d %lld\n", case_num+1, solve(0,m_idx,m));
    printf("#%d %lld\n", case_num+1, sum);
    stuff.clear();
}
