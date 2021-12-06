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
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
vector<vector <int> > mountain;
int cache[500][500];

bool is_valid(int x, int y, int H)
{
    if(x<0 || y < 0 || y>= M || x>= N || H <= mountain[y][x])
        return false;
    return true;
}
int solve(int x, int y)
{
    if(x==N-1 && y==M-1) return 1;
    int &ret = cache[x][y];
    if(ret!=-1) return ret;
    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int next_x = x+dx[i], next_y = y+dy[i];
        if(is_valid(next_x,next_y,mountain[y][x]))
            ret+=solve(next_x,next_y);
    }
    return ret;
}
int main(int argc, char *argv[])
{
    int cases;
    cin>>M>>N;
    for (int i = 0; i < M; ++i)
    {
        mountain.push_back(vector<int>());
        for (int j = 0; j < N; ++j) {
            int in; cin>>in;
            mountain[i].push_back(in);
        }
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n", solve(0,0));
    return 0;
}
