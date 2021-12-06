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
int loc[51][51];

int dy[4] = {-1,-1,1,1};
int dx[4] = {1,-1,1,-1};

vector <pair<int,int> > house;
vector <pair<int,int> > chicken;


int get_chicken_dis(vector<int> comb)
{
    int chicken_dis = 0;
    // printf("--------------\n");
    for (int i = 0; i < chicken.size(); ++i) {
        pair<int,int> chicken_pos = chicken[i];
        loc[chicken_pos.first][chicken_pos.second] = 0;
    }
    for (int i = 0; i < comb.size(); ++i) {
        pair<int,int> chicken_pos = chicken[comb[i]];
        loc[chicken_pos.first][chicken_pos.second] = 2;
    }

    for (int i = 0; i < house.size(); ++i) {
        pair<int,int> house_pos = house[i];
        // printf("house = %d %d\n", house[i].first,house[i].second);
        int find_d;

        for (int d = 1; d <= 2*N; ++d) {
            // printf("d = %d\n", d);
            for (int k = 0; k < 4; ++k) {
                for (int j = d; j >= 0; --j) {
                    int y = house[i].first+j*dy[k];
                    int x = house[i].second+(d-j)*dx[k];
                    if(y<0 || x<0 || y>N || x>N)
                        continue;
                    if(loc[y][x] == 2)
                    {
                        find_d = d;
                        goto find;
                    }
                    // printf("%d %d\n", y,x);
                }
            }
        }
        find:
        chicken_dis += find_d;
    }
    return chicken_dis;
}

vector <vector<int> > combination(int n, int r)
{
    vector <vector<int> > comb;
    vector <int> num;
    for (int i = 0; i < n; ++i) {
        num.push_back(i);
    }
    vector<int> ind;

    for (int i = 0; i < r; ++i) {
        ind.push_back(1);
    }
    for (int i = 0; i < n-r; ++i) {
        ind.push_back(0);
    }

    sort(ind.begin(),ind.end());

    do{
        vector<int> one_comb;
        for (int i = 0; i < ind.size(); ++i) {
            if(ind[i] == 1)
                one_comb.push_back(num[i]);
        }
        comb.push_back(one_comb);
    }while(next_permutation(ind.begin(),ind.end()));

    return comb;
}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin>>loc[i][j];
            if(loc[i][j] == 2)
                chicken.push_back(make_pair(i,j));
            else if(loc[i][j] == 1)
                house.push_back(make_pair(i,j));
        }
    }

    vector <vector<int> > comb;
    comb = combination(chicken.size(),M);

    // for (int i = 0; i < comb.size(); ++i) {
    //     for (int j = 0; j < comb[i].size(); ++j) {
    //         printf("%d ", comb[i][j]);
    //     }
    //     printf("\n");
    // }

    int tmp[51][51];
    int min_dis = 999999;
    memcpy(tmp,loc,sizeof(loc));
    for (int i = 0; i < comb.size(); ++i) {
        memcpy(loc,tmp,sizeof(loc));
        min_dis = min(get_chicken_dis(comb[i]),min_dis);
    }
    printf("%d\n", min_dis);

    return 0;
}
