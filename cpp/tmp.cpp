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

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases = 100;
    for (int i = 0; i < cases; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j==i)
            printf("%d", j);
            else
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}

