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
int curve[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int gen_cnt[11] = {1,1,2,4,8,16,32,64,128,256,512};

void dragon_curve(int x,int y,vector<int> ori,int gen,int cur)
{
    curve[x][y] = 1;
    // printf("gen %d\n", cur);
    // if(cur==0)
    //     printf("%d %d\n", x, y);
    for (int i = 0; i < gen_cnt[cur]; ++i)
    {
        if(cur==0)
        {
            x+=dx[ori[i]];
            y+=dy[ori[i]];
        }
        else
        {
            int new_ori = ori[gen_cnt[cur] - i -1];
            new_ori++;
            // printf("%d - %d\n", gen_cnt[cur] , i+1);
            new_ori = new_ori%4;
            ori.push_back(new_ori);
            x+=dx[new_ori];
            y+=dy[new_ori];
        }
        // printf("%d %d\n", x, y);
        curve[x][y] = 1;
    }

    if(cur == gen) return;

    dragon_curve(x,y,ori,gen,cur+1);
}
int count_square()
{
    int cnt = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if(curve[i][j] + curve[i+1][j] + curve[i][j+1] + curve[i+1][j+1] == 4)
                cnt++;
        }
    }
    return cnt;
}
int main(int argc, char *argv[])
{
    cin>>N;
    memset(curve,0,sizeof(curve));
    for (int i = 0; i < N; ++i)
    {
        int x,y,ori,gen;
        scanf("%d %d %d %d", &x, &y, &ori, &gen);
        dragon_curve(x,y,vector<int>(1,ori),gen,0);
        // printf("-----------------\n");
    }
    printf("%d\n", count_square());
    return 0;
}

void solve_problem(int case_num)
{

}
