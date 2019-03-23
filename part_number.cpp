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

void solve_problem(int case_num)
{
    vector<int> num;
    cin>>N>>M;

    memset(D,0,sizeof(D));
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; num.push_back(in);
    }
    int cnt = 0;
    for (int i = 0; i < N;++i) {
        int sum = 0;
        for (int j = i; j < N; ++j) {
            sum+=num[j];
            // printf("%d\n", sum);
            if(sum==M)
                cnt++;
            else if(sum>M)
                break;
            // printf("i = %d j = %d\n", i,j);
            // printf("-----------\n");
        }
    }
    // D[0] = 1;
    // for (int i = 0; i < N; ++i) {
    //     if(i==0) D[num[i]] = 1;
    //     for (int j = 0; j <= M; ++j) {
    //         if(j - num[i]>=0)
    //             D[j] = D[j-num[i]] + 1;
    //     }
    // }
    printf("#%d %d\n", case_num+1, cnt);
}
