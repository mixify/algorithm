#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int post_calc_fibo(int idx);
int main(int argc, char *argv[])
{
    long long idx;
    cin>>idx;

    long long num = post_calc_fibo(idx%1500000);
    printf("%lld\n", num);
    return 0;
}

int post_calc_fibo(int idx)
{
    int n;
    int pibo[1500000] = {0,1};
    for (int i = 2; i <= idx; ++i) {
        pibo[i] = pibo[i-1] + pibo[i-2];
        pibo[i] %= 1000000;
    }

    return pibo[idx];
}
