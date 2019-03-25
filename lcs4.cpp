#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;
int num[1001];
int D[1001][1001];

int m= 0;
deque<int> best_idx;
deque<int> max_idx;
int solve(int idx, int length)
{
    int &ret = D[idx][length];
    if(ret!=-1) return ret;
    if(idx==N-1)
    {
        if(m<=length)
        {
            m = length;
            max_idx = best_idx;
            // printf("size = %d\n", max_idx.size());
            // auto itr = deque<int>::iterator();
        }
        return length;
    }

    ret = 0;
    for (int i = idx+1; i < N; ++i)
    {
        if(num[idx] < num[i])
        {
            // printf("%d => %d\n", num[idx], num[i]);
            best_idx.push_front(i);
            // printf("pushing %d\n", num[i]);
            ret = max(solve(i,length+1),ret);
            // printf("poping %d\n", num[best_idx.front()]);
            best_idx.pop_front();
            // break;
        }
    }

    // if(ret!=0)
    //     best_idx.pop();
    return ret;
}

int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i)
        cin>>num[i];
    memset(D,-1,sizeof(D));
    for (int i = 0; i < N; ++i)
    {
        best_idx.push_front(i);
        // printf("pushing %d\n", num[i]);
        m= max(m,solve(i,1));
        // printf("poping %d\n", num[best_idx.front()]);
        best_idx.pop_front();
    }

    printf("%d\n", m);
    while(max_idx.size()>0)
    {
        cout<<num[max_idx.back()]<<" ";//stack 은 제이랑피 top이다
        max_idx.pop_back();
    }
    return 0;
}
