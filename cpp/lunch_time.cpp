#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <map>
#include <deque>

using namespace std;
int N, M;
int m[11][11];

struct stair
{
    int y;
    int x;
    int dis;
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

    vector<pair<int,int > > people;
    vector<stair> stairs;

    deque <int> st[2];

    int max;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>m[i][j];
            if(m[i][j] == 1)
                people.push_back(make_pair(i,j));
            else if(m[i][j] > 1)
                stairs.push_back({i,j,m[i][j]});
        }
    }

    max = pow(2,people.size());
    int best = 99999999;
    // cout<<max<<endl;
    for (int i = 0; i <= max; ++i) {
        int bin = i;
        vector<pair<int,int> > go;
        for (int j = 0; j < people.size(); ++j) {
            int val = bin & 1;

            int dis = abs(stairs[val].y - people[j].first) + abs(stairs[val].x - people[j].second);
            go.push_back(make_pair(dis,val));

            bin = bin>>1;
        }
        int p_cnt = people.size();
        int time = 0;
        while(p_cnt > 0)
        {
            for(auto &sts : st)
            {
                int end_cnt = 0;
                for(auto &t: sts)
                {
                    if(--t == 0)
                    {
                        p_cnt--;
                        end_cnt++;
                    }
                }
                for(int cnt = 0 ; cnt < end_cnt ; cnt++) sts.pop_front();
            }
            for(auto &it : go)
            {
                if(--it.first == -1)
                {
                    if(st[it.second].size() < 3)
                        st[it.second].push_back(stairs[it.second].dis);
                    else
                        it.first++;
                }
            }
            time++;
        }
        // cout<<time<<" "<<i<<endl;
        best = min(time,best);

    }
    cout<<"#"<<case_num<<" "<<best<<endl;
}
