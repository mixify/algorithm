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

#define LEFT 1
#define ON 0
#define RIGHT -1

struct point{
    long long x;
    long long y;
};
struct line{
    point start;
    point end;
    line *parent;
    int height;
};
using namespace std;
int N;

line lines[3000];

long long sign_area(point a,point b,point c)
{
    // if(c.y==4)
    //     printf("%d - %d + %d - %d + %d - %d\n", a.x*b.y , a.y*b.x , b.x*c.y , c.x*b.y , c.x*a.y , a.x*c.y);
    // printf("%lld\n", (a.x*b.y - a.y*b.x + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y));
    long long sa = (a.x*b.y - a.y*b.x + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y);
    return sa==1?1:sa/2;
}
int left(point a, point b, point c)
{
    //c is the main
    // if(c.y==4)
    // {
    //     printf("sibal\n");
    //     printf("%lld\n", sign_area(a,b,c));
    // }
    if(sign_area(a,b,c) > 0) return true;
    else return false;
    // else if (sign_area(a,b,c) == 0) return ON;
    // else return RIGHT;
}
double distance(point a, point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
int between(point a, point b, point c)
{
    if(sign_area(a,b,c)==0)
    {
        long long crossproduct = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
        long long dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
        long long squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
        if(abs(crossproduct) > 0) return false;
        if(dotproduct<0) return false;
        if(dotproduct>squaredlengthba) return false;
        // long long dxc = c.x - a.x;
        // long long dyc = c.y - a.y;
        //
        // long long dx1 = b.x - a.x;
        // long long dy1 = b.y - a.y;
        //
        // long long cross = dxc * dy1 - dyc * dx1;
        return true;
        // if(distance(a,c) + distance(b,c) == distance(a,b))
        //     return true;
    }
    return false;
}

bool intersect(point a, point b,point c,point d)
{
    if(between(a,b,c) || between(a,b,d) || between(c,d,a) || between(c,d,b)) return true;
    // printf("sibal\n");
    // printf("%d %d %d %d\n", left(a,b,c),left(a,b,d) ,left(c,d,a),left(c,d,b));
    return ( (left(a,b,c)^left(a,b,d)) && (left(c,d,a)^left(c,d,b)) );
}

void create_set(line *x)
{
    x->parent = x;
    x->height = 1;
}
line* find_set(line *x)
{
    if(x->parent == NULL) return NULL;
    while(x!=x->parent)
        x = x->parent;
    return x;
}

void merge(line *x, line *y)
{
    line *a=find_set(x);
    line *b=find_set(y);
    if(a->height <= b->height)
    {
        if(a->height == b->height) b->height++;
        a->parent = b;
    }
    else b->parent = a;
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        cin>>lines[i].start.x>>lines[i].start.y;
        cin>>lines[i].end.x>>lines[i].end.y;
        lines[i].parent = NULL;
    }
    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            if(lines[i].parent == NULL)
                create_set(lines+i);
            if(lines[j].parent == NULL)
                create_set(lines+j);
            if(intersect(lines[i].start,lines[i].end,lines[j].start,lines[j].end))
            {
                // printf("%d %d\n", i,j);
                merge(lines+i,lines+j);
            }
        }
    }

    map<line *, int> groups;
    for (int i = 0; i < N; ++i)
    {
        auto addr = find_set(lines+i);
        // printf("%x %d\n", addr, i);
        if(groups.count(addr) == 1)
            groups[addr] = groups[addr]+1;
        groups.insert(make_pair(find_set(lines+i),1));
    }

    printf("%lu\n", groups.size());
    int m = 0;
    for(auto itr=groups.begin() ; itr !=groups.end() ; itr++)
    {
        m = max(m,itr->second);
    }
    printf("%d\n", m);
    // printf("%d\n", intersect({0,0},{0,4},{-1,2},{1,5}));
    // printf("%d\n", intersect({0,0},{0,4},{-1,2},{1,5})); should care later
    return 0;
}
