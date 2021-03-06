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

int INF = 999999999;

map<int,vector<pair<int,int> > > grp;

int main(int argc, char *argv[])
{

    cin>>N>>M;

    for (int i = 0; i < M; ++i)
    {
        int from, to, val;
        cin>>from>>to>>val;
        grp[from].push_back(make_pair(val,to));
    }

    vector<int> visit = vector<int>(N+1,0);
    vector<long long> dis = vector<long long>(N+1,-1);

    deque<int> q;

    q.push_front(1);
    dis[1] = 0;

    while(!q.empty())
    {
        int n = q.front();
        q.pop_front();
        visit[n]++;

        if(visit[n] > N-1)
        {
            printf("-1\n");
            return 0;
        }
        for(auto itr : grp[n])
        {
            pair<int,int> p = itr;
            int d = p.first;
            int to = p.second;
            if((dis[to]==-1) || (dis[n] + d < dis[to]))
            {
                dis[to] = dis[n] + d;

                if(find(q.begin(), q.end(), to) == q.end())
                    q.push_back(to);
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        printf("%d\n", dis[i]);
    }
    return 0;
}

