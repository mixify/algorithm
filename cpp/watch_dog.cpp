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
#include <queue>

using namespace std;
int N, M;
int office[9][9];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int cnt_cctv = 0;
struct cctv {
    int y;
    int x;
    int kind;
    int ori;
};

cctv cctvs[8];

int calc_space()
{
    bool visited[9][9];
    queue <pair <int,int> > q;
    memset(visited,0,sizeof(visited));

    for (int i = 0; i < cnt_cctv; ++i) {
        cctv cur = cctvs[i];
        int cur_y = cur.y;
        int cur_x = cur.x;
        int pre_y = cur.y;
        int pre_x = cur.x;
        int cur_ori = cur.ori;
        int next_ori = (cur_ori+1)%4;
        switch (cur.kind)
        {
            case 1:
                do
                {
                    office[cur_y][cur_x]='#';
                    cur_y+=dy[cur_ori];
                    cur_x+=dx[cur_ori];
                    if(office[cur_y][cur_x]==6)
                        break;
                }while(cur_y>=0 && cur_y<N && cur_x>=0 && cur_x < M);
                break;
            case 2:
                for (int o = 0; o < 2; ++o) {
                    do
                    {
                        office[cur_y][cur_x]='#';
                        cur_y+=dy[cur_ori];
                        cur_x+=dx[cur_ori];
                        if(office[cur_y][cur_x]==6)
                            break;
                    }while(cur_y>=0 && cur_y<N && cur_x>=0 && cur_x < M);

                    cur_y = pre_y;
                    cur_x = pre_x;
                    cur_ori = (cur_ori+2)%4;
                }

                break;
            case 3:
                for (int o = 0; o < 2; ++o) {
                    do
                    {
                        office[cur_y][cur_x]='#';
                        cur_y+=dy[cur_ori];
                        cur_x+=dx[cur_ori];
                        if(office[cur_y][cur_x]==6)
                            break;
                    }while(cur_y>=0 && cur_y<N && cur_x>=0 && cur_x < M);
                    cur_y = pre_y;
                    cur_x = pre_x;

                    cur_ori = (cur_ori+1)%4;
                }
                break;
            case 4:
                for (int o = 0; o < 3; ++o) {
                    do
                    {
                        office[cur_y][cur_x]='#';
                        cur_y+=dy[cur_ori];
                        cur_x+=dx[cur_ori];
                        if(office[cur_y][cur_x]==6)
                            break;
                    }while(cur_y>=0 && cur_y<N && cur_x>=0 && cur_x < M);

                    cur_y = pre_y;
                    cur_x = pre_x;
                    cur_ori = (cur_ori+1)%4;
                }
                break;
            case 5:
                for (int o = 0; o < 4; ++o) {
                    do
                    {
                        office[cur_y][cur_x]='#';
                        cur_y+=dy[cur_ori];
                        cur_x+=dx[cur_ori];
                        if(office[cur_y][cur_x]==6)
                            break;
                    }while(cur_y>=0 && cur_y<N && cur_x>=0 && cur_x < M);

                    cur_y = pre_y;
                    cur_x = pre_x;
                    cur_ori = (cur_ori+1)%4;
                }
                break;
            default:
                break;

        }

    }

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         if(office[i][j]=='#')
    //             printf("# ");
    //         else
    //             printf("%d ", office[i][j]);
    //     }
    //     printf("\n");
    // }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(!visited[i][j] && office[i][j] == 0)
            {
                visited[i][j] = true;
                q.push(make_pair(i,j));
                cnt++;
            }

            while(!q.empty())
            {
                pair<int,int> yx = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = yx.first + dy[k];
                    int x = yx.second + dx[k];
                    if(y >= 0 && y < N && x>=0 && x<M)
                    {
                        if(!visited[y][x] && office[y][x] == 0)
                        {
                            visited[y][x] = true;
                            // printf("%d %d\n", y,x);
                            cnt++;
                            q.push(make_pair(y,x));
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
void set_state(int state)
{
    int val;
    for (int i = 0; i < cnt_cctv; ++i) {
        val = state & 0x3;
        state = state>>2;
        cctvs[i].ori = val;
        // printf("%d", val);
    }
    // printf("\n");
}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>office[i][j];
            switch (office[i][j]) {
                case 1:
                    cctvs[cnt_cctv++] = {i,j,1,0};
                    break;
                case 2:
                    cctvs[cnt_cctv++] = {i,j,2,0};
                    break;
                case 3:
                    cctvs[cnt_cctv++] = {i,j,3,0};
                    break;
                case 4:
                    cctvs[cnt_cctv++] = {i,j,4,0};
                    break;
                case 5:
                    cctvs[cnt_cctv++] = {i,j,5,0};
                    break;
                default:
                    break;
            }
        }
    }
    int min_space = 9999999;

    int kinds = pow(2,cnt_cctv*2);
    // printf("kinds = %d\n",kinds);
    int tmp[9][9];
    memcpy(tmp,office,sizeof(office));
    for (int i = 0; i < kinds; ++i) {
        set_state(i);
        memcpy(office,tmp,sizeof(office));
        min_space = min(min_space,calc_space());
        // printf("min = %d\n", min_space);
    }
    printf("%d\n", min_space);
    return 0;
}
