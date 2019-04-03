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
// int cache[2501][2501];// [2501];
int cache[2501];/* [2501] */;// [2501];
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
// int palindrome(int idx,int count)
// {
//     int &ret = cache[idx][count];// [length];
//     if(ret!=-1) return ret;
//     if(idx==str.length()) {
//         if(count<m) m = count;
//         return ret = 1;
//     }
//
//     ret = 0;
//
//     for (int i = str.length()-1; i >= idx; --i) {
//         // if()
//         if(is_symmetry(idx,i))
//         {
//             // printf("from %d to %d\n", idx,i);
//             // cout<<str.substr(idx,i-idx+1)<<endl;
//             //how to ignore useless duplicates??
//             // int bef = ret;
//             ret += palindrome(i+1,count+1);
//             // break;
//         }
//     }
//     // printf("at %d ret = %d\n", idx, ret);
//     return ret;
// }
int palindrome(int y)
{
    int &ret = cache[y];
    if(y==0) return 1;
    if(ret!=-1) return ret;
    // if(idx==str.length()) {
    //     if(count<m) m = count;
    //     return ret = 1;
    // }

    ret = 2500;

    for (int i = 0; i <= y; ++i) {
        if(is_symmetry(i,y))
        {
            // cout<<str.substr(i,y-i+1)<<endl;
            // printf("%d %d\n", i,y);
            if(i==0) return 1;
            ret = min(ret,palindrome(i-1)+1);
        }
    }
    // printf("at %d ret = %d\n", idx, ret);
    return ret;
}
// int total_cost3(int y)
// {
//     int &ret = cache2[y];
//     if(y == 0) return ret = min(summation[y][y],summation_heli[y][y]);
//     if(ret!=-1) return ret;
//
//     ret = min(summation[0][y], summation_heli[0][y]);
//     for (int x = 0; x < y; ++x) {
//         ret = min(ret, total_cost3(x) +  summation_heli[x+1][y]);
//     }
//     return ret;
// }
int main(int argc, char *argv[])
{
    cin>>str;
    memset(cache,-1,sizeof(cache));
    memset(sym_cache,-1,sizeof(sym_cache));
    // if(str.length()==0) return 1;
    // palindrome(str.length());
    // if(is_symmetry(0,str.length()-1))
    //     printf("1\n");
    // else
    printf("%d\n", palindrome(str.length()-1));
    // printf("%d\n", m);
    return 0;
}
