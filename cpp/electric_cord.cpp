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
int N;
int mat[12][12];
int best;
int best_min;
int cache[12][4][12];
int dy[5] = {-1,0,0,1,0};
int dx[5] = {0,1,-1,0,0};
vector<pair<int,int> > core;


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

int answer(int idx, int ori, int count_cord, int count_core)
{
    int org[12][12];
    int org_count = count_cord;
    memcpy(org,mat,sizeof(mat));
    if(idx==core.size())
    {
        // if(count_core==5)
        //     printf("%d best = %d\n", count_core, best);
        if(count_core >= best)
        {
            // best_min = 200;
            if(count_core > best)
            {
                best = count_core;
                best_min = 200;
            }
            if(best_min > count_cord)
            {
                // printf("best = %d cord = %d\n", best,count_cord);
                best_min = count_cord;
            }
        }
        return count_cord;
    }

    int a = core[idx].first;
    int b = core[idx].second;

    bool possible = true;
    while((a+dy[ori] >= 0 && a+dy[ori] < N) && (b+dx[ori] >=0 && b+dx[ori] < N))
    {
        if(ori == 4)
        {
            possible = false;
            break;
        }
        if(mat[a+dy[ori]][b+dx[ori]] != 0)
        {
            memcpy(mat,org,sizeof(mat));
            possible = false;
            break;
        }

        a+=dy[ori];
        b+=dx[ori];
        mat[a][b] = 2;
        count_cord++;
    }
    if(possible)
        count_core++;
    else
        count_cord = org_count;
    if(best>0)
        if(core.size() - idx + count_core < best)
            return 0;

    for (int i = 0; i < 5; ++i)
        answer(idx+1,i,count_cord,count_core);
    memcpy(mat,org,sizeof(mat));
    return count_cord;
}
void solve_problem(int case_num)
{
    cin>>N;
    best = -1;
    best_min = 200;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>mat[i][j];
            if(mat[i][j]==1)
                if(i!=0 && i!=N-1 && j!=0 && j!=N-1)
                    core.push_back(make_pair(i,j));
        }
    }
    for (int i = 0; i < 5; ++i) {
        answer(0,i,0,0);
    }

    printf("#%d %d\n",case_num+1, best_min);
    core.clear();
    // printf("%d\n", answer(0,0));
}
