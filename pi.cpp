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

int cache[10001];
void solve_problem(int case_num);
int min_score(string &pi, int pos);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i)
        solve_problem(i);
    return 0;
}

void solve_problem(int case_num)
{
    string pi;
    cin>>pi;
    memset(cache, -1, sizeof(cache));
    printf("%d\n", min_score(pi, 0));
}

int check_score(vector <int> segment)
{
    if(segment.size() < 3)
        return 1000000;
    bool legit = true;
    int pre = segment[0];
    for (int i = 1; i < segment.size(); ++i) {
        if(segment[i] != pre)
            legit = false;
        pre=segment[i];
    }
    if(legit)
        return 1;
    legit = true;

    pre = segment[0];
    int diff = segment[1] - segment[0];
    for (int i = 1; i < segment.size(); ++i) {
        if(pre + diff*i != segment[i])
            legit = false;
    }
    if(legit)
    {
        if(abs(diff) == 1)
            return 2;
        return 5;
    }
    legit = true;
    for (int i = 2; i < segment.size(); ++i) {
        if(segment[i-2] != segment[i])
            legit = false;
    }
    if(legit)
        return 4;

    return 10;
}
int min_score(string &pi, int pos)
{
    int &ret = cache[pos];
    vector<int> v;
    if(ret != -1) return ret;
    if(pos >= pi.length())
        return 0;
    ret = 10000;
    for (int i = pos; i < pi.length(); ++i) {
        v.push_back(pi[i]);
        if(v.size()>=3 && v.size()<=5)
            ret = min(min_score(pi,i+1) + check_score(v), ret);
    }
    return ret;
}

