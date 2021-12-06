#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;
int center[8][8];
pair <int,int> idx[64];
pair <int,int> virus_idx[64];
int cnt = 0;
int virus_cnt = 0;
int dy[4] = {-1,0,0,1};
int dx[4] = {0,1,-1,0};

int check(int safety)
{
    int center_for_check[8][8];
    int ret = 0;
    queue<pair<int,int> > q;
    memcpy(center_for_check,center,sizeof(center));
    for (int i = 0; i < virus_cnt; ++i) {
        q.push(make_pair(virus_idx[i].first, virus_idx[i].second));
        while(!q.empty())
        {
            pair<int,int> s = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                if(s.first+dy[j]<N && s.first+dy[j]>=0 && s.second+dx[j]<M && s.second+dx[j]>=0)
                    if(center_for_check[s.first+dy[j]][s.second+dx[j]] == 0)
                    {
                        safety--;
                        center_for_check[s.first+dy[j]][s.second+dx[j]] = 2;
                        q.push(make_pair(s.first+dy[j],s.second+dx[j]));
                    }
            }
        }
    }
    return safety;
}
int bfs(int val)
{
    int ret = 0;
    for (int i = 0; i < cnt-2; ++i) {
        for (int j = i+1; j < cnt-1; ++j) {
            for (int k = j+1; k < cnt; ++k) {
                // printf("%d %d %d\n", i,j,k);
                center[idx[i].first][idx[i].second] = 1;
                center[idx[j].first][idx[j].second] = 1;
                center[idx[k].first][idx[k].second] = 1;
                ret = max(ret,check(cnt-3));
                center[idx[i].first][idx[i].second] = 0;
                center[idx[j].first][idx[j].second] = 0;
                center[idx[k].first][idx[k].second] = 0;
            }
        }
    }
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &center[i][j]);
            if(center[i][j] == 0)
                idx[cnt++] = make_pair(i,j);
            else if(center[i][j] == 2)
                virus_idx[virus_cnt++] = make_pair(i,j);
        }
    }
    printf("%d\n", bfs(0));
    return 0;
}

