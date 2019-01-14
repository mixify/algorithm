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
int cache[100][100][100];

void solve_problem(int case_num);
int onetwothree(int n, int one, int two, int three);
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
    int n;
    cin>>n;
    memset(cache,-1, sizeof(cache));
    printf("%d\n", onetwothree(n,0,0,0));
}

int onetwothree(int n, int one, int two, int three)
{
    int &ret = cache[one][two][three];
    if(ret!=-1)
    {
        printf("sibal\n");
        return ret;
    }

    if(one + 2*two + 3*three == n)
        return 1;
    else if(one + 2*two + 3*three > n)
        return 0;

    return ret = onetwothree(n,one+1,two,three) + onetwothree(n,one,two+1,three) + onetwothree(n,one,two,three+1);
}
