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
int cache[1001][1001];
int best[1001][1001][2];
int solve(string &seq1,string &seq2, int idx1, int idx2);
void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    solve_problem(0);
    return 0;
}

string str;
void tracking(string &seq1,string &seq2,int i, int j)
{
    if(cache[i][j] == 0) return;
    str.append(seq1,best[i][j][0],1);
    tracking(seq1,seq2,best[i][j][0]+1,best[i][j][1]+1);
}
void solve_problem(int case_num)
{
    string seq1;
    string seq2;
    // string str = "";
    cin>>seq1>>seq2;
    N = seq1.length();
    M = seq2.length();

    memset(cache, -1, sizeof(cache));
    memset(cache, -1, sizeof(cache));
    // mx = max(solve(seq1,seq2,0,0), mx);
    printf("%d\n", solve(seq1,seq2,0,0)/* -2 */);
    tracking(seq1,seq2,0,0);
    cout<<str<<endl;
    // for (int i = 1; i < JLIS.size(); ++i) {
    //     printf("%d ", JLIS[i]);
    // }
    // printf("\n");
}
int solve(string &seq1,string &seq2, int idx1, int idx2)
{
    int &ret = cache[idx1][idx2];
    if(ret != -1)
        return ret;

    // string a;
    int best_i = 0;
    int best_j = 0;

    ret = 0;
    int better;
    for (int i = idx1; i < N; ++i)
    {
        for (int j = idx2; j < M; ++j)
            if (seq1[i] == seq2[j])
            {
                // ret = max(ret, solve(seq1,seq2,i+1,j+1)+1);
                // break;
                if(ret < (better = solve(seq1,seq2,i+1,j+1)+1))
                {
                    ret = better;
                    best_i = i;
                    best_j = j;
                }
                    break;
            }
    }
    best[idx1][idx2][0] = best_i;
    best[idx1][idx2][1] = best_j;
    return ret;
}
