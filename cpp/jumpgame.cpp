#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>

#define DOWN 0
#define RIGHT 1

using namespace std;


int cache[100][100][2];
int board_size;
bool possible;
void solve_problem(int case_num);
int jump_board(pair<int,int> location, vector<vector <int> > board);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i)
        solve_problem(i);
    return 0;
}

void solve_problem(int case_num)
{
    possible = false;
    cin>>board_size;
    memset(cache,-1,sizeof(cache));
    vector<vector <int> > board;
    for (int i = 0; i < board_size; ++i) {
        vector<int> v;
        board.push_back(v);
        for (int j = 0; j < board_size; ++j) {
            int n;
            scanf(" %1d",&n);
            board[i].push_back(n);
        }
    }
    jump_board(make_pair(0,0),board);
    if(possible)
        printf("YES\n");
    else
        printf("NO\n");
}
int jump_board(pair<int,int> location, vector<vector <int> > board)
{
    int x = location.first;
    int y = location.second;
    if(x >= board_size || y >= board_size)
    {
        return -100;
    }
    if(board[x][y] == 0)
    {
        possible = true;
        return 0;
    }
    int step = board[x][y];
    int &down = cache[x][y][DOWN];
    if(down==-1)
        cache[x][y][DOWN] = jump_board(make_pair(x+step,y),board);
    int &right = cache[x][y][RIGHT];
    if(right==-1)
        cache[x][y][RIGHT] = jump_board(make_pair(x,y+step),board);
    return step;
}
