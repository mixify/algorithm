#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comprev(int a, int b)
{
    return b < a;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <pair<int, int> > q;
    int time = 0;
    vector<int> seosun = priorities;
    sort(seosun.begin(),seosun.end(),comprev);

    for(int i = 0 ; i < priorities.size() ; i++)
        q.push(make_pair(priorities[i], i));
    int i = 0;
    do
    {
        pair<int,int> pri = q.front();
        printf("%d %d\n", pri.first, pri.second);
        printf("%d\n", seosun[i]);
        if(pri.first >= seosun[i])
        {
            if(pri.second==location) return answer = time;
            q.pop();
            i++;
        }
        else
        {
            q.pop();
            q.push(pri);
        }
        time++;
    }while(!q.empty());
    return 0;
}

int main(int argc, char *argv[])
{
    int N,M;
    cin>>N>>M;
    vector<int> pri;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; pri.push_back(in);
    }
    solution(pri,M);
    return 0;
}
