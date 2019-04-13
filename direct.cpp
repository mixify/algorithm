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
vector<int> A;
int B, C;

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in;
        A.push_back(in);
    }
    cin>>B>>C;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        A[i];
        A[i]-=B;
        cnt++;
        if(A[i]>0)
        {
            // printf("cur = %d\n", A[i]);
            int s = A[i]/C;
            int r = A[i]%C;

            // printf("%d %d\n", s,r);
            // printf("sum = %d\n", s + (r>0?1:0));

            cnt += s + (r>0?1:0);
        }
    }
    printf("%d\n", cnt);
    return 0;
}

