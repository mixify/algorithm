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
string str;
int cache[2501][2501];// [2501];
int sym_cache[2501][2501];// [2501];

bool is_symmetry(int i, int j)
{
    int &ret = sym_cache[i][j];
    if(ret!=-1) return ret;
    while(i<j)
    {
        if(str[i] != str[j])
            return ret = 0;
        i++; j--;
    }
    return ret = 1;
}
int m = 2500;
int palindrome(int idx,int count)
{
    int &ret = cache[idx][count];// [length];
    if(ret!=-1) return ret;
    if(idx==str.length()) {
        if(count<m) m = count;
        return 1;
    }

    ret = 0;

    for (int i = str.length()-1; i >= idx; --i) {
        // if()
        if(is_symmetry(idx,i))
        {
            // printf("from %d to %d\n", idx,i);
            // cout<<str.substr(idx,i-idx+1)<<endl;
            //how to ignore useless duplicates??
            int bef = ret;
            ret += palindrome(i+1,count+1);
            // break;
        }
    }
    // printf("at %d ret = %d\n", idx, ret);
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>str;
    memset(cache,-1,sizeof(cache));
    memset(sym_cache,-1,sizeof(sym_cache));
    palindrome(0,0);
    // printf("%d\n", palindrome(0,0));
    printf("%d\n", m);
    return 0;
}
