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

int cache[11][11];
int result[11][11][101];

// long long stair_num(int start, int end, int size)
// {
//     // long long &ret = cache[start][end];
//     int ret;
//     if(ret!=-1)
//         return ret;
//
//     if(size==N)
//         return ret = start-end+1;
//
//     if(end == 9)
//     {
//         //up delete 1
//         end--;
//         // stair_num(start,8,size+1);
//     }
//     if(start == 0)
//     {
//         start++;
//         //down delete 1
//     }
//     // ret = v_up.size() + v_down.size();
//     // ret = stair_num(,size+1) + stair_num(v_down,size+1);
//     ret %= 1000000000;
//     return ret;
// }
int solve(int start, int end, int size)
{
    int& ret = result[start][end][size];
    if(ret!=-1)
        return ret;
    if(size == N-1)
        return ret = cache[start][end];
    // int ret;
    int ue,ds;
    ue = end==9?end:end+1;
    ds = start==0?start:start-1;
    // printf("%s\n", );
    if(start==10)
        return ret = 0;
    if(cache[start][end] == 0)
        return ret = 0;
    if(start==9)
    {
        if(end==9)
        {
            ret = solve(ds,end-1,size+1);
            ret %= 1000000000;
            return ret;
        }
        start--;
    }
    if(end==0)
    {
        if(start==0)
        {
            ret = solve(start+1,ue,size+1);
            ret %= 1000000000;
            return ret;
        }
        end++;
    }
    ret = /* cache[start][end] +  */solve(start+1,ue,size+1) + solve(ds,end-1,size+1);
    ret %= 1000000000;
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N;
    // vector<int> v;
    // for (int i = 1; i <= 9; ++i)
    //     v.push_back(i);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cache[i][j] = (j-i+1)*2;
            if(i==0 || i == 9)
                cache[i][j]--;
            if(j==0 || j == 9)
                cache[i][j]--;
            if(i==j)
                cache[i][j] = 2;
        }
    }
    cache[0][0] = 1;
    cache[9][9] = 1;
    // printf("%d\n", cache[1][8]);
    // printf("%d\n", cache[1][9]);
    memset(result, -1, sizeof(result));
    int start = 1, end = 9;
    if(N==1)
        printf("9\n");
    else
        printf("%d\n",solve(start,end,1));
    // for (int i = 1; i < N; ++i) {
    //     cache[start][end];
    // }
    // printf("%lld\n", stair_num(1,9,1));
}
