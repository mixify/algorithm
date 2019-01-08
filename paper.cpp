#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void cut_paper(int x, int y, int size, vector<vector <int> > paper);
int minus_count;
int zero_count;
int plus_count;
int main(int argc, char *argv[])
{
    int N;
    vector<vector <int> > paper;
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
    cut_paper(0,0, N,paper);
}

void cut_paper(int x, int y, int size, vector<vector <int> > paper)
{
    int init = paper[x][y];
    bool same = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(init!=paper[i][j])//divide by 9
            {
                same = false;
            }
        }
    }
    if(same)
    {
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
                cut_paper(x+size*i,y+size*j,size,paper);
            }
        }
    }
}
