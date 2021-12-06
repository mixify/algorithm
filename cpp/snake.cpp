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
int N, K, L;
int board[101][101];
int ori[101][101];
char rot[10001];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int main(int argc, char *argv[])
{
    cin>>N>>K;
    memset(board,0,sizeof(board));
    for (int i = 0; i < K; ++i) {
        int a,b; cin>>a>>b;
        board[a][b]=2;
    }

    cin>>L;
    memset(rot,0,sizeof(rot));

    for (int i = 0; i < L; ++i) {
        int a; char b; cin>>a>>b;
        rot[a] = b;
    }

    int cur_ori = 0;
    int time = 0;
    int y,x;
    y = 1; x = 1;
    ori[y][x] = cur_ori;
    board[y][x] = 1;
    pair<int,int> tail = make_pair(y,x);
    pair<int,int> head = make_pair(y,x);
    while(1)
    {
        if(rot[time] == 'D')
        {
            cur_ori = (cur_ori+1)%4;
            ori[y][x] = cur_ori;
        }
        else if(rot[time] == 'L')
        {
            cur_ori = cur_ori-1;
            if(cur_ori<0) cur_ori = 3;
            ori[y][x] = cur_ori;
        }
        else
            ori[y][x] = cur_ori;
        y = y+dy[cur_ori];
        x = x+dx[cur_ori];

        head = make_pair(y,x);

        if(y<1 || x<1 || y>N || x>N) break;

        if(board[y][x] == 1) break;
        else if(board[y][x]==2)
        {
            //do nothing?
        }
        else
        {
            board[tail.first][tail.second] = 0;
            tail = make_pair(tail.first + dy[ori[tail.first][tail.second]]
                    ,tail.second + dx[ori[tail.first][tail.second]]);
        }
        board[y][x] = 1;
        // for (int i = 1; i <= N; ++i) {
        //     for (int j = 1; j <= N; ++j) {
        //         printf("%d ", board[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("---------------\n");
        time++;
    }
    printf("%d\n", time+1);

    return 0;
}
