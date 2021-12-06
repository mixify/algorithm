#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<pair<int,int> > pq;
    int cur = stock;
    int cnt = 0;
    for(int i = 0 ; i < dates.size() ; i++)
    {
        printf("%d\n", cur);
        if(cur - k >= 0)
            break;

        if(cur - dates[i] >= 0)
            pq.push(make_pair(supplies[i],i));
        else
        {
            cur = cur + pq.top().first;
            // printf("in %d %d\n", pq.top().first,dates[pq.top().second]);
            // k-=dates[pq.top().second];
            i = pq.top().second;
            pq = priority_queue <pair<int,int> >();
            cnt++;
        }
    }
    if(cur - k < 0)
        cnt++;
    return cnt;
}

int main(int argc, char *argv[])
{
    printf("%d\n",solution(4,vector<int>{4,10,15},vector<int>{20,5,10},30));
    return 0;
}
