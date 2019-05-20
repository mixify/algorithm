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

map<int,set<int> > scc_way;
map<int,set<int> > scc_reversed_way;

int color[10001];
int color2[10001];
int D[10001];
int pred[10001];
vector<int> f;
vector<int> d;

int t = 0;

struct scc{
    int parent;
    int height;
    // vector<int> members;
    // set<int> way;
    // set<int> reverse_way;
};

int scc[10001];
int size[10001];

int find_set(int p) {
	int &q = scc[p];
	if (p == q) return p;
	return q = find_set(q);
}

void merge(int p, int q) {
	p = find_set(p);
	q = find_set(q);
	scc[q] = p;
	if (p != q) size[p] += size[q];
}

// vector <scc> scs;
template <typename T>
vector<int> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] > v[i2];});

  return idx;
}

int grp;
int cnt = 0;
void DFS_visit(int u, int direction)
{
    color[u] = GRAY;
    t= t+1;
    grp++;
    d[u] = t;
    vector<int> w;
    if(direction == REVERSE)
    {
        // if(scs[u].parent == NULL)
        //     create_set(scs+u,u);
    }
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
            // create_set(scs+v,v);
            merge(u,v);
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

int dp[10001];
bool visit[10001];
int solve(size_t node) {
	int sccId = scc[node];
	int &p = dp[sccId];
	if (visit[sccId]) return p;
	else if (sccId == scc[T]) {
		visit[sccId] = true;
		return p = size[sccId];
	}
	visit[sccId] = true;

	for (size_t i = 0; i < N; i++) {
		if (scc[i] == sccId) {
			for (auto next : way[i]) {
				if (scc[next] != sccId) p = max(p, solve(next));
			}
		}
	}

	return p += size[sccId];
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
	for (int i = 1; i <= N; i++)
        scc[i] = i;
    fill_n(size,N+1,1);
    for(auto i : sort_indexes(f))
    {
        // printf("%d\n", i);
        // grp = 0;
        if(i==0) continue;
        if(color[i]==WHITE)
            DFS_visit(i,REVERSE);// making one scc
    }
    // printf("%d\n", scc[2]);

    for (int i = 1; i <= N; ++i) {
        for(auto w: way[i])
        {
            scc_way[scc[i]].insert(scc[w]);
            scc_reversed_way[scc[w]].insert(scc[i]);
        }
    }

    solve(S);
    // int d[10001];
    // d[scc[S]] = size[scc[S]];
    // for (int i = scc[S]; i >= 0; --i) {
    //     for(auto next : scc_way[scc[i]])
    //         D[next] = max(D[next],size[scc[next]] + D[i]);
    // }
    printf("%u", visit[scc[T]] ? solve(S) : 0);
    return 0;
}
