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
#include <queue>

using namespace std;
int N, M;
map<char, vector<char> > adj;


int main(int argc, char *argv[])
{
    cin>>N;
    set<char> start_node;

    int capacity[256][256];
    int f[256][256];
    memset(capacity,0,sizeof(capacity));
    memset(f,0,sizeof(f));
    for (int i = 0; i < N; ++i) {
        char from,to;
        int v;
        cin>>from>>to>>v;

        adj[from].push_back(to);
        adj[to].push_back(from);
        capacity[from][to] += v;
        capacity[to][from] += v;
    }
    int totalflow = 0;
    char source = 'A';
    char sink = 'Z';
    while(1)
    {
        char parent[256];
        // pipe *p_edge[256][256];
        memset(parent, -1, sizeof(parent));

        queue<char> q;
        q.push(source);

        while(!q.empty())
        {
            char cur = q.front();
            q.pop();

            for (auto next : adj[cur])//for all adjacent edges
            {
                // char next = e
                if(parent[next] != -1)
                    continue;

                if(capacity[cur][next] - f[cur][next] > 0)
                {
                    q.push(next);

                    parent[next] = cur;

                    if(next == sink)
                        break;
                }
            }
        }
        if(parent[sink] == -1)
            break;

        int flow = 999999999;

        for (char c = sink; c != source; c = parent[c]) {
            flow = min(flow, capacity[parent[c]][c] - f[parent[c]][c]);
        }

        for (char c = sink; c != source; c = parent[c]) {
            f[parent[c]][c] += flow;
            f[c][parent[c]] -= flow;
        }

        totalflow += flow;
    }

    printf("%d\n", totalflow);
    return 0;
}
