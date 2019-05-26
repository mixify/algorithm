#include <stdio.h>
#include <cstring>
#include <queue>
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
std::vector<size_t> ordered(std::vector<T> const& values) {
    std::vector<size_t> indices(values.size());
    std::iota(begin(indices), end(indices), static_cast<size_t>(0));

    std::sort(
        begin(indices), end(indices),
        [&](size_t a, size_t b) { return values[a] > values[b]; }
    );
    return indices;
}

int grp;
int cnt = 0;
void DFS_visit(int u, int direction)
{
    color[u] = GRAY;
    t= t+1;
    grp++;
    if(direction == STRAIGHT)
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
    if(direction == STRAIGHT)
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


void solve2(int node) {
	int sccId = scc[node];
	if (!color[sccId]) return;
	color[sccId] = WHITE;

	for (int i = 1; i <= N; i++) {
		if (scc[i] == sccId) {
			for (auto next : reversed_way[i]) if (scc[next] != sccId) solve2(next);
		}
	}
}

int solve(size_t node) {
	int sccId = scc[node];
	int &p = dp[sccId];
	if (color[sccId]) return p;
	else if (sccId == scc[T]) {
		color[sccId] = BLACK;
		return p = size[sccId];
	}
	color[sccId] = BLACK;

	for (int i = 1; i <= N; i++) {
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
    // t = 0;
	for (int i = 1; i <= N; i++)
        scc[i] = i;
    fill_n(size,N+1,1);

    // vector<int> test;
    // test.push_back(5);
    // test.push_back(2);
    // test.push_back(3);
    // test.push_back(7);
    // for(auto i : ordered(test))
    // {
    //     printf("%d\n", test[i]);
    // }
    // for(auto v : f)
    //     printf("%d\n", v);
    for(auto i : ordered(f))
    {
        // grp = 0;
        if(i==0) continue;
        // printf("%d = %d\n", i, f[i]);
        if(color[i]==WHITE)
            DFS_visit(i,REVERSE);// making scc
    }
    // printf("-----------\n");
    // for(auto v : f)
    //     printf("%d\n", v);
    // printf("%d\n", scc[2]);

    for (int i = 1; i <= N; ++i) {
        for(auto w: way[i])
        {
            if(scc[i]!=scc[w])
            {
                scc_way[scc[i]].insert(scc[w]);
                scc_reversed_way[scc[w]].insert(scc[i]);
            }
        }
    }
    // printf("%d\n", scc[9]);


    // printf("%d\n", scc[5]);
    // printf("%d\n", size[scc[5]]);

    queue<int> Q;
    Q.push(scc[S]);

    dp[scc[S]] = size[scc[S]];

    // for (int i = 1; i <= N; ++i) {
    //     printf("%d => %d\n",i, scc[i]);
    // }
    // for(auto next : scc_way[scc[2]])
    //     cout<<next<<endl;
    // while(!Q.empty())
    // {
    //     int now = Q.front();
    //     Q.pop();
    //     for(auto next : scc_way[now])
    //     {
    //         // cout<<now<<"->"<<next<<endl;
    //         if(dp[next] < dp[now] + size[next])
    //         {
    //             dp[next] = dp[now] + size[next];
    //             Q.push(next);
    //         }
    //     }
    // }
    // printf("%d\n", dp[scc[T]]);
    //
    // for(int i = scc[S]; i < scc[T]; ++i){
    //     for(auto next : scc_way[scc[i]])
    //         if(dp[next] < dp[i] + size[scc[next]])
    //         {
    //             dp[next] = dp[i] + size[scc[next]];
    //         }
    // }
    // printf("%d\n", dp[scc[T]]);
    // memset(visit,0,sizeof(visit));
    solve2(T);
    solve(S);
    // int d[10001];
    // d[scc[S]] = size[scc[S]];
    // for (int i = scc[S]; i >= 0; --i) {
    //     for(auto next : scc_way[scc[S]])
    //         D[next] = max(D[next],size[scc[next]] + D[i]);
    // }
    // printf("%d\n", d[scc[T]]);
    printf("%u", visit[scc[T]] ? solve(S) : 0);
    return 0;
}
