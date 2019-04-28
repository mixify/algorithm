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
int check_cw(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    int res = (q.second - p.second)*(r.first - q.first) -
        (q.first-p.first)*(r.second-q.second);
    if(res==0) {
        return 0;
    }
    return (res>0)?1:2;
}

pair<int,int> swp(pair<int,int> *p1, pair<int,int> *p2)
{
    pair<int,int> tmp = make_pair((*p2).first,(*p2).second);
    p2->first = p1->first;
    p2->second = p1->second;
    p1->first = tmp.first;
    p1->second = tmp.second;
}
int dis(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.first-p2.first)*(p1.first-p2.first) +
        (p1.second-p2.second)*(p1.second-p2.second);
}

int comp(const void *p1, const void *p2)
{
    pair<int,int> a1 = *((pair<int,int>*)p1);
    pair<int,int> a2 = *((pair<int,int>*)p2);
    pair<int,int> org = make_pair(rm,lm);
    // printf("%d %d\n", rm,lm);
    int res = check_cw(org,a1,a2);
    if(res == 0)
    {
        return(dis(org, a2) >= dis(org, a1))?-1:1;
    }
    return (res==2)?-1:1;
    // printf("sibal %d %d %d %d\n",a1.first,a1.second,a2.first,a2.second);
    // if(p1<0) p1+=PI*2;
    // if(p2<0) p2+=PI*2;
}

pair<int,int> before_top()
{
    pair<int,int> tmp = st.top();
    st.pop();
    pair<int,int> ret = st.top();
    st.push(tmp);
    return ret;
}
void graham_scan()
{
    st.push(arrow[0]);
    st.push(arrow[1]);
    // st.push(arrow[2]);
    for (int i = 2; i < N; ++i)
    {
        while(st.size()>=2 && check_cw(before_top(),st.top(),arrow[i]) != 2)
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
            max_dis = max(max_dis, sqrt(dis(hull[i],hull[j])));
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
        if(y < lm || (lm == y && x < rm))
        {
            lm = y;
            rm = x;
            right_most = i;
        }
    }
    swp(arrow,arrow+right_most);
    // printf("%d %d haha\n", arrow[0].first, arrow[0].second);
    // for (int i = 0; i < N; ++i) {
    //     if(i==right_most) continue;
    //     arrow[i].first = arrow[i].first - arrow[right_most].first;
    //     arrow[i].second = arrow[i].second - arrow[right_most].second;
    // }
    qsort(&arrow[1],N-1,sizeof(pair<int,int>),comp);
    // for (int i = 0; i < N; ++i)
    //     printf("%d %d\n", arrow[i].first, arrow[i].second);
    graham_scan();
    return 0;
}
