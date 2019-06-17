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
#include <stack>
#include <queue>

using namespace std;
int N, M;

map<int, vector<int> > grp;
map<int, vector<int> > rev_grp;

int f[10001];
int visited[10001];

int t = 0;

stack<int> st;

void dfs(int i)
{
    if(visited[i]) return;
    visited[i] = true;
    for (auto itr : grp[i])
        dfs(itr);
    st.push(i);
}

vector<vector <int> > scc;

void rev_dfs(int i, int sc)
{
    if(visited[i]) return;
    scc[sc].push_back(i);
    visited[i] = true;
    for (auto itr : rev_grp[i])
        rev_dfs(itr,sc);
}

int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin>>from>>to;
        grp[from].push_back(to);
        rev_grp[to].push_back(from);
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= N; ++i)
        dfs(i);

    memset(visited, 0, sizeof(visited));

    int i = 0;
    while(!st.empty())
    {
        scc.push_back(vector<int> ());
        int p = st.top();
        st.pop();
        rev_dfs(p,i);
        sort(scc[i].begin(), scc[i].end());
        i++;
    }

    sort(scc.begin(), scc.end());

    for(auto scs : scc)
    {
        scs.push_back(-1);
        if(scs.size()==1) continue;
        for(auto s : scs)
            printf("%d ",s);
        printf("\n");
    }


    return 0;
}
