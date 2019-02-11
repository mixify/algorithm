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
        if(slice_orientation==VERTICAL && crystal[i].second == x)
            return false;
        if(slice_orientation==HORIZONTAL && crystal[i].first == y)
            return false;
    }
    return true;
}
int cut_stone(int x, int y, int size_x, int size_y, int slice_orientation)
{
    vector<pair<int,int> > dirty;
    vector<pair<int,int> > crystal;
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            if(stone[y+j][x+i] == 1)
                dirty.push_back(make_pair(j,i));
            else if(stone[y+j][x+i] == 2)
                crystal.push_back(make_pair(j,i));
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

    if(dirty.size()==0)
    {
        return 0;
    }
    int ret = 0;
    vector<int> divided_y;
    vector<int> divided_x;
    for (int i = 0; i < dirty.size(); ++i)
    {
        divided_y.push_back(dirty[i].first);
        divided_x.push_back(dirty[i].second);
    }
    sort(divided_y.begin(),divided_y.end());
    sort(divided_x.begin(),divided_x.end());
    divided_y.erase(unique(divided_y.begin(),divided_y.end()),divided_y.end());
    divided_x.erase(unique(divided_x.begin(),divided_x.end()),divided_x.end());
    // for (int i = 0; i < dirty.size(); ++i)
    // {
    //     int divided_y = dirty[i].first;
    //     int divided_x = dirty[i].second;
    if(slice_orientation==UNKNOWN)
    {
        for (int i = 0; i < divided_y.size(); ++i)
            if(dividable(0,divided_y[i],HORIZONTAL,crystal))
                ret += cut_stone(x,y,size_x,divided_y[i]-y,HORIZONTAL) && cut_stone(x,divided_y[i]+1,size_x,size_y + y-divided_y[i] -1,HORIZONTAL);
        for (int i = 0; i < divided_x.size(); ++i)
            if(dividable(divided_x[i],0,VERTICAL,crystal))
                ret += cut_stone(x,y,divided_x[i]-x,size_y,VERTICAL) && cut_stone(divided_x[i]+1,y,size_x + x-divided_x[i] - 1,size_y,VERTICAL);
    }
    else if(slice_orientation == HORIZONTAL)
    {
        for (int i = 0; i < divided_x.size(); ++i)
            if(dividable(divided_x[i],0,VERTICAL,crystal))
                if(!(cut_stone(x,y,divided_x[i]-x,size_y,VERTICAL) && cut_stone(divided_x[i]+1,y,size_x + x-divided_x[i] - 1,size_y,VERTICAL)))
                    return 0;
    }
    else
    {
        for (int i = 0; i < divided_y.size(); ++i)
            if(dividable(0,divided_y[i],HORIZONTAL,crystal))
                if(!(cut_stone(x,y,size_x,divided_y[i]-y,HORIZONTAL) && cut_stone(x,divided_y[i]+1,size_x,size_y + y-divided_y[i] -1,HORIZONTAL)))
                    return 0;
    }
    // }

    if(slice_orientation==UNKNOWN)
        return ret;
    else
        return 1;
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

