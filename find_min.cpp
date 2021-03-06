#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N,L;
vector<int> ary;
deque<pair<int,int> > dq;
int main(int argc, char *argv[])
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i) {
        int in; scanf("%d",&in); ary.push_back(in);
    }
    // i-L+1 ~ i
    for (int i = 0; i < N; ++i) {
        printf("incoming = %d\n", ary[i]);
        if(dq.empty())
            dq.push_back(make_pair(i,ary[i]));
        else
        {
            while(!dq.empty() && i - dq.front().first>=L) dq.pop_front();
            while(!dq.empty() && dq.back().second>ary[i]) dq.pop_back();
            dq.push_back(make_pair(i,ary[i]));
        }
        for (int i = 0; i < dq.size(); ++i) {
            printf("%d ", dq[i].second);
        }
        printf("\n");
        // cout<<dq.front().second<<" ";
    }
    printf("\n");
    return 0;
}
