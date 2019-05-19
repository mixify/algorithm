#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <numeric>
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
vector<int> f;
vector<int> d;

int t = 0;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

  return idx;
}

int grp;
void DFS_visit(int u, int direction)
{
    color[u] = GRAY;
    t= t+1;
    grp++;
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
    f = vector<int>(N+1);
    f[0] = -1;
    d = vector<int>(N+1);
    d[0] = -1;
    for (int i = 0; i < M; ++i) {
        int a,b; cin>>a>>b;
        way[a].push_back(b);
        reversed_way[b].push_back(a);
        // reversed_way[i].first = way[i].second;
        // reversed_way[i].second = way[i].first;
    }
    DFS(S,STRAIGHT);
    // for (int i = 1; i <= N; ++i) {
    //     printf("%d = %d\n", i,f[i]);
    // }
    memset(color,0,sizeof(color));
    t = 0;
    for(auto i : sort_indexes(f))
    {
        // printf("%d\n", i);
        grp = 0;
        DFS_visit(i,REVERSE);
        if(color[T]!=WHITE)
        {
            printf("%d\n", grp);
            break;
        }
    }

    // printf("%d\n", t+1);
    return 0;
}
