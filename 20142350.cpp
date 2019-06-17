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

using namespace std;
int N, M, K;
vector<vector <int> > worker;


bool DFS(int a, bool *visited, int *match)
{
    if(visited[a])
        return false;
    visited[a] = true;
    for(auto b : worker[a])
    {
        if(match[b] == -1)
        {
            // printf("0 : matching %d with %d\n",a,b );
            match[b] = a;
            return true;
        }
    }
    for(auto b : worker[a])
    {
        if(DFS(match[b],visited,match))
        {
            // printf("1 : matching %d with %d\n",a,b);
            match[b] = a;
            return true;
        }
    }
    return false;
}
int max_matching()
{
    bool visited[2*N];
    int match[M];
    int ans = 0;
    fill(match,match+M,-1);

    for (int i = 0; i < N; ++i) {
        fill(visited,visited+2*N,0);
        if(DFS(i,visited,match)) ++ans;
    }
    int cnt = 0;
    for (int i = N; i < 2*N; ++i) {
        fill(visited,visited+2*N,0);
        if(DFS(i,visited,match)) {
            ++cnt;
            ++ans;
            if(cnt>=K) break;
        }
    }
    // for (int i = 0; i < M; ++i) {
    //     printf("worker[%d] -> work[%d]\n",i, match[i]);
    // }
    return ans;
}
int main(int argc, char *argv[])
{
    cin>>N>>M>>K;

    for (int i = 0; i < N; ++i) {
        int c;
        cin>>c;
        worker.push_back(vector<int>());
        for (int j = 0; j < c; ++j)
        {
            int w;
            cin>>w;
            worker[i].push_back(w-1);
        }
    }
    for (int i = 0; i < N; ++i) {
        worker.push_back(vector<int>());
        for (auto w : worker[i])
        {
            worker[i+N].push_back(w);
        }
    }
    printf("%d\n", max_matching());
    return 0;
}

