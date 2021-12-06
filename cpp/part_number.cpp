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
int D[1001];

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
    vector<int> num;
int Dynamic(int idx, int sum)
{
    if(sum == M)
        return 1;
    if(idx==N)
    {
        return 0;
    }
    int ret;
    ret = Dynamic(idx+1,sum) + Dynamic(idx+1, sum+num[idx]);
    return ret;
}

void solve_problem(int case_num)
{
    cin>>N>>M;

    memset(D,-1,sizeof(D));
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; num.push_back(in);
    }
    // D[0] = 1;
    // for (int i = 0; i < N; ++i) {
    //     if(i==0) D[num[i]] = 1;
    //     for (int j = 0; j <= M; ++j) {
    //         if(j - num[i]>=0)
    //             D[j] = D[j-num[i]] + 1;
    //     }
    // }
    printf("#%d %d\n", case_num+1, Dynamic(0,0));
    num.clear();
}
