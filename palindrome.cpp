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
int cache[2501];// [2501];

bool is_symmetry(int i, int j)
{
    while(i<j)
    {
        if(str[i] != str[j])
            return false;
        i++; j--;
    }
    return true;
}
int palindrome(int idx,int length)
{
    int &ret = cache[idx];// [length];
    if(ret!=-1) return ret;
    if(idx==str.length()) return 1;

    ret = 0;

    for (int i = idx; i < str.length(); ++i) {
        if(is_symmetry(idx,i))
        {
            printf("from %d to %d\n", idx,i);
            cout<<str.substr(idx,i-idx+1)<<endl;
            ret += palindrome(idx+1,i-idx+1);
        }
    }
    printf("at %d ret = %d\n", idx, ret);
    return ret;
}
int main(int argc, char *argv[])
{
    cin>>str;
    memset(cache,-1,sizeof(cache));
    printf("%d\n", palindrome(0,0));
    return 0;
}
