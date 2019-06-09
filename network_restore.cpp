#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <queue>

using namespace std;
struct net{
    int to;
    int dis;
};
int N, M;
int K;
int W[1001][1001];

map<int,vector<net>> networks;
int main(int argc, char *argv[])
{
    cin>>N>>M;
    memset(W,0,sizeof(W));
    for (int i = 0; i < M; ++i) {
        int a, b, dis;
        cin>>a>>b>>dis;
        networks[a].push_back({b,dis});
        networks[b].push_back({a,dis});
    }

    vector<int> length(N+1,99999999);

    priority_queue<pair<int,int> > pq;
    vector<int> path(N+1,0);
    pq.push(make_pair(0,1));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int vnear = pq.top().second;
        pq.pop();

        if(length[vnear] < cost)
            continue;

        for (auto v : networks[vnear])
        {
            if(cost + v.dis < length[v.to])
            {
                length[v.to] = cost + v.dis;
                pq.push(make_pair(-(cost + v.dis),v.to));
                path[v.to] = vnear;
            }
        }
    }
    printf("%d\n", N-1);
    for (int i = 2; i <= N; ++i) {
        if(path[i]!=0)
            printf("%d %d\n", path[i],i);
    }
}
