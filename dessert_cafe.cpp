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
int m[21][21];

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
int out_of_boundary(int y,int x)
{
    if(y>=N || x>=N || x<0 || y<0)
        return true;
    return false;
}
int calc_and_valid_check(int y, int x, int w, int h)
{
    int total_cnt = 0;
    map<int,int> mm;

    int i = y;
    int j = x;

    int cnt = 0;
    while(cnt++ < w)
    {
        mm[m[i][j]]++;
        total_cnt++;
        if(mm[m[i][j]] > 1)
            return -1;
        i++;
        j--;
        if(out_of_boundary(i,j))
            return -1;

    }
    cnt = 0;
    while(cnt++ < h)
    {
        mm[m[i][j]]++;
        total_cnt++;
        if(mm[m[i][j]] > 1)
            return -1;
        i++;
        j++;
        if(out_of_boundary(i,j))
            return -1;
    }
    cnt = 0;
    while(cnt++ < w)
    {
        mm[m[i][j]]++;
        total_cnt++;
        if(mm[m[i][j]] > 1)
            return -1;
        i--;
        j++;
        if(out_of_boundary(i,j))
            return -1;
    }
    cnt = 0;
    while(cnt++ < h)
    {
        mm[m[i][j]]++;
        total_cnt++;
        if(mm[m[i][j]] > 1)
            return -1;
        i--;
        j--;
        if(out_of_boundary(i,j))
            return -1;
        else if(i==y && j==x) break;
    }

    return total_cnt;
}

void solve_problem(int case_num)
{

    int answer = -1;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>m[i][j];
        }
    }

    int w,h;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int y = i;
            int x = j;
            for(int w = 1 ; w <= j ; w++)
                for(int h = 1 ; h < N-i ; h++)
                    answer = max(answer,calc_and_valid_check(y,x,w,h));
        }
    }



    cout<<"#"<<case_num+1<<" "<<answer<<endl;
}
