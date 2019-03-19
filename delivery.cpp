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
int N;
vector<int> stuff;
vector<int> stuff_with_heli;
int cache[3001][3001];
int pay_truck, pay_heli;
int mid;
int total_cost(int x, int y)
{
    //first = distance, second = cost
    int &ret = cache[x][y];
    if(ret!=-1) return ret;
    if(x==y) return ret = min(stuff[x]*pay_truck, pay_heli);
    // if(x==y) return ret = 0;

    ret = INT_MAX;
    for (int k = x; k < y; ++k) {
        ret = min(ret,total_cost(x,k)+total_cost(k+1,y));
        // ret = min(ret, sum_with_heli*pay_truck + pay_heli);
        // printf("x k y = (%d %d %d)\n",x,k,y);
        // printf("ret = %d\n", ret);
    }


    // kjkjkjkjjkjkjjkjkjjjkj


    // int n=y-x+1;
    mid = /* n%2==0?stuff[(x+y)/2-1 < 0?0:(x+y)/2-1]: */stuff[(x+y)/2];
    // printf("mid = %d\n", mid);

    int sum = 0;
    int sum_heli = 0;
    for (int i = x; i <= y; ++i)
    {
        sum+=stuff[i]*pay_truck;
        sum_heli+=abs(stuff[i] - mid)*pay_truck;
        // printf("%d\n", abs(stuff[x] - mid)*pay_truck);
    }
    // printf("x y = (%d %d)\n", x,y);
    // printf("sum = %d sum_heli = %d\n",sum, sum_heli);
    ret = min(ret, min(sum,sum_heli + pay_heli));
    // printf("n = %d, mid = %d\n", n, mid);
    // int sum_with_heli = 0;
    //     sum_with_heli += abs(mid-stuff[i]);
    return ret;
}

int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; stuff.push_back(in);
    }

    //10 10 30 40 50
    //5/2 = 2;
    sort(stuff.begin(),stuff.end());
    cin>>pay_truck>>pay_heli;

    // int sum = 0;
    // int sum_by_heli = 0;
    // int ret;
    // for (int i = 0; i < N; ++i) {
    //     sum += stuff[i] * pay_truck;
    //     sum_by_heli += stuff_with_heli[i] * pay_truck;
    //     if(sum > sum_by_heli + pay_heli)
    //         ret = sum_by_heli + pay_heli;
    //     else
    //         ret = sum;
    // }
    // printf("%d\n", ret);
    memset(cache,-1,sizeof(cache));
    printf("%d\n", total_cost(0,N-1));
    return 0;
}
