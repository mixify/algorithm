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
int N, M;
int cache[10000][10000];

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
int merge(int idx,int cost, vector<pair<int,int> > file)
{
    int &ret = cache[idx][cost];
    if(file.size()==1) return ret = cost;
    if(ret!=-1) return ret;
    ret = 50000;
    for (int i = 0; i < file.size()-1; ++i) {
        vector<pair<int,int>> merged_file = file;
        merged_file[i].first = merged_file[i].first+merged_file[i+1].first;
        merged_file[i].second = merged_file[i].second+merged_file[i+1].second+N;
        // printf("%d : %d %d\n", N-file.size(),merged_file[i].first,merged_file[i].second);
        merged_file.erase(merged_file.begin()+i+1);
        ret = min(ret,merge(merged_file[i].second,cost+merged_file[i].first,merged_file));
    }
    // if(i==idx)
    //     continue;
    // merged_file[i] = merged_file[idx] +
    // ret = max(ret, merge(,file[idx] + file[i]));
    return ret;
}

void solve_problem(int case_num)
{
    vector<pair<int,int> > file;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        pair<int,int> in; int num; cin>>num; in.first=num; in.second=i; file.push_back(in);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n", merge(0,0,file));
}
