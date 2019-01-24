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
string max_string;
int solve(string &seq1,string &seq2, int idx1, int idx2, string &lcs);
void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    int cases;
    solve_problem(0);
    return 0;
}

void solve_problem(int case_num)
{
    string seq1;
    string seq2;
    string lcs;
    cin>>seq1>>seq2;
    N = seq1.length();
    M = seq2.length();

    memset(cache, -1, sizeof(cache));
    // mx = max(solve(seq1,seq2,0,0), mx);
    printf("%d\n", solve(seq1,seq2,0,0,lcs)/* -2 */);
    cout<<max_string<<endl;
    // for (int i = 1; i < JLIS.size(); ++i) {
    //     printf("%d ", JLIS[i]);
    // }
    // printf("\n");
}
int solve(string &seq1,string &seq2, int idx1, int idx2, string &lcs)
{
    int &ret = cache[idx1][idx2];
    if(ret != -1)
        return ret;

    ret = 0;
    for (int i = idx1; i < N; ++i)
    {
        for (int j = idx2; j < M; ++j)
            if (seq1[i] == seq2[j])
            {
                lcs+=seq1[i];
                // cout<<lcs<<endl;
                ret = max(ret, solve(seq1,seq2,i+1,j+1,lcs)+1);
                if(lcs.length()>=max_string.length())
                {
                    max_string = lcs;
                }
                lcs.pop_back();
                break;
            }
    }
    // ret = max(ret, solve(seq1,seq2,i,idx2,seq1[i])+1);
    // bool first = false;
    // if(last_elem == 0)
    //     first = true;
    // ret = 2;
    // long long a = (idx1==-1 ? NEGINF : seq1[idx1]);
    // long long b = (idx2==-1 ? NEGINF : seq2[idx2]);
    // long long last_elem = max(a,b);
    // printf("%lld\n", last_elem);
    return ret;
}
