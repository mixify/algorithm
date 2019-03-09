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
int N, M;
vector<int> house;

int min = 0;

int parametic(int left, int right, int cnt)
{
    int ret = 0;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int start = house[0];
        cnt = 1;
        for (int i = 1; i < N; ++i) {
            if(house[i]-start >= mid)
            {
                cnt++;
                start = house[i];
            }
        }

        if(cnt>=M)
        {
            ret = mid;
            left = mid + 1;
        }
        else right = mid -1;
    }
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; house.push_back(in);
    }

    sort(house.begin(),house.end());
    cout<<parametic(1,house[N-1] - house[0], 1)<<endl;
    return 0;
}
