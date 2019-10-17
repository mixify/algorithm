#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;
int K;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int cell[1001][1001];

struct cells {
    int y;
    int x;
    int val;
    int t;
};

bool operator <(cells c1, cells c2)
{
    return c1.val < c2.val;
}

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
    cin>>N>>M;
    cin>>K;

    vector<cells> deactivate;
    vector<cells> activate;
    priority_queue<cells> clone;

    memset(cell,0,sizeof(cell));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>cell[i+500][j+500];
            if(cell[i+500][j+500]>0)
                deactivate.push_back({i+500,j+500,cell[i+500][j+500],cell[i+500][j+500]});
        }
    }
    for (int t = 0; t < K; ++t) {


        auto c = activate.begin();

        while(c != activate.end())
        {
            if(++c->t == 1)
                clone.push({c->y,c->x,c->val,c->val});

            if(c->t == c->val)
            {
                cell[c->y][c->x] = -c->val;
                c = activate.erase(c);
            }
            else
                c++;
        }

        while(!clone.empty())
        {
            auto c = clone.top();
            clone.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = c.y + dy[i];
                int nx = c.x + dx[i];
                if(cell[ny][nx] == 0)
                {
                    deactivate.push_back({ny,nx,c.val,c.val+1});
                    cell[ny][nx] = c.val;
                }
            }
        }

        c = deactivate.begin();

        while(c != deactivate.end())
        {
            if(--c->t == 0)
            {
                activate.push_back({c->y,c->x,c->val,0});
                c = deactivate.erase(c);
            }
            else
                c++;
        }


    }

    printf("#%d %d\n", case_num+1, deactivate.size() + activate.size());

}
