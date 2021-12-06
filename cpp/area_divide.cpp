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
int M, N, K;
int rect[101][101];
bool visited[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    cin>>M>>N>>K;
    memset(rect,0,sizeof(rect));
    memset(visited,0,sizeof(visited));
    for (int i = 0; i < K; ++i)
    {
        int start_x,start_y;
        int end_x,end_y;

        cin>>start_x>>start_y;
        cin>>end_x>>end_y;
        // printf("------------\n");
        for (int i = start_y; i < end_y; ++i) {
            for (int j = start_x; j < end_x; ++j) {
                rect[i][j] = 1;
                // printf("%d %d\n", i,j);
            }
        }
    }
    // for (int i = 0; i < M; ++i)
    // {
    //     for (int j = 0; j < N; ++j)
    //     {
    //         printf("%d ", rect[i][j]);
    //     }
    //     printf("\n");
    // }

    queue<pair<int,int> > q;
    vector<int> areas;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int cnt = 0;
            if(!visited[i][j] && rect[i][j] == 0)
            {
                visited[i][j] = true;
                q.push(make_pair(i,j));
                cnt++;
            }
            while(!q.empty())
            {
                pair<int,int> yx = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = yx.first+dy[k];
                    int x = yx.second+dx[k];
                    if(x>=0 && y<M && y>=0 && x<N)
                    {
                        if(!visited[y][x] && rect[y][x]==0)
                        {
                            // printf("%d %d\n", y,x);
                            visited[y][x] = true;
                            q.push(make_pair(y,x));
                            cnt++;
                        }
                    }
                }
            }
            if(cnt!=0)
                areas.push_back(cnt);
        }
    }
    sort(areas.begin(), areas.end());
    printf("%d\n", areas.size());
    for (int i = 0; i < areas.size(); ++i) {
        printf("%d ", areas[i]);
    }
    printf("\n");
    return 0;
}

void solve_problem(int case_num)
{

}
