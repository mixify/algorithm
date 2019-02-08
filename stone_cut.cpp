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

#define VERTICAL 0
#define HORIZONTAL 1
#define UNKNOWN -1

using namespace std;
int N, M;
vector<vector<int> > stone;

bool dividable(int x, int y, int slice_orientation,vector<pair<int,int> > crystal)
{
    for (int i = 0; i < crystal.size(); ++i) {
        if(slice_orientation==VERTICAL && crystal[i].first == x)
            return false;
        if(slice_orientation==HORIZONTAL && crystal[i].second == y)
            return false;
    }
    return true;
}
int cut_stone(int x, int y, int size_x, int size_y, int slice_orientation)
{
    vector<pair<int,int> > dirty;
    vector<pair<int,int> > crystal;
    for (int i = x; i < size_x; ++i) {
        for (int j = y; j < size_y; ++j) {
            if(stone[i][j] == 1)
                dirty.push_back(make_pair(i,j));
            else if(stone[i][j] == 2)
                crystal.push_back(make_pair(i,j));
        }
    }

    if(crystal.size()==0) return 0;
    //제일 끝부분 자를 수도 있으니 그것도 고려하자
    if(crystal.size()==1)
    {
        if(dirty.size()==0)
            return 1;
        else
            return 0;
    }

    for (int i = 0; i < dirty.size(); ++i)
    {
        int divided_x = dirty[i].first;
        int divided_y = dirty[i].second;
        if(slice_orientation==UNKNOWN)
        {
            if(dividable(divided_x,divided_y,VERTICAL,crystal))
            {
                cut_stone(x,y,divided_x-x,y,VERTICAL);
                cut_stone(divided_x+1,y,size_x + x-divided_x - 1,y,VERTICAL);
            }
            if(dividable(divided_x,divided_y,HORIZONTAL,crystal))
            {
                cut_stone(x,y,x,divided_y-y,HORIZONTAL);
                cut_stone(x,divided_y+1,x,size_y + y-divided_y -1,HORIZONTAL);
            }
        }
        else if(slice_orientation == HORIZONTAL)
        {
            cut_stone(x,y,divided_x-x,y,VERTICAL);
            cut_stone(divided_x+1,y,size_x + x-divided_x - 1,y,VERTICAL);
        }
        else
        {
            cut_stone(x,y,x,divided_y-y,HORIZONTAL);
            cut_stone(x,divided_y+1,x,size_y + y-divided_y -1,HORIZONTAL);
        }
    }
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        stone.push_back(vector <int>());
        for (int j = 0; j < N; ++j) {
            int in; cin>>in; stone[i].push_back(in);
        }
    }
    int pr = cut_stone(0,0,N,N,-1);
    printf("%d\n",pr==0?-1:pr);
    return 0;
}

