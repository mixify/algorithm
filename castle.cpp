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
int N, K;
string words[51];
set<char> cand;

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
    cin>>N>>K;
    K-=5;//remove antic
    for (int i = 0; i < N; ++i) {
        string word;
        cin>>word;
        string substr = word.substr(4,word.length()-8);
        substr.erase(remove(substr.begin(),substr.end(),'a'), substr.end());
        substr.erase(remove(substr.begin(),substr.end(),'n'), substr.end());
        substr.erase(remove(substr.begin(),substr.end(),'t'), substr.end());
        substr.erase(remove(substr.begin(),substr.end(),'i'), substr.end());
        substr.erase(remove(substr.begin(),substr.end(),'c'), substr.end());
        words[i] = substr;
        // cin>>words[i];
    }

    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        vector<char> tmp;
        for (char c = 'a'; c <= 'z'; ++c) {
            if(words[i].find(c) != string::npos)
            {
                tmp.push_back(c);
                cnt++;
            }
        }
        if(cnt<=K)
        {
            for (int k = 0; k < tmp.size(); ++k)
            {
                cand.insert(tmp[k]);
            }
        }
    }

    auto itr = set<char>::iterator();
    vector<char> candidates;
    for(itr = cand.begin() ; itr != cand.end() ; itr++)
        candidates.push_back(*itr);

    vector <vector<int> > comb = combination(candidates.size(),K);

    int res = 0;
    for (int i = 0; i < comb.size(); ++i) {
        vector<char> selected_char;
        int cnt = 0;
        // string copied_words[51];
        // memcpy(copied_words,words,sizeof(words));
        for (int j = 0; j < comb[i].size(); ++j) {
            selected_char.push_back(candidates[comb[i][j]]);
            // cout<<candidates[comb[i][j]]<<' ';
        }
        for (int j = 0; j < N; ++j)
        {
            string str = words[j];
            for (int k = 0; k < selected_char.size(); ++k) {
                str.erase(remove(str.begin(),
                            str.end(),selected_char[k]), str.end());
            }
            if(str.length()==0) cnt++;
        }
        res = max(res,cnt);
        // printf("\n");
    }

    printf("%d\n", res);
    return 0;
}
