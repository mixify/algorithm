#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N;
int L,R;
int country[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int main(int argc, char *argv[])
{
    cin>>N;
    cin>>L>>R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>country[i][j];
        }
    }
    int total_count = 0;
    bool happen;
    do{
        happen = false;
        memset(visited,0,sizeof(visited));
        queue<pair<int,int> > group;
        // for (int i = 0; i < N; ++i)
        // {
        //     for (int j = 0; j < N; ++j)
        //     {
        //         printf("%d ", country[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("----------------\n");
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int open_count;
                int sum;
                vector<pair<int,int> > places;
                open_count = 0;
                if(!visited[i][j])
                {
                    group.push(make_pair(i,j));
                    places.push_back(make_pair(i,j));
                    visited[i][j] = true;
                    sum = country[i][j];
                }
                while(!group.empty())
                {
                    pair<int,int> yx = group.front();
                    group.pop();
                    for (int i = 0; i < 4; ++i) {
                        int y = yx.first+dy[i];
                        int x = yx.second+dx[i];
                        if(y>=0 && y<N && x>=0 && x<N)
                        {
                            if(!visited[y][x])
                            {
                                int diff = abs(country[yx.first][yx.second] - country[y][x]);
                                if(L <= diff && diff <= R)
                                {
                                    happen = true;
                                    sum+=country[y][x];
                                    places.push_back(make_pair(y,x));
                                    open_count++;
                                    visited[y][x] = true;
                                    group.push(make_pair(y,x));
                                }
                            }
                        }
                    }
                }
                for (size_t k = 0; k < places.size(); ++k)
                {
                    country[places[k].first][places[k].second] = sum/places.size();
                }
            }
        }
        if(happen) total_count++;

    }while(happen);
    printf("%d\n", total_count);
    return 0;
}

