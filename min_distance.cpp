#include <stdio.h>
#include <climits>
#include <time.h>
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
int distance_by_point(pair<int,int> d1, pair<int,int> d2);
bool compare_y(pair <int,int> p1, pair <int,int> p2)
{
    if(p1.second = p2.second)
        return p1.first < p2.first;
    return p1.second<p2.second;
}
bool compare_x(pair <int,int> p1, pair <int,int> p2)
{
    if(p1.first = p2.first)
        return p1.second < p2.second;
    return p1.first<p2.first;
}

int brute()
{
    int min = 999999999;
    for (int i = 0; i < dots.size()-1; ++i) {
        for (int j = i+1; j < dots.size(); ++j) {
            int dis = distance(i,j);
            if(dis < min)
                min = dis;
        }
    }
    return min;
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

    clock_t begin,end;
    begin = clock();
    // printf("answer = %d\n", brute());
    end = clock();
    // cout<<"time = "<<end-begin<<endl;
    begin = clock();
    sort(dots.begin(), dots.end(),compare_x);
    // printf("my_algo = %d\n", solve(0, dots.size()-1));
    printf("%d\n", solve(0, dots.size()));
    end = clock();
    // cout<<"time = "<<end-begin<<endl;
    return 0;
}

int solve(int left, int right)
{
    if(left == right)
        return INT_MAX;

    int mid = (left+right) / 2;
    int ret;
    ret = min(solve(left,mid), solve(mid+1,right));

    int lo = mid, hi = mid+1;
    // ret = min(ret, distance(lo,hi));
    vector<pair<int,int> > cand_lo;
    vector<pair<int,int> > cand_hi;

    ret = min(ret, distance(lo,hi));
    int y_dis = abs(dots[lo].second - dots[hi].second);

    for (int i = mid-1; i >= left; --i)
        if(abs(dots[i].second - dots[mid].second) <= y_dis)
            cand_lo.push_back(make_pair(dots[i].first,dots[i].second));
    for(int i = mid+2; i < right ; i++)
        if(abs(dots[i].second - dots[mid+1].second) <= y_dis)
            cand_hi.push_back(make_pair(dots[i].first,dots[i].second));

    // sort(cand_lo.begin(), cand_lo.end(), compare_y);
    // sort(cand_hi.begin(), cand_hi.end(), compare_y);

    vector<pair<int,int> >::iterator lo_iter,hi_iter;
    lo_iter = cand_lo.begin();
    hi_iter = cand_hi.begin();
    while(cand_lo.size() > 0 || cand_hi.size() > 0)
    {
        if(cand_lo.size()==0)
        {
            ret = min(ret, distance_by_point(*hi_iter,dots[mid+1]));
            cand_hi.erase(hi_iter);
        }
        else if(cand_hi.size()==0)
        {
            ret = min(ret, distance_by_point(*lo_iter,dots[mid]));
            cand_lo.erase(lo_iter);
        }
        else
        {
            if(abs(lo_iter->second - dots[mid].second) > abs(hi_iter->second - dots[mid+1].second))
            {
                ret = min(ret, distance_by_point(*hi_iter,dots[mid+1]));
                cand_hi.erase(hi_iter);
            }
            else
            {
                ret = min(ret, distance_by_point(*lo_iter,dots[mid]));
                cand_lo.erase(lo_iter);
            }
        }
    }

    return ret;
}
int distance(int i1, int i2)
{
    if(i1 == i2)
        return INT_MAX;
    pair<int,int> d1 = dots[i1];
    pair<int,int> d2 = dots[i2];
    return (d1.first-d2.first) * (d1.first-d2.first) + (d1.second-d2.second) * (d1.second-d2.second);
}
int distance_by_point(pair<int,int> d1, pair<int,int> d2)
{
    return (d1.first-d2.first) * (d1.first-d2.first) + (d1.second-d2.second) * (d1.second-d2.second);
}
