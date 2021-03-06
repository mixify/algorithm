#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
vector<vector <int> > paper;
void cut_paper(int x, int y, int size);
int minus_count;
int zero_count;
int plus_count;
int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);
    minus_count = 0;
    zero_count = 0;
    plus_count = 0;
    for (int i = 0; i < N; ++i) {
        vector <int> v;
        paper.push_back(v);
        for (int j = 0; j < N; ++j) {
            int num;
            scanf("%d", &num);
            paper[i].push_back(num);
        }
    }
    cut_paper(0,0,N);
    printf("%d\n%d\n%d\n",minus_count, zero_count, plus_count);
}

void cut_paper(int x, int y, int size)
{
    bool same = true;
    for (int i = x; i < x+size; ++i) {
        for (int j = y; j < y+size; ++j) {
            if(paper[x][y]!=paper[i][j])//divide by 9
            {
                same = false;
                i =9999999;
                    break;
            }
        }
    }
    if(same)
    {
        int init = paper[x][y];
        if(init == -1)
            minus_count++;
        else if(init == 0)
            zero_count++;
        else
            plus_count++;
        return;
    }
    else
    {
        size/=3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cut_paper(x+size*i,y+size*j,size);
            }
        }
    }
}
