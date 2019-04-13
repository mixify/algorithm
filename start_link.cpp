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
int N;
int stat[21][21];

vector <vector<int> > combination(int n, int r)
{
    vector <vector<int> > comb;
    vector <int> num;
    for (int i = 0; i < n; ++i) {
        num.push_back(i);
    }
    vector<int> ind;

    for (int i = 0; i < r; ++i) {
        ind.push_back(1);
    }
    for (int i = 0; i < n-r; ++i) {
        ind.push_back(0);
    }

    sort(ind.begin(),ind.end());

    do{
        vector<int> one_comb;
        for (int i = 0; i < ind.size(); ++i) {
            if(ind[i] == 1)
                one_comb.push_back(num[i]);
        }
        comb.push_back(one_comb);
    }while(next_permutation(ind.begin(),ind.end()));

    return comb;
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>stat[i][j];
        }
    }
    int min_diff = 99999999;
    vector <vector<int> > comb = combination(N,N/2);
    int sum1, sum2;
    for (int i = 0; i < comb.size()/* /2 */; ++i) {
        sum1=0;
        sum2=0;
        for (int j = 0; j < comb[i].size()-1; ++j) {
            for (int k = j+1; k < comb[i].size(); ++k) {
                // printf("%d ", stat[comb[i][j]][comb[i][k]]);
                sum1+=stat[comb[i][j]][comb[i][k]];
                sum1+=stat[comb[i][k]][comb[i][j]];
            }
            // printf("\n");
            // printf("%d ",comb[i][j]);
        }
        // printf("vs ");
        for (int j = 0; j < comb[i].size(); ++j) {
            for (int k = j+1; k < comb[i].size(); ++k) {
                sum2+=stat[comb[comb.size()-i-1][j]][comb[comb.size()-i-1][k]];
                sum2+=stat[comb[comb.size()-i-1][k]][comb[comb.size()-i-1][j]];
            }
            // printf("%d ",comb[comb.size()-i-1][j]);
        }
        // printf("%d %d\n", sum1,sum2);
        min_diff = min(min_diff,abs(sum1-sum2));
        // printf("\n");
    }
    printf("%d\n", min_diff);

    return 0;
}
