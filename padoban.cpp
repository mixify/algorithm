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

void solve_problem(int case_num)
{
    int cache[100] = {1,1,1,2,2,3,4,5,7,9,12,16};
    cin>>N;
    for (int i = 5; i < N; ++i) {
        cache[i] = cache[i-1]+cache[i-5];
    }
    printf("%d\n", cache[N-1]);
}
