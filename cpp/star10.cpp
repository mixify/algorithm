#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int stars[6561][6561];
void set_star(int x,int y, int num);
int main(int argc, char *argv[])
{
    int N;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            stars[i][j] = ' ';
        }
    }
    set_star(0,0,N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c",stars[i][j]);
        }
        if(i!=N-1)
            printf("\n");
    }
    return 0;
}

void set_star(int x, int y, int num)
{
    if(num==1)
    {
        stars[x][y] = '*';
        return;
    }
    num/=3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i==1 && j==1)
                ;
            else
                set_star(x+i*num,y+j*num,num);
        }
    }
}
