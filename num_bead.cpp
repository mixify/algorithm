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
int max_min = 0;
int max_value = 0;
vector<int> bead;

void parametric()
{
    int left = max_min;
    int right = max_value;
    int ret = 0;
    vector<int> ret_vectors;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int start = bead[0];
        int sum = start;
        int cnt = 1;
        int bead_cnt = 1;
        vector<int> division;
        for (int i = 1; i < N; ++i) {
            sum+=bead[i];
            if(sum > mid)
            {
                division.push_back(bead_cnt);
                cnt++;
                bead_cnt=1;
                start = bead[i];
                sum = start;
            }
            else
                bead_cnt++;
        }
        division.push_back(bead_cnt);
        //cnt초과 => 너무많이 해당됨 == 값을 키워야 함
        if(cnt>M) left = mid + 1;//딱맞을때 어떻게 해야할까
        else
        {
            ret = mid;
            ret_vectors = division;
            right = mid -1;
        }//cnt 부족=> 값을 줄여서 하자

    }
    for (int i = 0; i < ret_vectors.size(); ++i) {
        printf("%d ", ret_vectors[i]);
    }
    printf("\n%d\n",ret);

}
int main(int argc, char *argv[])
{
    cin>>N>>M;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; bead.push_back(in);
        if(in > max_min) max_min = in;
        max_value+=in;
    }
    if(N==M)
    {
        for (int i = 0; i < N; ++i) {
            printf("1 ");
        }
        printf("\n%d\n", max_min);
        return 0;
    }
    parametric();
    return 0;
}
