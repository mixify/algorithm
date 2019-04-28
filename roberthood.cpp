#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
#include <vector>
#include <stack>
#include <utility>
#include <set>
#include <map>

#define PI 3.141592
using namespace std;
int N, M;
int right_most;
int lm,rm;
pair<int,int> arrow[100000];
vector<pair<int,int> > hull;
stack<pair<int,int> > st;
// bool cmp1(pos p1, pos p2) {
// }
int comp(pair<int,int> a1, pair<int,int> a2)
{
    int ax = a1.first;
    int ay = a1.second;
    int bx = a2.first;
    int by = a2.second;

    // if(p1<0) p1+=PI*2;
    // if(p2<0) p2+=PI*2;

    return atan2(ax-rm,ay-lm) > atan2(bx-rm,by-lm);
}

int check_cw(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3)
{
    return (p2.first*p1.first)*(p3.second - p1.second) - (p2.second-p1.second)*(p3.first-p1.first);
}
pair<int,int> before_top()
{
    pair<int,int> tmp = st.top();
    st.pop();
    pair<int,int> ret = st.top();
    st.push(tmp);
    return ret;
}
double dis(pair<int,int> p1, pair<int,int> p2)
{
    return sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
}
void graham_scan()
{
    st.push(arrow[0]);
    st.push(arrow[1]);
    // st.push(arrow[2]);
    for (int i = 2; i < N; ++i)
    {
        while(st.size()>=2 && check_cw(before_top(),st.top(),arrow[i]) <= 0)
            st.pop();
        st.push(arrow[i]);
    }
    while(!st.empty())
    {
        pair<int,int> t = st.top();
        hull.push_back(t);
        // cout << "(" << t.first << ", " << t.second << ")" << endl;
        st.pop();
    }
    double max_dis = 0;
    for (int i = 0; i < hull.size()-1; ++i)
    {
        for (int j = i+1; j < hull.size(); ++j) {
            max_dis = max(max_dis, dis(hull[i],hull[j]));
        }
    }
    printf("%lf\n", max_dis);
}
int main(int argc, char *argv[])
{
    cin>>N;
    rm = -1000;
    lm = 1000;
    // return p1.x < p2.x || (p1.x == p2.x) && (p1.y < p2.y);
    for (int i = 0; i < N; ++i)
    {
        int x,y;
        cin>>x>>y;
        arrow[i] = make_pair(x,y);
        if(y < lm)
        {
                lm = y;
                rm = x;
                right_most = i;


        }
        else
        {
            if(y == lm && x>rm)
            {
                lm = y;
                rm = x;
                right_most = i;
            }
        }
    }
    // for (int i = 0; i < N; ++i) {
    //     if(i==right_most) continue;
    //     arrow[i].first = arrow[i].first - arrow[right_most].first;
    //     arrow[i].second = arrow[i].second - arrow[right_most].second;
    // }
    sort(arrow,arrow+N,comp);
    graham_scan();
    // for (int i = 0; i < N; ++i)
    //     printf("%d %d\n", arrow[i].first, arrow[i].second);
    return 0;
}
