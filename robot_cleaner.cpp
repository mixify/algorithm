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
int N, M;
int place[51][51];
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int dy_b[4] = {1,0,-1,0};
int dx_b[4] = {0,-1,0,1};
int clean = 0;
void dfs(int r, int c,int orientation,int clean_count)
{
    if(place[r][c]==0)
    {
        clean++;
        place[r][c]=2;
    }

    if(orientation < 0) orientation = 3;

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         if(i==r && j==c)
    //         {
    //             char c;
    //             switch(orientation)
    //             {
    //                 case 0:
    //                     c='^';
    //                     break;
    //                 case 1:
    //                     c='>';
    //                     break;
    //                 case 2:
    //                     c='V';
    //                     break;
    //                 case 3:
    //                     c='<';
    //                     break;
    //             }
    //             printf("%c ",c );
    //         }
    //         else
    //         printf("%d ", place[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("------------------\n");
    //
    if(clean_count==4)
    {
        if(place[r+dy_b[orientation]][c+dx_b[orientation]] == 1)
            return;
        clean_count=0;
        dfs(r+dy_b[orientation],c+dx_b[orientation],orientation,clean_count);
    }
    else if(place[r+dy[orientation]][c+dx[orientation]] == 0)
    {
        clean_count=0;
        dfs(r+dy[orientation],c+dx[orientation],orientation-1,clean_count);
    }
    else if(place[r+dy[orientation]][c+dx[orientation]] != 0)
    {
        dfs(r,c,orientation-1, clean_count+1);
    }

}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    int r,c,orientation;
    cin>>r>>c>>orientation;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &place[i][j]);
        }
    }
    dfs(r,c,orientation,0);
    printf("%d\n", clean);
    return 0;
}

