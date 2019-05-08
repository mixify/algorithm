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

int gd1[101][101];
int gd2[101][101];

int visited1[101][101];
int visited2[101][101];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

vector< vector<pair<int,int> > > region1;
vector< vector<pair<int,int> > > region2;
int countMatches(vector<string> grid1, vector<string> grid2) {
    int N = grid1.size();
    int M = grid2.size();
    memset(visited1,0,sizeof(visited1));
    memset(visited2,0,sizeof(visited2));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            gd1[i][j] = grid1[i][j]-'0';
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j)
            gd2[i][j] = grid2[i][j]-'0';
    }

    queue<pair<int,int> > q;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(!visited1[i][j] && gd1[i][j]==1)
            {
                q.push(make_pair(i,j));
                visited1[i][j] = true;
                vector<pair<int,int> > cur_region;
                while(!q.empty())
                {
                    pair<int,int> cur = q.front();
                    cur_region.push_back(make_pair(cur.first,cur.second));
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int y = cur.first + dy[i];
                        int x = cur.second + dx[i];
                        if(y>=0 && y<N && x>=0 && x<N)
                        {
                            if(!visited1[y][x] && gd1[y][x]==1)
                            {
                                visited1[y][x] = true;
                                q.push(make_pair(y,x));
                            }
                        }
                    }
                }
                region1.push_back(cur_region);
            }
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if(!visited2[i][j] && gd2[i][j]==1)
            {
                q.push(make_pair(i,j));
                visited2[i][j] = true;
                vector<pair<int,int> > cur_region;
                while(!q.empty())
                {
                    pair<int,int> cur = q.front();
                    cur_region.push_back(make_pair(cur.first,cur.second));
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int y = cur.first + dy[i];
                        int x = cur.second + dx[i];
                        if(y>=0 && y<M && x>=0 && x<M)
                        {
                            if(!visited2[y][x] && gd2[y][x]==1)
                            {
                                visited2[y][x] = true;
                                q.push(make_pair(y,x));
                            }
                        }
                    }
                }
                region2.push_back(cur_region);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < region1.size(); ++i) {
        for (int j = 0; j < region2.size(); ++j) {
            {
                vector<pair<int,int> > rg1= region1[i];
                vector<pair<int,int> > rg2= region2[j];
                if(rg1.size()!=rg2.size()) continue;
                sort(rg1.begin(), rg1.end());
                sort(rg2.begin(), rg2.end());
                bool same = true;
                for (int k = 0; k < rg1.size(); ++k) {
                    if(rg1[k] != rg2[k])
                    {
                        same = false;
                        break;
                    }
                }
                if(same) count++;
            }
        }
    }


    return count;
}

int main(int argc, char *argv[])
{
    int N;
    cin>>N;
    vector<string> grid1;
    vector<string> grid2;
    for (int i = 0; i < N; ++i) {
        string str; cin>>str;
        grid1.push_back(str);
    }
    cin>>N;
    for (int i = 0; i < N; ++i) {
        string str; cin>>str;
        grid2.push_back(str);
    }
    printf("%d\n", countMatches(grid1,grid2));
    return 0;
}

