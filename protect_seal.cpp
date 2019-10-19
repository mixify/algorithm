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
int D, W, K;

int seal[14][21];

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

bool check_seal(int seal[14][21])
{
    // for (int i = 0; i < D; ++i)
    // {
    //     for (int j = 0; j < W; ++j)
    //         printf("%d ", seal[i][j]);
    // printf("\n");
    // }
    for (int i = 0; i < W; ++i) {
        bool pass = false;
        for (int j = 0; j < D-K+1; ++j) {
            bool appropriate = true;
            for (int k = 0; k < K-1; ++k) {
                // printf("%d %d\n", j+k,j+k+1);
                if(seal[j+k][i] != seal[j+k+1][i])
                {
                    appropriate = false;
                    break;
                }
            }
            // printf("\n");
            if(appropriate)
            {
                pass = true;
                break;
            }
        }
        if(!pass) return false;
    }
    return true;
}

void solve_problem(int case_num)
{
    cin>>D>>W>>K;

    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < W; ++j) {
            cin>>seal[i][j];
        }
    }
    int cases = pow(3,D);
    int applied_seal[14][21];
    int min_apply = 100;

    // check_seal(seal);
    for (int i = 0; i < cases; ++i) {
        int n = i;
        int cnt = 0;
        memcpy(applied_seal,seal,sizeof(seal));
        for (int j = 0; j < D; ++j) {
            int div = n%3;
            if(div!=0)
            {
                cnt++;
                for(int &s : applied_seal[j])
                    s = div-1;
            }
            n/=3;
        }
        if(check_seal(applied_seal))
        {
            // printf("true\n");
            min_apply = min(cnt,min_apply);
        }
        else
        {
            // printf("false\n");
        }

        // printf("\n");

    }
    printf("#%d %d\n", case_num+1,min_apply);
}
