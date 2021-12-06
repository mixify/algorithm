#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;
pair<int,int> cache[101][101];

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
pair<int,int> count_paths(vector<vector <int> > &triangle, int y, int x)
{
    pair<int,int> &ret = cache[y][x];
    if(ret.first!=-1)
        return ret;
    // if(x > y) return ret = -1;
    if(y == triangle.size()-1)
    {
        ret.first = triangle[y][x];
        ret.second = 1;
        return ret;
    }

    pair<int,int> p1 = count_paths(triangle, y+1,x);
    pair<int,int> p2 = count_paths(triangle, y+1,x+1);
    pair<int,int> mx = p1.first>p2.first ? p1 : p2;
    ret.first = triangle[y][x] + max(p1.first,p2.first);
    if (p1.first == p2.first)
        ret.second = p1.second + p2.second;
    else
        ret.second = mx.second;
    // printf("%d %d => %d\n",y,x,ret );

    return ret;
}


void solve_problem(int case_num)
{
    cin>>N;
    vector<vector <int> > triangle;
    for (int i = 0; i < N; ++i) {
        triangle.push_back(vector<int>());
        for (int j = 0; j <= i; ++j) {
            int num;
            cin>>num;
            triangle[i].push_back(num);
        }
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", count_paths(triangle,0,0).second);
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j <= i; ++j) {
    //         printf("%d ", cache[i][j]);
    //     }
    //     printf("\n");
    // }
}
