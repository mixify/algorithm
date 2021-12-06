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
int apart[26][26];
bool visited_flower[26][26];
bool visited_road[26][26];
vector<int> danjis;
int N;
int dy[8] = {-1,1,0,0,1,1,-1,-1};
int dx[8] = {0,0,1,-1,1,-1,1,-1};


int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%1d", &apart[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            queue<pair<int, int> > group;
            int cnt = 0;
            memset(visited_road,0,sizeof(visited_road));
            if(!visited_flower[i][j] && apart[i][j]==1)
            {
                // printf("%d %d\n", i,j);
                group.push(make_pair(i,j));
                visited_flower[i][j] = true;
                // cnt++;
            }
            while(!group.empty())
            {
                pair<int,int> yx = group.front();
                group.pop();
                for (int i = 0; i < 8; ++i) {
                    int y = yx.first+dy[i];
                    int x = yx.second+dx[i];
                    // printf("%d %d \n", y, x);
                    if(y>=0 && y<N && x>=0 && x<N)
                    {
                        if(!visited_flower[y][x] && !visited_road[y][x])
                        {
                            if(apart[y][x]==1)
                            {
                                group.push(make_pair(y,x));
                                visited_flower[y][x] = true;
                            }
                            else
                            {
                                visited_road[y][x] = true;
                                cnt++;
                            }
                        }
                    }
                }
            }
            if(cnt>0)
                danjis.push_back(cnt);
        }
    }
    sort(danjis.begin(), danjis.end());
    // printf("%d\n", danjis.size());
    for (int i = 0; i < danjis.size(); ++i) {
        printf("%d\n", danjis[i]);
    }
    return 0;
}

