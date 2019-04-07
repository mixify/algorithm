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
string str;
int land_A[1501][1501];//for lower
int land_B[1501][1501];//for higher
int summation_A[1501][1501];
int summation_B[1501][1501];
int cache[1501][1501][3];

int R, C;

int bulldozer(int y, int x,int ori,int apple, int banana)
{
    int &ret = cache[y][x][ori];
    // int &ret = cache[x][y];
    if(ret!=-1) return ret;
    //
    if(y==R || x==C)
        return -10000;
    // if(x >= size)
    //     return 0;
    // if(ori == 0)
    //     printf("jump type = x\n");
    // else if(ori == 1)
    //     printf("jump type = y\n");
    // else if(ori == 2)
    //     printf("jump type = xy\n");
    // printf("at %d %d\n", y,x);
    // printf("apple + banana = %d\n", apple + banana);

    if(y==R-1 && x==C-1)
        return ret = apple + banana;
    //     return triangle[x][y];

    return ret = apple+banana + max(
            max(bulldozer(y+1,x+1,2,summation_A[y+1][x+1],summation_B[y+1][x+1]),
                bulldozer(y+1,x,1,-land_A[y+1][x],summation_B[y+1][x]))
            , bulldozer(y,x+1,0,summation_A[y][x+1],-land_B[y][x+1]));
}

int main(int argc, char *argv[])
{
    cin>>R>>C;
    memset(cache,-1,sizeof(cache));
    memset(land_A,0,sizeof(land_A));
    memset(land_B,0,sizeof(land_B));
    memset(summation_A,0,sizeof(summation_A));
    memset(summation_B,0,sizeof(summation_B));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin>>str;
            int amount = stoi(str.substr(1,str.length()-1));
            if(str[0]=='A')
                land_A[i][j] = amount;
            else
                land_B[i][j] = amount;
        }
    }
    for (int j = 0; j < C; ++j)
    {
        for (int i = 0; i < R; ++i)
        {
            summation_A[0][j] += land_A[i][j];
        }
    }

    for (int j = 0; j < C; ++j)
    {
        for (int i = 0; i < R; ++i)
        {
            if(i==0) summation_A[i][j] = summation_A[0][j] - land_A[i][j];
            else
                summation_A[i][j] = summation_A[i-1][j] - land_A[i][j];
        }
    }

    // printf("%d\n", summation_A[0][1]);
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            summation_B[i][0] += land_B[i][j];
        }
    }
    // printf("%d\n", summation_B[0][0]);
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if(j==0) {
                // printf("%d - %d\n", summation_B[i][0] - land_B[i][j]);
                summation_B[i][j] = summation_B[i][0] - land_B[i][j];
            }
            else
                summation_B[i][j] = summation_B[i][j-1] - land_B[i][j];
        }
    }
    printf("%d\n", bulldozer(0,0,0,summation_A[0][0],summation_B[0][0]));
    return 0;
}
