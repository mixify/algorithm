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
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int grid[4000][4000];

struct atom{
    int x;
    int y;
    int dir;
    int energy;
};

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

void solve_problem(int case_num)
{
    cin>>N;
    vector<atom> qt;
    for (int i = 0; i < N; ++i) {
        int x,y,dir,energy;
        cin>>x>>y>>dir>>energy;
        qt.push_back({x*2 + 2000,y*2 + 2000,dir,energy});
    }

    memset(grid,0,sizeof(grid));
    int total_energy = 0;
    int cnt = 0;
    for (int i = 0; i < 4000; ++i)
    {

        for(int j = 0 ; j < qt.size() ; j++)
        {
            atom &q = qt[j];

            // if(i<10)
            //     printf("%d %d\n", q.x,q.y);
            if(q.energy < 0)
                continue;

            q.x = q.x + dx[q.dir];
            q.y = q.y + dy[q.dir];
            if(q.x < 0 || q.x > 4000 || q.y < 0 || q.y > 4000)
            {
                q.energy = -1;
                cnt++;
                continue;
            }
            grid[q.x][q.y]++;

            // grid[q.x][q.y] = q.energy;
        }

        for(int j = 0 ; j < qt.size() ; j++)
        {
            atom &q = qt[j];
            if(q.energy > 0)
                if(grid[q.x][q.y] > 1)
                {
                    total_energy += q.energy;
                    q.energy = -1;
                }
        }
        for(int j = 0 ; j < qt.size() ; j++)
        {
            atom &q = qt[j];
            if(q.x < 0 || q.x > 4000 || q.y < 0 || q.y > 4000)
                ;
            else
                grid[q.x][q.y] = 0;
        }
        // vector<atom> tmp;
        if(qt.size() == cnt) break;
    }

    printf("#%d %d\n", case_num+1, total_energy);

}
