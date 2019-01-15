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
int cache[501];

void solve_problem(int case_num);
int find_lis(vector<int> &sequence, int size);
bool is_increasing(vector<int> sequence);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}
int brute(vector<int> &sequence, int idx);

void solve_problem(int case_num)
{
    int n;
    vector<int> sequence;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int in; cin>>in;
        sequence.push_back(in);
    }
    int mx=0;
    for (int i = 0; i < n; ++i)
    {
        memset(cache, -1 , sizeof(cache));
        mx = max(mx,brute(sequence, i));
    }
    printf("%d\n", mx);
    // find_lis(sequence, 0);
}
int brute(vector<int> &sequence, int idx)
{
    int &ret = cache[idx];
    if(ret != -1)
        return ret;
    if(idx == sequence.size()-1)
        return ret = 1;
    int mx = 1;
    for (int i = idx+1; i < sequence.size(); ++i)
    {
        if(sequence[i] > sequence[idx])
            mx = max(brute(sequence,i)+1, mx);
    }
    return ret = mx;
}
// int find_lis(vector<int> &sequence, int size)
// {
//
// }
// bool is_increasing(vector<int> sequence)
// {
//     if(sequence.size() == 1)
//         return true;
//     for (int i = 1, before= sequence[0]; i < sequence.size(); ++i)
//     {
//         if(before > sequence[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }
