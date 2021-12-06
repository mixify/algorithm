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
int N, M;
vector<string> cache[4][4][8];
char panel[4][4];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
set<string> strs;
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

int traveling(int x, int y, int length, string str)
{
    if(x<0 || x>=4 || y<0 || y>=4) return 0;
    // string &ret = cache[x][y][length];
    // if(ret!=-1) return ret;
    if(length==7) {
        strs.insert(str);
        //set은 insert를 사용한다!!!!
        return 0 ;
    }

    // printf("str appending = %d\n", str.length());
    str.append(1,panel[x][y]+'0'); // string에 char 한글짜식 추가하는 방법임!
    // cout<<str<<endl;

    for (int i = 0; i < 4; ++i)
    {
        traveling(x+dx[i],y+dy[i],length+1, str);
    }
}

void solve_problem(int case_num)
{
    memset(cache,0,sizeof(cache));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin>>panel[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            traveling(i,j,0,string());
        }
    }
    printf("#%d %d\n", case_num+1, strs.size());
    strs.clear();
}
