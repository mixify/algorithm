#include <stdio.h>
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
bool compare_x(pair <int,int> p1, pair <int,int> p2)
{
    return p1.first<p2.first;
}

int brute()
{
    int min = 99999999;
    for (int i = 0; i < dots.size()-1; ++i) {
        for (int j = i+1; j < dots.size(); ++j) {
            int dis = distance(i,j);
            if(dis < min)
            {
                min = dis;
            }
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
    printf("%d", brute());
    end = clock();
    // cout<<"time = "<<end-begin<<endl;
    begin = clock();
    sort(dots.begin(), dots.end(),compare_x);
    // printf("my_algo = %d\n", solve(0, dots.size()-1));
    end = clock();
    // cout<<"time = "<<end-begin<<endl;
    return 0;
}

int solve(int left, int right)
{
    if(left-right ==1 || right-left == 1)
        return distance(left,right);

    int mid = (left+right) / 2;
    int ret;
    if(mid+1 == right)
        ret = solve(left,mid);
    else
        ret = min(solve(left,mid), solve(mid+1,right));

    int lo = mid, hi = mid;

    // ret = min(ret, distance(lo,hi));

    int max_y,min_y;
    max_y = min_y = dots[mid].second;

    while(left < lo || hi < right)
    {
        // if(hi < right && (lo == left || distance(mid,lo-1) > distance(mid,hi+1)))
        int left_diff = abs(max_y - dots[lo-1].second) < abs(min_y - dots[lo-1].second) ? abs(max_y - dots[lo-1].second) : abs(min_y - dots[lo-1].second);
        int right_diff = abs(max_y - dots[hi+1].second) < abs(min_y - dots[hi+1].second) ? abs(max_y - dots[hi+1].second) : abs(min_y - dots[hi+1].second);
        if(hi < right && (lo == left || left_diff > right_diff ))
        {
            ++hi;
            if(max_y < dots[hi].second)
                max_y = dots[hi].second;
            else if(min_y > dots[hi].second)
                min_y = dots[hi].second;

            ret = min(ret, distance(mid,hi));
        }
        else
        {
            --lo;
            if(max_y < dots[lo].second)
                max_y = dots[lo].second;
            else if(min_y > dots[lo].second)
                min_y = dots[lo].second;

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
