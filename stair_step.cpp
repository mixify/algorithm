#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int cache[301];
int climb(vector<int> stair, int n, int adjacent_count);

int main(int argc, char *argv[])
{
    int stair_num;
    cin>>stair_num;
    vector<int> stair;
    for (int i = 0; i < stair_num; ++i) {
        int input;
        cin>>input;
        stair.push_back(input);
    }
    memset(cache, -1, sizeof(cache));
    climb(stair,stair.size()-1, 0);
    printf("%d\n", cache[stair.size()-1]);
    return 0;
}

int climb(vector<int> stair, int n, int adjacent_count)
{
    int &ret = cache[n];
    if(ret!=-1) return ret;

    int val = stair[n];
    if(n == 0)
        return ret = val;
    else if(n < 0)
        return -1;
    if(adjacent_count == 1)
        return climb(stair, n-2, 0);
    return ret = val + max(climb(stair, n-1, adjacent_count+1), climb(stair, n-2, 0));
}