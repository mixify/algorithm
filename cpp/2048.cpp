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

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3
int board[21][21];
using namespace std;
int N, M;
int max_block = 0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};


void play_game(int cnt,int ori)
{

    // printf("-----------\n");
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }

    if(cnt==5) return;

    int tmp[21][21];
    memcpy(tmp,board,sizeof(board));
    vector<vector<int> > chained;


    // for (int i = 0; i < N; ++i) {
    //     horizontal.push_back(vector<int>());
    //     for (int j = 0; j < N; ++j) {
    //         if(board[i][j]!=0)
    //             horizontal[i].push_back(board[i][j]);
    //     }
    // }
    if(ori<=1)
        for (int i = 0; i < N; ++i) {
            chained.push_back(vector<int>());
            if(ori==0)
                for (int j = N-1; j >= 0; --j) {
                    if(board[j][i]!=0)
                        chained[i].push_back(board[j][i]);
                }
            else if(ori==1)
                for (int j = 0; j < N; ++j){
                    if(board[j][i]!=0)
                        chained[i].push_back(board[j][i]);
                }
        }
    else
    {
        for (int i = 0; i < N; ++i) {
            chained.push_back(vector<int>());
            if(ori==2)
                for (int j = N-1; j >= 0; --j) {
                    if(board[i][j]!=0)
                        chained[i].push_back(board[i][j]);
                }
            else if(ori==3)
                for (int j = 0; j < N; ++j){
                    if(board[i][j]!=0)
                        chained[i].push_back(board[i][j]);
                }
        }
    }
    auto itr = vector<int> ::iterator();
    switch (ori) {
        case 0:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < chained[i].size()-1; ++j) {
                    if(chained[i].size()==0) break;
                    if(chained[i][j] == chained[i][j+1])
                    {
                        chained[i][j]*=2;
                        max_block = max(chained[i][j],max_block);
                        chained[i][j+1]=0;
                    }
                }
                int cnt = N-1;
                for (itr = chained[i].begin(); itr != chained[i].end();) {
                    if(*itr == 0)
                        itr = chained[i].erase(itr);
                    else
                    {
                        board[cnt][i] = *itr;
                        itr++;
                        cnt--;
                    }
                }
                for (int j = cnt; j >= 0; --j) {
                    board[j][i] = 0;
                }
            }
            break;
        case 1:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < chained[i].size()-1; ++j) {
                    if(chained[i].size()==0) break;
                    if(chained[i][j] == chained[i][j+1])
                    {
                        chained[i][j]*=2;
                        max_block = max(chained[i][j],max_block);
                        chained[i][j+1]=0;
                    }
                }
                int cnt = 0;
                for (itr = chained[i].begin(); itr != chained[i].end();) {
                    if(*itr == 0)
                        itr = chained[i].erase(itr);
                    else
                    {
                        board[cnt][i] = *itr;
                        itr++;
                        cnt++;
                    }
                }
                for (int j = cnt; j < N; ++j) {
                    board[j][i] = 0;
                }
            }
            break;
        case 2:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < chained[i].size()-1; ++j) {
                    if(chained[i].size()==0) break;
                    if(chained[i][j] == chained[i][j+1])
                    {
                        chained[i][j]*=2;
                        max_block = max(chained[i][j],max_block);
                        chained[i][j+1]=0;
                    }
                }
                int cnt = N-1;
                for (itr = chained[i].begin(); itr != chained[i].end();) {
                    if(*itr == 0)
                        itr = chained[i].erase(itr);
                    else
                    {
                        board[i][cnt] = *itr;
                        itr++;
                        cnt--;
                    }
                }
                for (int j = cnt; j >= 0; --j) {
                    board[i][j] = 0;
                }
            }
            break;
        case 3:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < chained[i].size()-1; ++j) {
                    if(chained[i].size()==0) break;
                    if(chained[i][j] == chained[i][j+1])
                    {
                        chained[i][j]*=2;
                        max_block = max(chained[i][j],max_block);
                        chained[i][j+1]=0;
                    }
                }
                int cnt = 0;
                for (itr = chained[i].begin(); itr != chained[i].end();) {
                    if(*itr == 0)
                        itr = chained[i].erase(itr);
                    else
                    {
                        board[i][cnt] = *itr;
                        itr++;
                        cnt++;
                    }
                }
                for (int j = cnt; j < N; ++j) {
                    board[i][j] = 0;
                }
            }
            break;
        default:
            break;
    }

    for (int i = 0; i < 4; ++i)
    {
        // printf("-----------\n");
        play_game(cnt+1,i);
    }
    memcpy(board,tmp,sizeof(board));
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>board[i][j];
            max_block = max(max_block,board[i][j]);
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        play_game(0,i);
    }

    printf("%d\n", max_block);
    return 0;
}

