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

using namespace std;
int N, W;
int cache[101][1001];

class stuff
{
public:
    string name;
    int size;
    int need;
    stuff(string n, int s, int ne)
    {
        name = n;
        size = s;
        need = ne;
    }
};

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

int pack(vector<stuff> &stuffs,int size, int num)
{
    if(num == N) return 0;
    int &ret = cache[num][size];
    if(ret!=-1) {
        // printf("cache[%d][%d] = %d\n", num,size,ret);
        return ret;
    }
    ret = pack(stuffs, size, num+1);

    if(size - stuffs[num].size >= 0)
        ret = max(ret, pack(stuffs,size-stuffs[num].size,num+1) + stuffs[num].need);
    return ret;

}

void tracking(vector<stuff> &stuffs,int size, int num, vector<string> &stuffs_name)
{
    if(num == N) return;
    if(pack(stuffs,size, num) == pack(stuffs,size, num+1))
        tracking(stuffs,size,num+1,stuffs_name);
    else
    {
        stuffs_name.push_back(stuffs[num].name);
        tracking(stuffs,size-stuffs[num].size,num+1,stuffs_name);
    }
}

void solve_problem(int case_num)
{
    cin>>N>>W;
    vector<stuff> stuffs;
    vector<string> stuffs_name;;
    for (int i = 0; i < N; ++i) {
        string name; int size; int ne; cin>>name>>size>>ne;
        stuffs.push_back(stuff(name,size,ne));
    }
    memset(cache, -1, sizeof(cache));
    cout<<pack(stuffs,W,0)<<" ";
    tracking(stuffs,W,0,stuffs_name);
    cout<<stuffs_name.size()<<endl;
    for (int i = 0; i < stuffs_name.size(); ++i) {
        cout<<stuffs_name[i]<<endl;
    }
}
