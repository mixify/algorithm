#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
vector<pair<int,int> > dots;

int solve(int left, int right);
int distance(int i1, int i2);
bool compare_x(pair <int,int> p1, pair <int,int> p2)
{
    return p1.first<p2.first;
}
int main(int argc, char *argv[])
{
    int num_dots;
    cin>>num_dots;
    for (int i = 0; i < num_dots; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        dots.push_back(make_pair(x,y));
    }

    // sort(dots.begin(), dots.end(),compare_x);
    printf("%d\n", solve(0, dots.size()-1));
    return 0;
}

int solve(int left, int right)
{
    if(left-right ==1 || right-left == 1)
        return distance(left,right);

    int mid = (left+right) / 2;
    int ret = min(solve(left,mid), solve(mid+1,right));

    int lo = mid, hi = mid;

    // ret = min(ret, distance(lo,hi));

    // int max_y,min_y;
    // int max_y = min_y = dots[mid].second;

    while(left < lo || hi < right)
    {
        // if(hi < right && (lo == left || max_y-dots[] > )))
        if(hi < right && (lo == left || distance(mid,lo-1) > distance(mid,hi+1)))
        {
            ++hi;
            ret = min(ret, distance(mid,hi));
        }
        else
        {
            --lo;
            ret = min(ret, distance(mid,lo));
        }
    }

    return ret;
}
int distance(int i1, int i2)
{
    pair<int,int> d1 = dots[i1];
    pair<int,int> d2 = dots[i2];
    return (d1.first-d2.first) * (d1.first-d2.first) + (d1.second-d2.second) * (d1.second-d2.second);
}
