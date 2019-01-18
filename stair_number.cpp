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
int N;

long long cache[102][101];

long long stair_num(vector<int> v, int size)
{
    long long &ret = cache[size][v.size()];
    if(ret!=-1) return ret;

    if(size==N)
        return v.size();
    vector<int> v_up = v;
    vector<int> v_down = v;

    for (int i = 0; i < v.size(); ++i) {
        if(v[i] < 9)
            v_up[i] = v[i] +1;
        else
            v_up.pop_back();
    }
    for (int i = v.size()-1 ; i >= 0; --i) {
        if(v[i] > 0)
            v_down[i] = v[i] -1;
        else
            v_down.erase(v_down.begin());
    }
    ret = stair_num(v_up,size+1) + stair_num(v_down,size+1);
    ret %= 1000000000;
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N;
    vector<int> v;
    for (int i = 1; i <= 9; ++i)
        v.push_back(i);

    memset(cache, -1, sizeof(cache));
    printf("%lld\n", stair_num(v,1));
}
