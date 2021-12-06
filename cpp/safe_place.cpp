#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N;
int L,U;
int place[101][101];
bool visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int main(int argc, char *argv[])
{
    cin>>N;
    L = 1000; U = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>place[i][j];
            // if(L > place[i][j])
            //     L = place[i][j];
            // if(U < place[i][j])
            //     U = place[i][j];
        }
    }
    int ans = -1;

    for (int d = 0; d <= 100; ++d) {
        queue<pair<int,int> > grp;
        memset(visited,0,sizeof(visited));
        int cnt = 0;
        // printf("d = %d ---------------\n", d);
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if(!visited[i][j] && place[i][j] > d)
                {
                    grp.push(make_pair(i,j));
                    visited[i][j] = true;
                    cnt++;
                    // printf("%d %d => %d\n", i,j,cnt);
                }
                while(!grp.empty())
                {
                    pair<int,int> yx;
                    yx = grp.front();
                    grp.pop();
                    for (int i = 0; i < 4; ++i) {
                        if(!visited[yx.first+dy[i]][yx.second+dx[i]] && yx.first+dy[i] >= 0 && yx.first+dy[i] < N && yx.second+dx[i]>=0 && yx.second+dx[i]<N)
                        {
                            if(place[yx.first+dy[i]][yx.second+dx[i]]>d)
                            {
                                visited[yx.first+dy[i]][yx.second+dx[i]] = true;
                                grp.push(make_pair(yx.first+dy[i],yx.second+dx[i]));
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans,cnt);
    }
    printf("%d\n", ans);
    return 0;
}
