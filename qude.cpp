#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector<vector <int> > quadtree;
void compress_image(int x, int y, int size);
int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        vector <int> v;
        quadtree.push_back(v);
        for (int j = 0; j < N; ++j) {
            int num;
            scanf("%1d", &num);
            quadtree[i].push_back(num);
        }
    }
    compress_image(0,0,N);
    printf("\n");
}

void compress_image(int x, int y, int size)
{
    bool same = true;
    for (int i = x; i < x+size; ++i) {
        for (int j = y; j < y+size; ++j) {
            if(quadtree[x][y]!=quadtree[i][j])//divide by 4
            {
                same = false;
                i =9999999;
                break;
            }
        }
    }
    if(same)
    {
        printf("%d", quadtree[x][y]);
        return;
    }
    else
    {
        printf("(");
        size/=2;
        compress_image(x,y,size);
        compress_image(x,y+size,size);
        compress_image(x+size,y,size);
        compress_image(x+size,y+size,size);
        printf(")");
    }
}
