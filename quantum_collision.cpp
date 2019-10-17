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

struct atom{
    int x;
    int y;
    int dir;
    int energy;
};

struct grid{
    int val;
    int y;
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
        qt.push_back({x*2,y*2,dir,energy});
    }

    int total_energy = 0;
    int cnt = 0;
    for (int i = 0; i < 4000; ++i)
    {

        map<pair<int,int> , vector<int> > next;

        for(int j = 0 ; j < qt.size() ; j++)
        {
            atom &q = qt[j];

            // if(i<10)
            //     printf("%d %d\n", q.x,q.y);
            if(q.energy < 0)
                continue;

            q.x = q.x + dx[q.dir];
            q.y = q.y + dy[q.dir];
            if(q.x < -2000 || q.x > 2000 || q.y < -2000 || q.y > 2000)
            {
                q.energy = -1;
                cnt++;
                continue;
            }

            // next[make_pair(q.x,q.y)].push_back(j);
            // grid[q.x][q.y] = q.energy;
        }
        // for(auto it : next)
        // {
        //     if(it.second.size() > 1)
        //     {
        //         for(int j : it.second)
        //         {
        //             total_energy += qt[j].energy;
        //             qt[j].energy = -1;
        //             cnt++;
        //         }
        //     }
        // }
        // vector<atom> tmp;
        if(qt.size() == cnt) break;
    }
    printf("#%d %d\n", case_num+1, total_energy);

}
