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

struct bc{
    int x;
    int y;
    int c;
    int p;
};

int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};
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
    vector<int> p1;
    vector<int> p2;
    vector<bc> batteries;
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        int x;
        cin>>x;
        p1.push_back(x);
    }

    for (int i = 0; i < N; ++i) {
        int x;
        cin>>x;
        p2.push_back(x);
    }
    int p1x = 1;
    int p1y = 1;
    int p2x = 10;
    int p2y = 10;
    for (int i = 0; i < M; ++i) {
       int x,y,c,p;
       cin>>x>>y>>c>>p;
       batteries.push_back({x,y,c,p});
    }
    int total_charge = 0;
    for (int i = -1; i < N; ++i) {

        vector<int> p1b;
        vector<int> p2b;

        if(i >= 0)
        {
            p1x += dx[p1[i]];
            p1y += dy[p1[i]];
            p2x += dx[p2[i]];
            p2y += dy[p2[i]];
        }

        int charge = 0;
        for(int j = 0 ; j < batteries.size() ; j++)
        {
            bc b = batteries[j];
            int d1 = abs(b.x-p1x) + abs(b.y-p1y);
            if(d1 <= b.c) p1b.push_back(j);
            int d2 = abs(b.x-p2x) + abs(b.y-p2y);
            if(d2 <= b.c) p2b.push_back(j);
        }

        if(p1b.size() == 0)
        {
            for(int b2 : p2b)
                charge = max(charge, batteries[b2].p);
        }
        else if(p2b.size() == 0)
        {
            for(int b1 : p1b)
                charge = max(charge, batteries[b1].p);
        }
        else
        {

            for(int b1 : p1b)
                for(int b2 : p2b)
                {
                    if(b1==b2) charge = max(charge,batteries[b1].p);
                    else charge = max(charge,batteries[b1].p+batteries[b2].p);
                }
        }

        // printf("%d\n", charge);

        total_charge += charge;


    }
    printf("#%d %d\n", case_num+1, total_charge);
}
