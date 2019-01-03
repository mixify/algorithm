#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define BLACK 0;
#define WHITE 1;

#define NO_TURN 0;
#define ROTATE_1 1;
#define ROTATE_2 2;
#define ROTATE_3 3;
using namespace std;
int H, W;
int case_count;

const int dx[] = {0,1,1,0};
const int dy[] = {0,0,1,1};

void solve_problem(int case_num);
void recursive_rotate(char **board,int x, int y, int whitecount);
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
    char **board;
    case_count = 0;
    int whitecount = 0;
    cin>>H>>W;
    board = new char*[H];
    for (int i = 0; i < H; ++i) {
        board[i] = new char[W];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf(" %1c",&board[i][j]);
            if(board[i][j] == '.')
                whitecount++;
        }
    }

    if(whitecount%3)
    {
        cout<<0<<endl;
        return;
    }
    // for (int i = 0; i < H; ++i) {
    //     for (int j = 0; j < W; ++j) {
    //         printf("%c",board[i][j]);
    //     }
    //         printf("\n");
    // }

    //////////////////////////////////////////////////
    recursive_rotate(board, 0,0,whitecount);
    printf("%d\n", case_count);
    //////////////////////////////////////////////////
    for (int i = 0; i < H; ++i) {
        delete [] board[i];
    }
    delete [] board;
}

bool is_valid(char **board,int x,int y)
{
    // for (int i = 0; i < 4; ++i) {
    //
    // }
    if(x>=W || y>=H)
        return false;
    else if(x<0 || y<0)
        return false;
    // else if(x<0 || y<0)
    //     return false;
    else if(board[y][x] == '#')
        return false;
    else
        return true;
}

bool place(char **board, int x, int y, int degree)
{
    for (int i = 0; i < 4; ++i) {
        if(i == degree)
            continue;
        if(!is_valid(board, x+dx[i], y+dy[i]))
            return false;
    }
    for (int i = 0; i < 4; ++i) {
        if(i == degree)
            continue;
        board[y+dy[i]][x+dx[i]] = '#';
    }
    return true;
}
void recursive_rotate(char **board,int x, int y, int whitecount)
{
    if(whitecount==0)
    {
        case_count++;
        return;
    }
    if(x == W-1 && y == H-1)
        return;
    for (int i = 0; i < 4; ++i) {
        char **update_board;
        update_board = new char*[H];
        for (int i = 0; i < H; ++i)
            update_board[i] = new char[W];
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                update_board[i][j] = board[i][j];
            }
        }
        if(place(update_board, x, y, i))
        {
            // cout<<"updated board"<<endl;
            // for (int i = 0; i < H; ++i) {
            //     for (int j = 0; j < W; ++j) {
            //         printf("%c",update_board[i][j]);
            //     }
            //     printf("\n");
            // }
            if(x==W-1)
                recursive_rotate(update_board,0,y+1,whitecount-3);
            else
                recursive_rotate(update_board,x+1,y,whitecount-3);
        }
        for (int i = 0; i < H; ++i) {
            delete [] update_board[i];
        }
        delete [] update_board;
    }
    if(is_valid(board,x-1,y) || is_valid(board,x,y-1))
        return;
    if(x==W-1)
        recursive_rotate(board,0,y+1,whitecount);
    else
        recursive_rotate(board,x+1,y,whitecount);
}
