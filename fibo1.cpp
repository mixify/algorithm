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

pair<int,int> cache[40];
pair<int,int> fibonacci(int n);
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
    int num;
    cin>>num;
    memset(cache,-1,sizeof(cache));
    pair<int,int> ret = fibonacci(num);
    printf("%d %d\n", ret.first, ret.second);
}

pair<int,int> fibonacci(int n) {
    pair<int,int> &ret = cache[n];
    if(ret.first != -1 && ret.second != -1)
        return ret;
    if (n == 0) {
        ret.first = 1;
        ret.second = 0;
        return ret;
    } else if (n == 1) {
        ret.first = 0;
        ret.second = 1;
        return ret;
    } else {
        ret.first = fibonacci(n-1).first+ fibonacci(n-2).first;
        ret.second = fibonacci(n-1).second+ fibonacci(n-2).second;
        return ret;
    }
}
