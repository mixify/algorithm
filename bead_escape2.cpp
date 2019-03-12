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

#define NOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define RED_FIRST 5
#define BLUE_FIRST 6
using namespace std;
int N, M;
vector<vector <char> > board;
int brute(int count, int direction, int Ry, int Rx, int By, int Bx)
{
    if(count>10) return 999999;
    bool success = false;
    int dy,dx;
    int original_Ry = Ry;
    int original_Rx = Rx;
    int original_By = By;
    int original_Bx = Bx;
    int orientation = BLUE_FIRST;
    int ret = 0;
    switch (direction) {
        case UP: dy=-1; dx=0; if(Ry < By) orientation=RED_FIRST;
            break;
        case DOWN: dy=1; dx=0; if(Ry > By) orientation=RED_FIRST;
            break;
        case LEFT: dy=0; dx=-1; if(Rx < Bx) orientation=RED_FIRST;
            break;
        case RIGHT: dy=0; dx=1; if(Rx > Bx) orientation=RED_FIRST;
            break;
        default:
            break;
    }//같은 행이나 열이 아니라도 상관없지않나??
    if(direction!=NOP)
    {
        if(orientation == RED_FIRST)
        {
            while(board[Ry+dy][Rx+dx] == '.') {board[Ry][Rx] = '.'; Ry+=dy; Rx+=dx;}
            board[Ry][Rx] = 'R';
            if(board[Ry+dy][Rx+dx] == 'O'){ success = true; board[Ry][Rx] = '.';}
            while(board[By+dy][Bx+dx] == '.') {board[By][Bx] = '.'; By+=dy; Bx+=dx;}
            if(board[By+dy][Bx+dx] == 'O') count = 999999;
            board[By][Bx] = 'B';
        }
        else
        {
            while(board[By+dy][Bx+dx] == '.') {board[By][Bx] = '.'; By+=dy; Bx+=dx;}
            if(board[By+dy][Bx+dx] == 'O') count = 999999;
            board[By][Bx] = 'B';
            while(board[Ry+dy][Rx+dx] == '.') {board[Ry][Rx] = '.'; Ry+=dy; Rx+=dx;}
            if(board[Ry+dy][Rx+dx] == 'O') success = true;
            board[Ry][Rx] = 'R';
        }
    }

    if(success || count==999999) ret = count;
    else
        ret = min(min(brute(count+1,UP,Ry,Rx,By,Bx),brute(count+1,DOWN,Ry,Rx,By,Bx))
                ,min(brute(count+1,LEFT,Ry,Rx,By,Bx),brute(count+1,RIGHT,Ry,Rx,By,Bx)));

    board[Ry][Rx] = '.';
    board[original_Ry][original_Rx] = 'R';
    board[By][Bx] = '.';
    board[original_By][original_Bx] = 'B';

    return ret;
}
int main(int argc, char *argv[])
{
    // vector<vector <char> > board;
    cin>>N>>M;
    int Rx,Ry;
    int Bx,By;
    for (int i = 0; i < N; ++i) {
        board.push_back(vector <char>());
        for (int j = 0; j < M; ++j) {
            char c; cin>>c; board[i].push_back(c);
            if(c=='R') {Ry = i; Rx = j;}
            if(c=='B') {By = i; Bx = j;}
        }
    }
    int p = brute(0,NOP,Ry,Rx,By,Bx);
    cout<<(p==999999?-1:p)<<endl;
    return 0;
}
