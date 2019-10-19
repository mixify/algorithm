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
int game[101][101];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int D[101][101][4];
// int trace[101][101][4];

int dirc[4][7];

void solve_problem(int case_num);
map<int,vector<pair<int, int> > > wormhall;

void set_dirc()
{
    dirc[0][1] = 1;
    dirc[0][2] = 2;
    dirc[0][3] = 3;
    dirc[0][4] = 1;
    dirc[0][5] = 1;

    dirc[1][1] = 2;
    dirc[1][2] = 0;
    dirc[1][3] = 0;
    dirc[1][4] = 3;
    dirc[1][5] = 0;

    dirc[2][1] = 3;
    dirc[2][2] = 3;
    dirc[2][3] = 1;
    dirc[2][4] = 0;
    dirc[2][5] = 3;

    dirc[3][1] = 0;
    dirc[3][2] = 1;
    dirc[3][3] = 2;
    dirc[3][4] = 2;
    dirc[3][5] = 2;
    // for (int i = 0; i < 4; ++i) {
    //     for (int j = 0; j < 6; ++j) {
    //         if(i==0)
    //         {
    //             if(j==1)
    //                 dirc[i][j]
    //         }
    //     }
    // }
}
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    set_dirc();
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}


int get_score(int sy, int sx, int y, int x, int dir)
{
    int &ret = D[y][x][dir];
    int score = 0;


    int next_y = y + dy[dir];
    int next_x = x + dx[dir];

    if(next_y >= N || next_y < 0 || next_x >= N || next_x < 0)
    {
        y = next_y;
        x = next_x;
        score = 1;
        // if(y==sy && x==sx) return ret=score;
        dir = dirc[dir][5];
        // if(0 < game[y][x] && game[y][x] < 5)
        // {
        //     dir = dirc[dir][game[y][x]];
        //     score++;
        // }
    }

    else if(next_y == sy && next_x == sx) {
        return ret = score;
    }

    else if(game[next_y][next_x] == -1) {
        return ret = score;
    }

    else if(game[next_y][next_x] == 0)
    {
        y = next_y;
        x = next_x;
    }
    else if(game[next_y][next_x] > 5)
    {
        pair<int,int> w1 = wormhall[game[next_y][next_x]][0];
        pair<int,int> w2 = wormhall[game[next_y][next_x]][1];
        if(w1.first != next_y || w1.second !=next_x)
        {
            y = w1.first;
            x = w1.second;
        }
        else
        {
            y = w2.first;
            x = w2.second;
        }
    }
    else
    {
        score++;
        y = next_y;
        x = next_x;
        dir = dirc[dir][game[next_y][next_x]];
    }

    return ret = score + get_score(sy, sx, y, x, dir);
}

void solve_problem(int case_num)
{
    int max_score = 0;
    cin>>N;
    memset(D,-1,sizeof(D));
    wormhall.clear();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>game[i][j];
            if(game[i][j] > 5)
                wormhall[game[i][j]].push_back(make_pair(i,j));
        }
    }


    // printf("%d\n", get_score(13,13,13,13,2));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if(game[i][j] == 0)
                for (int k = 0; k < 4; ++k) {
                    // int trace[101][101][4];
                    // memset(trace,0,sizeof(trace));
                    // printf("%d %d %d\n", i,j,k);
                    max_score = max(max_score,get_score(i,j,i,j,k));
                    // if(pre!=max_score) printf("%d %d %d\n", i,j,k);
                }
    printf("#%d %d\n", case_num+1, max_score);
}
