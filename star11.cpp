#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int stars[3072][6144];
void set_star(int x, int y, int H);
int main(int argc, char *argv[])
{
    int H;
    cin>>H;
    // int W = H * 5 / 3;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < 2*H; ++j) {
            stars[i][j] = ' ';
        }
    }
    set_star(0,0,H);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < 2*H; ++j) {
            printf("%c",stars[i][j]);
        }
        if(i!=H-1)
            printf("\n");
    }
    return 0;
}

void set_star(int x, int y, int H)
{
    if(H==3)
    {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(i==0)
                {
                    if(j==2)
                        stars[x+i][y+j] = '*';
                }
                else if(i==1)
                {
                    if(j==1 || j==3)
                        stars[x+i][y+j] = '*';
                }
                else
                {
                    stars[x+i][y+j] = '*';
                }
            }
        }
        return;
    }
    H/=2;
    set_star(x+H,y,H);
    set_star(x,y+H,H);
    set_star(x+H,y+H*2,H);
}
