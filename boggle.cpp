#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>

#define X 0
#define Y 1
#define NUM_DIRECTIONS 8
int board[5][5];
int cache[5][5][10];

using namespace std;

const int adjacent_num[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
void solve_problem(int case_num);
bool has_word(int x,int y,string word, int count);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i <cases; ++i) {
        solve_problem(i);
    }
    return 0;
}
void solve_problem(int case_num)
{
    int word_count;
    bool found;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf(" %1c",&board[i][j]);
        }
    }
    scanf("%d", &word_count);
    vector<string> word;
    getchar();
    for (int i = 0; i < word_count; ++i) {
        memset(cache, -1, sizeof(cache));
        string str;
        cin>>str;
        cout<<str<<" ";
        bool exist = false;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if(has_word(j,k,str,0))
                {
                    exist=true;
                    printf("YES\n");
                    goto exist;
                }
            }
        }
        printf("NO\n");
exist:
        ;
    }
}
bool in_of_boundary(int x,int y)
{
    if(x<0 || y<0)
        return false;
    else if(x>4 || y>4)
        return false;
    return true;
}
bool has_word(int x, int y, string word, int count)
{
    int &ret = cache[x][y][count];
    if(ret!=-1) return ret;
    if(count == word.length()-1)
        if(word[count] == board[x][y])
            return true;
    if(board[x][y] != word[count])
        return 0;
    for (int i = 0; i < 8; ++i) {
        if(in_of_boundary(x+adjacent_num[i][X],y+adjacent_num[i][Y]))
            if(has_word(x+adjacent_num[i][X], y+adjacent_num[i][Y], word, count+1))
                return ret = 1;
    }
    return 0;
}
