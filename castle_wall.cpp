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
#include <queue>

#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8

struct wall{
    int y;
    int x;
    int direction;
};
using namespace std;
int N, M;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
// int castle[51][51];
int castle_wall[51][51];
bool visited[51][51];

vector<wall> walls;

int cnt_rooms = 0;
int widest = 0;
int widest_after_removing = 0;

int dir(int exp)
{
    if(exp == 0) return WEST;
    else if(exp == 1) return NORTH;
    else if(exp == 2) return EAST;
    else if(exp == 3) return SOUTH;
    return 0;
}
void BFS(int removed_wall)
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> > q;
    if(removed_wall!=-1)
    {
        wall rw = walls[removed_wall];
        castle_wall[rw.y][rw.x] -= rw.direction;
    }
    for (int i = 0; i < M; ++i) {// i is Y
        for (int j = 0; j < N; ++j) {// j is X
            if(!visited[i][j])
            {
                if(removed_wall == -1) cnt_rooms++;
                int area = 1;
                visited[i][j] = true;
                q.push(make_pair(i,j));
                // printf("%d %d\n", i,j);
                while(!q.empty())
                {
                    pair<int,int> yx = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int y = yx.first + dy[k];
                        int x = yx.second + dx[k];
                        if(y>=0 && x>=0 && x<N && y<M)
                        {
                            if(((castle_wall[yx.first][yx.second] & dir(k)) == 0) && !visited[y][x])
                            {
                                // printf("%d %d\n", y,x);
                                area++;
                                visited[y][x] = true;
                                q.push(make_pair(y,x));
                            }
                        }
                    }
                }
                // printf("------------\n");
                if(removed_wall == -1) widest = max(area,widest);
                else if (removed_wall != -1) widest_after_removing = max(area,widest_after_removing);
            }
        }
    }
    if(removed_wall!=-1)
    {
        wall rw = walls[removed_wall];
        castle_wall[rw.y][rw.x] += rw.direction;
    }
}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    memset(castle_wall,0,sizeof(castle_wall));

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin>>castle_wall[i][j];
            for (int dir = EAST; dir <= SOUTH; dir*=2) {
                if(castle_wall[i][j] & dir)
                    walls.push_back(wall{i,j,dir});
            }
        }
    }

    for (int i = 0; i <= walls.size(); ++i)
        BFS(i-1);
    printf("%d\n", cnt_rooms);
    printf("%d\n", widest);
    printf("%d\n", widest_after_removing);
    return 0;
}
