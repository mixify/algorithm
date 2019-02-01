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
pair<int,string> cache[1001][1001];
pair<int,string> solve(string &seq1,string &seq2, int idx1, int idx2, string &lcs);
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

    // memset(cache, 0, sizeof(cache));
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            cache[i][j].first = 0;
        }
    }
    // mx = max(solve(seq1,seq2,0,0), mx);
    // printf("%d\n", solve(seq1,seq2,0,0,lcs).first/* -2 */);
    solve(seq1,seq2,0,0,lcs);
    cout<<cache[0][0].first<<endl<<cache[0][0].second<<endl;
    // cout<<max_string<<endl;
    // for (int i = 1; i < JLIS.size(); ++i) {
    //     printf("%d ", JLIS[i]);
    // }
    // printf("\n");
}
pair<int,string> solve(string &seq1,string &seq2, int idx1, int idx2, string &lcs)
{
    pair<int,string> &ret = cache[idx1][idx2];
    if(ret.first != 0 && lcs.length()<ret.second.length())
        return ret;

    ret.first = 0;
    ret.second = lcs;

    for (int i = idx1; i < N; ++i)
    {
        for (int j = idx2; j < M; ++j)
            if (seq1[i] == seq2[j])
            {
                lcs+=seq1[i];
                // cout<<lcs<<endl;
                // ret.second+=seq1[i];
                pair<int,string> res = solve(seq1,seq2,i+1,j+1,lcs);
                if(ret.first < res.first+1)
                {
                    ret.first=res.first+1;
                    ret.second=res.second;//  + res.second;
                    // std::cout << idx1 <<" "<< idx2 << std::endl;
                    // std::cout << "lcs2 : "<< ret.second << std::endl;
                }
                // ret.first = max(ret.first, solve(seq1,seq2,i+1,j+1,lcs)+1);
                // ret.second +=
                // if(lcs.length()>=max_string.length())
                //     max_string = lcs;
                // ret.second
                // ret.second.pop_back();
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
