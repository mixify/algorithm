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
pair<int,int> cache[10000][10000];

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
pair<int,int> merge(int x,int y, vector<int> &file)
{
    pair<int,int> &ret = cache[x][y];
    //first => file_size second=> total_cost
    if(x == y) return ret = make_pair(file[x],file[y]);
    if(ret.first!=-1) return ret;
    ret.second = INT_MAX;
    for (int k = x; k < y; ++k) {
        int add1 = 0;
        int add2 = 0;
        if(x!=k) add1 = merge(x,k,file).second;
        if(k+1!=y) add2 = merge(k+1,y,file).second;
        // if(x==k || k+1==y) {add1 = 0;}
        if(ret.second>merge(x,k,file).first + merge(k+1,y,file).first + add1 + add2)
        {
            ret.first = merge(x,k,file).first + merge(k+1,y,file).first;
            ret.second = merge(x,k,file).first + merge(k+1,y,file).first + add1 + add2;
        }
        // ret.second = min(ret.second,);
    }
    return ret;
}

void solve_problem(int case_num)
{
    vector<int> file;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; file.push_back(in);
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n", merge(0,N-1,file).second);
}
