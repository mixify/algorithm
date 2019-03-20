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
int cache[21][21][401];

vector<vector <int> > aquarium;

bool out_of_boundary(int y,int x)
{
    if(y<0 || y>=N)
        return true;
    if(x<0 || x>=N)
        return true;
    return false;
}
int solve(int y, int x, int shark_size, int fish_count, int time,int length, vector<int> fish)
{
    // printf("%d %d\n", y, x);
    if(out_of_boundary(y,x)) return 999;
    int &ret = cache[y][x][time];
    if(ret!=-1)
    {
        // printf("%d %d %d %d in cache..\n",y,x,fish_count,time);
        return ret;
    }
    if(shark_size < aquarium[y][x]) return ret = 999;
    int org;
    org = aquarium[y][x];
    if(org!=0 && org < shark_size)
    {
        fish_count++;
        length++;
        fish[org]--;
        aquarium[y][x] = 0;
        if(shark_size == fish_count)
        {
            shark_size++;
            fish_count = 0;
        }
    }
    // time++;
    if(time > N*N) {
        aquarium[y][x] = org;
        return ret = 999;
    }

    bool pos = false;
    for (int i = 1; i < shark_size; ++i) {
        if(fish[i]!=0)
        {
            pos = true;
            break;
        }
    }
    if(!pos)
    {
        aquarium[y][x] = org;
        return ret = time;
    }

    ret = 999;
    ret = min(ret,solve(y-1,x,shark_size,fish_count,time+1,length,fish));
    ret = min(ret,solve(y,x-1,shark_size,fish_count,time+1,length,fish));
    ret = min(ret,solve(y+1,x,shark_size,fish_count,time+1,length,fish));
    ret = min(ret,solve(y,x+1,shark_size,fish_count,time+1,length,fish));

    // printf("y = %d x = %d time = %d\n", y,x,time);
    // printf("%d %d %d %d\n",solve(y-1,x,shark_size,fish_count,remaining,time)
    //         ,solve(y,x-1,shark_size,fish_count,remaining,time)
    //         ,solve(y+1,x,shark_size,fish_count,remaining,time)
    //         ,solve(y,x+1,shark_size,fish_count,remaining,time));

    aquarium[y][x] = org;
    // fish[org]++;

    // if(ret = 999) return ret = 0;

    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N;
    int start_y, start_x;
    vector<int> fish(7,0);
    fish.push_back(0);
    for (int i = 0; i < N; ++i) {
        aquarium.push_back(vector <int>());
        for (int j = 0; j < N; ++j) {
            int in; cin>>in; aquarium[i].push_back(in);
            if(in>=1 && in <= 6) fish[in]++;
            if(in == 9) {start_y = i; start_x = j; aquarium[start_y][start_x] = 0;}
        }
    }

    memset(cache, -1, sizeof(cache));
    printf("%d\n", solve(start_y,start_x,2,0,1,0,fish)-1);
    return 0;
}
