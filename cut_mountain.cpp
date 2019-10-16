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
int N, K;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int mon[9][9];

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

int DFS(int y,int x, int tmp[9][9],int dis)
{
    dis++;
    int ret = dis;

    for (int i = 0; i < 4; ++i) {
        int dest_y = y+dy[i];
        int dest_x = x+dx[i];
        if(dest_y < 0 || dest_x < 0 || dest_y>=N || dest_x>=N) continue;
        if(tmp[y][x] > tmp[dest_y][dest_x])
            ret = max(ret,DFS(dest_y,dest_x,tmp,dis));
    }
    return ret;
}
void solve_problem(int case_num)
{
    cin>>N;
    cin>>K;
    int max_h = 0;
    int answer = 0;
    vector <pair<int,int> > bong;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>mon[i][j];
            if(max_h < mon[i][j])
            {
                max_h = mon[i][j];
                bong.clear();
                bong.push_back(make_pair(i,j));
            }
            else if(max_h == mon[i][j])
                bong.push_back(make_pair(i,j));
        }
    }
    int tmp[9][9];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k <= K; ++k) {
                memcpy(tmp,mon,sizeof(mon));
                tmp[i][j] -= k;
                for(auto b : bong)
                {
                    answer = max(answer,DFS(b.first,b.second,tmp,0));
                }
            }
        }
    }
    printf("#%d %d\n", case_num+1,answer);
}
