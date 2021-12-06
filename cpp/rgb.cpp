#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
#define NUM_COLOR 3
#define RED 0
#define GREEN 1
#define BLUE 2

int cache[1001][3];

void solve_problem(int case_num);
int painting(vector<vector<int> > house,int n, int color);
int main(int argc, char *argv[])
{
    int num_house;
    cin>>num_house;
    vector<vector<int> > house;
    for (int i = 0; i < num_house; ++i) {
        house.push_back(vector<int> ());
        for (int j = 0; j < NUM_COLOR; ++j) {
            int n;
            cin>>n;
            house[i].push_back(n);
        }
    }

    memset(cache, -1 , sizeof(cache));
    painting(house, 0, RED);
    painting(house, 0, GREEN);
    painting(house, 0, BLUE);

    printf("%d\n", min(min(cache[0][RED],cache[0][GREEN]),cache[0][BLUE]));


    return 0;
}

int painting(vector<vector<int> > house,int n, int color)
{
    int &ret = cache[n][color];
    if(ret != -1)
        return ret;
    int val = house[n][color];

    if(n == house.size()-1)
        return ret = val;

    int color_1 = -1;
    int color_2 = -1;
    for (int i = 0; i < NUM_COLOR; ++i)
    {
        if(i==color)
            continue;
        if(color_1== -1)
            color_1 = i;
        else
            color_2 = i;
    }

    return ret = val + min(painting(house,n+1,color_1),painting(house,n+1,color_2));
}
