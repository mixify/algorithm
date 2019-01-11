#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

char cache[100];
void solve_problem(int case_num);
int valid(string wildcard, string filename, int pos_wildcard, int pos_filename);
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
    string wildcard;
    cin>>wildcard;
    int num_files;
    vector<string> filename;
    cin>>num_files;
    for (int i = 0; i < num_files; ++i) {
        string str;
        cin>>str;
        filename.push_back(str);
    }

    for (int i = 0; i < num_files; ++i) {
        memset(cache,-1,sizeof(cache));
        if(valid(wildcard,filename[i],0,0))
            cout<<filename[i]<<endl;
    }
}
int valid(string wildcard, string filename, int pos_wildcard, int pos_filename)
{
    int offset = 0;
    int v;
    if(pos_wildcard == wildcard.length())
    {
        if(pos_filename < filename.length())
            return 0;
        return 1;
    }
    // if()
    //     return 0;


    offset = pos_filename+1;
    if(wildcard[pos_wildcard] == '?' )
    {
        if(pos_filename >= filename.length())
            v = 0;
        else
            v = 1;
    }
    else if(wildcard[pos_wildcard] == '*')
    {
        v = 1;
        if(pos_wildcard + 1 == wildcard.length())
            return 1;
        offset = filename.find(wildcard[pos_wildcard+1],pos_filename);
        if(offset == string::npos)
            v = 0;
    }
    else
        v = (filename[pos_filename] == wildcard[pos_wildcard]);
    return v && valid(wildcard,filename,pos_wildcard + 1, offset);
}
