#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
int N, M, W;

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

void solve_problem(int case_num)
{
    cin>>N>>M>>W;
    map<int,vector<pair<int,int > > > road;
    // map<int,vector<pair<int,int > > > wormhole;
    for (int i = 0; i < M; ++i) {
        int s,t,e;
        scanf("%d %d %d", &s, &t, &e);
        road[s].push_back(make_pair(t,e));
        road[t].push_back(make_pair(s,e));
    }
    for (int i = 0; i < W; ++i) {
        int s,t,e;
        scanf("%d %d %d", &s, &t, &e);
        road[s].push_back(make_pair(t,-e));
    }
    vector<int> distance(N+1,99999999);
    vector<int> predecessor(N+1,99999999);
    distance[1] = 0;

    deque<int> q;
    vector<int> visited(N+1,0);
    q.push_back(1);
    bool cycle = false;
    while(!q.empty())
    {
        int u = q.front();
        visited[u]++;
        if(visited[u]>N-1)
        {
            cycle = true;
            break;
        }
        q.pop_front();
        for(auto edge : road[u])
        {
            int w = edge.second;
            int v = edge.first;
            if(distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                // printf("%d\n", distance[v]);
                predecessor[v] = u;
                if(find(q.begin(), q.end(), v) == q.end())
                    q.push_back(v);
            }
        }
    }
    printf("%s\n", cycle?"YES":"NO");
}
