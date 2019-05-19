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

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define STRAIGHT 3
#define REVERSE 4
using namespace std;
int M,N,S,T;
map<int,vector<int> > way;
map<int,vector<int> > reversed_way;

int color[10001];
int pred[10001];
int f[10001];
int d[10001];

int t = 0;

void DFS_visit(int u, int direction)
{
    color[u] = GRAY;
    t= t+1;
    d[u] = t;
    vector<int> w;
    if(direction == STRAIGHT)
        w= way[u];
    else
        w= reversed_way[u];
    for(auto itr = w.begin() ; itr!= w.end() ; itr++)
    {
        int v = *itr;
        if(color[v] == WHITE)
        {
            pred[v] = u;
            DFS_visit(v,direction);
        }
    }
    color[u] = BLACK;
    t= t + 1;
    f[u] = t;
}
void DFS(int V,int direction)
{
    vector<int> w;
    if(direction == STRAIGHT)
        w = way[V];
    else
        w = reversed_way[V];
    for(auto itr = w.begin() ; itr!= w.end() ; itr++)
    {
        int u = *itr;
        color[u] = WHITE;
        pred[u] = 0;
    }

    t = 0;
    for(auto itr = w.begin() ; itr!= w.end() ; itr++)
    {
        int u = *itr;
        if(color[u] == WHITE);
            DFS_visit(u,direction);
    }
}
int main(int argc, char *argv[])
{
    cin>>N>>M>>S>>T;
    for (int i = 0; i < M; ++i) {
        int a,b; cin>>a>>b;
        way[a].push_back(b);
        reversed_way[b].push_back(a);
        // reversed_way[i].first = way[i].second;
        // reversed_way[i].second = way[i].first;
    }
    DFS(S,STRAIGHT);
    DFS(T,REVERSE);

    printf("%d\n", t+1);
    return 0;
}
