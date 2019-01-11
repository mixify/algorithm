#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int cache[101][101];
void solve_problem(int case_num);
// int valid(string wildcard, string filename, int pos_wildcard, int pos_filename);
int valid(string wildcard, string filename, int pos_wildcard, int pos_filename, int star_count);
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

    vector<string> valid_filename;
    for (int i = 0; i < num_files; ++i) {
        memset(cache,-1,sizeof(cache));
        if(valid(wildcard,filename[i],0,0,0))
            valid_filename.push_back(filename[i]);
    }
    sort(valid_filename.begin(), valid_filename.end());
    for (int i = 0; i < valid_filename.size(); ++i) {
        cout<<valid_filename[i]<<endl;
        if(i==valid_filename.size()-1)
        cout<<valid_filename[i];
    }
}

int valid(string wildcard, string filename, int pos_wildcard, int pos_filename, int star_count)
{
    int &ret = cache[pos_wildcard][pos_filename];
    if(ret!=-1)
        return ret;
    // if(pos_wildcard==-1)
    //     return 1;
    // else if(pos_wildcard == wildcard.length())
    //     return 1;
    while(pos_wildcard < wildcard.length() && pos_filename < filename.length() && (wildcard[pos_wildcard] == '?' || wildcard[pos_wildcard] == filename[pos_filename]))
    {
        pos_wildcard++;
        pos_filename++;
    }
    if(pos_wildcard == wildcard.length())
        return pos_filename == filename.length();
    // else if(pos_filename == filename.length())
    // {
    //     for (int i = pos_wildcard; i < wildcard.length(); ++i) {
    //         if(wildcard[i] != '*')
    //             return 0;
    //     }
    //     return 1;
    // }
    // if(pos_wildcard == wildcard.length())
    //     return pos_filename == filename.length();
    if(wildcard[pos_wildcard] == '*')
    {
        for (int i = 0; i+pos_filename <= filename.length(); ++i) {
            if(valid(wildcard,filename,pos_wildcard+1,pos_filename+i,star_count+1))
                return ret = 1;
        }
    }
    else
        return ret = 0;
}
// int valid(string wildcard, string filename, int pos_wildcard, int pos_filename) brute force...
// {
//     int offset = 0;
//     int v;
//     if(pos_wildcard == wildcard.length())
//     {
//         if(pos_filename < filename.length())
//             return 0;
//         return 1;
//     }
//     // if()
//     //     return 0;
//
//
//     offset = pos_filename+1;
//     if(wildcard[pos_wildcard] == '?' )
//     {
//         if(pos_filename >= filename.length())
//             v = 0;
//         else
//             v = 1;
//     }
//     else if(wildcard[pos_wildcard] == '*')
//     {
//         if(pos_wildcard + 1 == wildcard.length())
//             return 1;
//         else if(wildcard[pos_wildcard+1] == '?')
//         {
//             if(pos_filename < filename.length())
//                 v = 1;
//             // else
//             v = 1;
//             offset = pos_filename;
//             // pos_wildcard++;
//         }
//         else
//         {
//             offset = filename.find(wildcard[pos_wildcard+1],pos_filename);
//             if(offset == string::npos)
//                 v = 0;
//         }
//     }
//     else
//         v = (filename[pos_filename] == wildcard[pos_wildcard]);
//     return v && valid(wildcard,filename,pos_wildcard + 1, offset);
// }
