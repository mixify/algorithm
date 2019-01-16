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

int N,M;
int cache[101][101];
vector<int> solve_by_lower_bound(vector<int> seq1, vector<int> seq2);
int solve(vector<int> &seq1,vector<int> &seq2, int idx1, int idx2, int last_elem);
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

void solve_problem(int case_num)
{
    cin>>N>>M;

    vector<int> seq1;
    vector<int> seq2;
    int num;
    for (int i = 0; i < N; ++i) {
        cin>>num;
        seq1.push_back(num);
    }
    for (int i = 0; i < M; ++i) {
        cin>>num;
        seq2.push_back(num);
    }

    int mx = 1;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; ++i) {
       for (int j = 0; j < M; ++j) {
           mx = max(solve(seq1,seq2,i,j,-1), mx);
       }
    }
    if(mx == 1)
        printf("1\n");
    else
        printf("%d\n", mx-1);
    // for (int i = 1; i < JLIS.size(); ++i) {
    //     printf("%d ", JLIS[i]);
    // }
    // printf("\n");
}
int solve(vector<int> &seq1,vector<int> &seq2, int idx1, int idx2, int last_elem)
{
    int &ret = cache[idx1][idx2];
    if(ret != -1)
        return ret;
    if(idx1 == N-1 && idx2 == M-1)
        return ret = 1;
    int mx = 1;
    for (int i = idx1; i < N; ++i)
    {
        if(seq1[i] > last_elem)
            mx = max(mx, solve(seq1,seq2,i,idx2, seq1[i])+1);
    }
    for (int j = idx2; j < M; ++j)
    {
        if(seq2[j] > last_elem)
            mx = max(mx, solve(seq1,seq2,idx1,j,seq2[j])+1);
    }
    return ret = mx;
}
// vector<int> solve_by_lower_bound(vector<int> seq1, vector<int> seq2)
// {
//     vector<int> JLIS;
//     JLIS.push_back(-1);
//
//     int i=0,j=0;
//     // while(i<N || j<M)
//     // {
//     //     if(j==M || seq1[i] < seq2[j] && i<N)
//     //     {
//     //         if(seq1[i] > JLIS.back())
//     //             JLIS.push_back(seq1[i]);
//     //         else
//     //         {
//     //             auto it = lower_bound(JLIS.begin(), JLIS.end(), seq1[i]);
//     //             *it = seq1[i];
//     //         }
//     //         i++;
//     //     }
//     //     else
//     //     {
//     //         if(seq2[j] > JLIS.back())
//     //             JLIS.push_back(seq2[j]);
//     //         else
//     //         {
//     //             auto it = lower_bound(JLIS.begin(), JLIS.end(), seq2[j]);
//     //             *it = seq2[j];
//     //         }
//     //         j++;
//     //     }
//     // }
//     // for (int i = 0; i < N; ++i)
//     // {
//     //     if(seq1[i] > JLIS.back())
//     //     {
//     //         JLIS.push_back(seq1[i]);
//     //     }
//     //     else
//     //     {
//     //         auto it = lower_bound(JLIS.begin(),JLIS.end(),seq1[i]);
//     //         *it = seq1[i];
//     //     }
//     // }
//     //
//     // for (int i = 0; i < M; ++i) {
//     //     if(seq2[i] > JLIS.back())
//     //     {
//     //         JLIS.push_back(seq2[i]);
//     //     }
//     //     else
//     //     {
//     //         auto it = lower_bound(JLIS.begin(),JLIS.end(),seq2[i]);
//     //         *it = seq2[i];
//     //     }
//     // }
//     return JLIS;
// }
