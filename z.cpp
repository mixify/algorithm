#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

void Z(int x,int y, int N);
int row,col;
int order = 0;
int main(int argc, char *argv[])
{
    int N;
    int size = 1;
    cin>>N;
    cin>>row>>col;
    for (int i = 0; i < N; ++i) {
        size*=2;
    }
    Z(0,0,size);
    return 0;
}

void Z(int x,int y, int N)//2, 0, 2  3 1
{
    if(x==row && y==col)
    {
        printf("%d\n", order);
        exit(0);
    }
    int half = N/2;
    if(row<x+half && col<y+half)
    {
        Z(x,y,half);
    }
    else if(row<x+half && col>=y+half)
    {
        order+=half*half;
        Z(x,y+half,half);
    }
    else if(row>=x+half && col<y+half)
    {
        order+=half*half*2;
        Z(x+half,y,half);
    }
    else
    {
        order+=half*half*3;
        Z(x+half,y+half,half);
    }
}
//N=16 =>64 = 8*8 씩,N=8 => 16 => 4*4씩 , N=4 => 4=>2*2씩, N=2 => 1=>1*1씩
