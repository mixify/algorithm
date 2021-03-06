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

int cache[302][2];
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
    // for (int i = stair_num-1; i >= 0; --i) {
    //     printf("%d = %d\n", i,climb(stair, i, 0));
    // }
    printf("%d\n", climb(stair, stair_num-1, 0));
    return 0;
}

int climb(vector<int> stair, int n, int jump_type)
{
    if(n < 0)
        return -1;
    // int ret;
    int &ret = cache[n][jump_type];
    if(ret!=-1)
        return ret;

    int val = stair[n];
    if(n == 0)
        return ret = val;
    if(jump_type == 1)
    {
        if(n==1)
            return ret = val;
        return ret = val + climb(stair, n-2, 0);
    }
    return ret = val + max(climb(stair, n-1, 1), climb(stair, n-2, 0));
}
