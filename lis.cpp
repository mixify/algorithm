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
int cache[51][51];

void solve_problem(int case_num);
int find_lis(vector<int> sequence, int idx);
bool is_increasing(vector<int> sequence)
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void solve_problem(int case_num)
{
    int n;
    vector<int> sequence;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int in; cin>>in;
        sequence.push_back(in);
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", find_lis(sequence, sequence.size()));
    // find_lis(sequence, 0);
}
// int brute(vector<int> sequence, int idx)
// {
//
// }
int find_lis(vector<int> sequence, int idx)
{

}
bool is_increasing(vector<int> sequence)
{
    if(sequence.size() == 1)
        return true;
    for (int i = 1, before= sequence[0]; i < sequence.size(); ++i)
    {
        if(before > sequence[i])
        {
            return false;
        }
    }
    return true;
}
