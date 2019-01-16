#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

#define sq(x) (x)*(x)
using namespace std;
int N, S;
int cache[101][11];

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

int group_value(vector <int> group)
{
    int sum = 0;
    for (int i = 0; i < group.size(); ++i) {
        // printf("%d\n", group[i]);
        sum+=group[i];
    }
    int size = group.size();
    // int avg;
    // if (size % 2 == 0)
    // {
    //     avg = (group[size / 2 - 1] + group[size / 2]) / 2;
    // }
    // else
    // {
    //     avg = group[size / 2];
    // }
    int avg = sum/group.size();

    // printf("avg = %d\n", avg);
    int val = 100000000;
    for (int i = avg-11; i < avg+11; ++i) {
        sum = 0;
        for (int j = 0; j < group.size(); ++j) {
            sum += sq(i-group[j]);
        }
        val = min(sum,val);
    }
    // printf("rss = %d\n", sum);
    return val;
}
int quantize(vector <int> &sequence, int pos, int groups)
{
    int &ret = cache[pos][groups];
    if(ret!=-1) return ret;
    //lets divide seqence S groups
    ret = 100000000;
    if(groups == S)
    {
        if(pos < N)
            return ret = 200000000;
        else
            return ret = 0;
    }
    vector<int> group;
    vector<int> best_group;
    for (int i = pos; i < N; ++i) {
        group.push_back(sequence[i]);
        {
            if(ret > quantize(sequence, i+1,groups+1)+group_value(group))
            {
                // printf("%d, %d\n", i,groups);
                // printf("%d + %d\n",quantize(sequence, i+1,groups+1),group_value(group) );
                ret = quantize(sequence, i+1,groups+1)+group_value(group);
                best_group = group;
            }
            // ret = min(quantize(sequence, i+1,groups+1)+group_value(group), ret);
        }
    }
    // printf("at pos = %d, groups = %d best = %d\n", pos, groups, ret);
    // for (int i = 0; i < best_group.size(); ++i) {
    //     printf("%d ", best_group[i]);
    // }
    // printf("\n");
    return ret;
}
void solve_problem(int case_num)
{
    cin>>N>>S;
    vector <int> v;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; v.push_back(in);
    }
    if(N<=S)
    {
        printf("0\n");
        return;
    }
    sort(v.begin(),v.end());
    memset(cache, -1, sizeof(cache));
    // for (int i = 0; i < N; ++i) {
    //     printf("%d ", v[i]);
    // }
    printf("%d\n", quantize(v, 0,0));
}

