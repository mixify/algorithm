#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;
string no_hole = "CEFGHIJKLMNSTUVWXYZ";
string one_hole = "ADOPQR";
string two_hole = "B";
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
    bool same = true;
    string str1,str2;
    cin>>str1>>str2;

    for (int i = 0; i < str1.size(); ++i) {
        if(str1.size() != str2.size())
        { same = false; break; }
        if(no_hole.find(str1[i])!=-1)
        {

            if(no_hole.find(str2[i])==-1)
            { same = false; break; }
        }
        else if(one_hole.find(str1[i])!=-1)
        {

            if(one_hole.find(str2[i])==-1)
            { same = false; break; }
        }
        else
        {
            if(str1[i]!=str2[i])
            { same = false; break; }
        }

    }
    printf("#%d ", case_num+1);
    if(same)
        printf("SAME\n");
    else
        printf("DIFF\n");
}
