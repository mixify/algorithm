#include <stdio.h>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int cache[101][101];
void solve_problem(int case_num);
int max_triangle(vector<vector <int> > v, int x, int y);
    int size;
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void solve_problem(int case_num)
{
    cin>>size;
    vector<vector <int> > triangle;
    for (int i = 0; i < size; ++i) {
        vector<int> v;
        triangle.push_back(v);
        for (int j = 0; j <= i; ++j) {
            int num;
            cin>>num;
            triangle[i].push_back(num);
        }
    }
    memset(cache,-1,sizeof(cache));
    cout<<max_triangle(triangle,0,0)<<endl;
}
int max_triangle(vector<vector <int> > triangle, int x, int y)
{
    int &ret = cache[x][y];
    if(ret!=-1) return ret;

    if(x >= size)
        return 0;
    if(y == size-1)
        return triangle[x][y];

    return ret = triangle[x][y] + max(max_triangle(triangle,x+1,y),max_triangle(triangle,x+1,y+1));
}
