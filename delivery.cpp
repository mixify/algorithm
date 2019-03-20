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
// vector<int> stuff_with_heli;
// int cache[3001][3001];
int cache2[3001];
// int summation[3001][3001];
// int summation_heli[3001][3001];
int pay_truck, pay_heli;
int mid;

int heli()
{
    +
}
int total_cost(int y)
{
    int &ret = cache2[y];
    ret = INT_MAX;
    for (int i = y; i > 0; --i)
    {
        ret = min(ret, total_cost(i) + heli(y,i));
    }

    for (int i = 1; i <= N; ++i) {
        cache2[i] = cache2[i-1] + stuff[i]*pay_truck;
        int cost = pay_heli;
        for (int j = i; j > 0; --j) {
            int mid = (i+j+1)/2;
            // printf("%d\n", stuff[mid]-stuff[j]);
            cost += (stuff[mid]-stuff[j]) * pay_truck;
            // printf("i = %d, j = %d\n", i, j);
            // printf("%d vs %d + %d\n",cache2[i], cache2[j-1], cost);
            cache2[i] = min(cache2[i], cache2[j-1] + cost);
            // cache2[i] = min(cache2[i], summation_heli[0][j]*pay_truck + pay_heli + summation[j][i] * pay_truck);
        }
    }

}
// int total_cost(int x, int y)
// {
//     // int &ret = cache[x][y];
//     int &ret = cache2[x];
//     if(ret!=-1) return ret;
//     // if(x==y) return ret = min(stuff[x]*pay_truck, pay_heli);
//     if(y==N) return ret = 0;
//
//     ret = INT_MAX;
//     // for (int k = x; k < y; ++k) {
//     //     ret = min(ret,total_cost(x,k)+total_cost(k+1,y));
//     // }
//     ret = min(ret, total_cost(x,y+1));
//
//     int sum = summation[x][y] * pay_truck;
//     int sum_heli = summation_heli[x][y] * pay_truck + pay_heli;
//     ret = min(ret, min(sum,sum_heli));
//     return ret;
// }

int main(int argc, char *argv[])
{
    cin>>N;
    stuff.push_back(0);
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; stuff.push_back(in);
    }

    sort(stuff.begin()+1,stuff.end());
    cin>>pay_truck>>pay_heli;

    // for (int i = 0; i < N; ++i) {
    //     for (int j = i; j < N; ++j) {
    //         mid = stuff[(i+j)/2];
    //         if(i==j) {summation[i][j] = stuff[i]; summation_heli[i][j] = abs(stuff[i]-mid);}
    //         else
    //         {
    //             summation[i][j] = summation[i][j-1] + stuff[j];
    //             summation_heli[i][j] = summation_heli[i][j-1] + abs(stuff[j]-mid);
    //         }
    //     }
    // }
    // memset(cache,-1,sizeof(cache));
    memset(cache2,0,sizeof(cache2));
    // for (int i = 0; i < N; ++i) {
    //     for (int j = i; j < N; ++j) {
    //
    //     }
    // }
    // int &ret = cache[x][y];
    // int &ret = cache2[x];
    // if(ret!=-1) return ret;
    // if(x==N) return ret = 0;
    // ret = INT_MAX;
    // for (int i = 1; i <= N; ++i) {
    //     cache2[i] = cache2[i-1] + stuff[i]*pay_truck;
    //     int cost = pay_heli;
    //     for (int j = i; j > 0; --j) {
    //         int mid = (i+j+1)/2;
    //         // printf("%d\n", stuff[mid]-stuff[j]);
    //         cost += (stuff[mid]-stuff[j]) * pay_truck;
    //         // printf("i = %d, j = %d\n", i, j);
    //         // printf("%d vs %d + %d\n",cache2[i], cache2[j-1], cost);
    //         cache2[i] = min(cache2[i], cache2[j-1] + cost);
    //         // cache2[i] = min(cache2[i], summation_heli[0][j]*pay_truck + pay_heli + summation[j][i] * pay_truck);
    //     }
    // }

    // for (int k = x; k < y; ++k) {
    //     ret = min(ret,total_cost(x,k)+total_cost(k+1,y));
    // }
    // ret = min(ret, total_cost2(x+1));

    // printf("%d\n", total_cost2(0));
    printf("%d\n", cache2[N]);

    // printf("%d\n", total_cost(0,N-1));
    return 0;
}
