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

void Z(int x,int y, int N)
{
    if(N==1)
    {
        if(x==row && y==col)
        {
            printf("%d\n", order);
            exit(0);
        }
        order++;
        return;
    }
    N/=2;
    Z(x,y,N);
    Z(x,y+N,N);
    Z(x+N,y,N);
    Z(x+N,y+N,N);
}
