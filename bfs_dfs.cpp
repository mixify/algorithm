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
int N, M;
int V;

vector<bool> visited;

map<int,vector<int> > graph;

queue<int> q;

void dfs(int n)
{
    if(visited[n]) return;
    printf("%d ", n);
    visited[n] = true;
    for(auto itr : graph[n])
        dfs(itr);

}

void bfs(int n)
{
    q.push(n);
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        if(visited[val]) continue;
        printf("%d ", val);
        visited[val] = true;
        for(auto itr : graph[val])
            q.push(itr);
    }
}
int main(int argc, char *argv[])
{
    cin>>N>>M>>V;

    for (int i = 0; i < M; ++i) {
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    visited = vector<bool>(N+1,false);
    dfs(V);
    printf("\n");
    visited = vector<bool>(N+1,false);
    bfs(V);
    printf("\n");
    return 0;
}
