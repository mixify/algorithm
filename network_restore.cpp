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
        int from = min(a,b);
        int to = max(a,b);
        networks[from].push_back({to,dis});
        W[a][b] = W[b][a] = dis;
        // networks[to].push_back({from,dis});
    }

    vector<net> F;

    // int nearest[N+1];
    int length[N+1];

    fill_n(length,N+1,9999999);
    priority_queue<pair<int,int> > pq;
    vector<int> path(N+1,0);
    for(auto v : networks[1])
    {
        pq.push(make_pair(-v.dis,v.to));
        length[v.to] = v.dis;
        path[v.to] = 1;
        // nearest[i] = 1;
        // length[i] = W[1][i];
    }


    path[1] = 0;

    while(!pq.empty())
    {
        // printf("%d %d\n", -pq.top().first,pq.top().second);
        int cost = -pq.top().first;
        int vnear = pq.top().second;
        pq.pop();

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
    // for (int i = 1; i <= N; ++i) {
    //     printf("%d = %d\n", i, length[i]);
    // }
    stack<int> st;
    // int p = 4;
    set<pair<int, int> > lines;
    // printf("%d\n", p);
    for (int i = 1; i <= N; ++i) {

        int p = i;
        while(path[p] != 0)
        {
            lines.insert(make_pair(path[p], p));
            p = path[p];
        }
    }
    cout<<lines.size()<<endl;
    for(auto line : lines)
        cout<<line.first<<" "<<line.second<<endl;

    // K=0;
    // cout<<K<<endl;
    // for (int i = 0; i < K; ++i) {
    //     ;
    // }
    return 0;
}
