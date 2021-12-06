#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <map>

using namespace std;
int N, M;
int water[21][21];
bool visited[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

struct yxd {
    int y;
    int x;
    int d;
};

int compare_yxd(yxd a, yxd b)
{
    if(a.d == b.d)
    {
        if(a.y == b.y)
            return a.x < b.x;
        return a.y < b.y;
    }
    return a.d < b.d;
}
int hunt(int shark_y, int shark_x, int eat_amount, int shark_size)
{
    queue <yxd> q;
    yxd a;
    a.y = shark_y;
    a.x = shark_x;
    a.d = 0;
    q.push(a);
    memset(visited,0,sizeof(visited));
    visited[shark_y][shark_x] = true;
    water[shark_y][shark_x] = 0;
    vector<yxd> fish;

    // printf("%d\n", shark_size);
    while(!q.empty())
    {
        yxd my = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int y = my.y + dy[i];
            int x = my.x + dx[i];
            if(y>=0 && y<N && x>=0 && x<N)
            {
                if(!visited[y][x] && water[y][x] <= shark_size)
                {
                    yxd b;
                    visited[y][x] = true;
                    b.y = y;
                    b.x = x;
                    // printf("%d %d\n", y,x);
                    b.d = my.d+1;
                    if(water[y][x]!=0 && shark_size > water[y][x])
                        fish.push_back(b);
                    q.push(b);
               }
            }
        }
    }

    int val;
    if(fish.size() == 0) return 0;
    else
    {
        eat_amount++;
        sort(fish.begin(),fish.end(),compare_yxd);
        val = water[fish[0].y][fish[0].x];
        water[fish[0].y][fish[0].x] = 0;
        if(eat_amount == shark_size)
        {
            shark_size++;
            // printf("shark is now %d\n", shark_size);
            eat_amount = 0;
        }
    }

    return fish[0].d + hunt(fish[0].y,fish[0].x,eat_amount,shark_size);
}
int main(int argc, char *argv[])
{
    int shark_y, shark_x;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>water[i][j];
            if(water[i][j]==9)
            {
                shark_y = i;
                shark_x = j;
            }
        }
    }
    printf("%d\n", hunt(shark_y, shark_x, 0, 2));

    return 0;
}
