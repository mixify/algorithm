#include <stdio.h>
#include <iostream>

#define X 0
#define Y 1
#define NUM_DIRECTIONS 8
int board[5][5];
using namespace std;

const int adjacent_num[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
void solve_problem(int case_num);
bool has_word(int x,int y,string word, int count);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    cout<<cases<<endl;
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
    cin>>word_count;
    string word[word_count];
    getchar();
    for (int i = 0; i < word_count; ++i) {
        getline(cin,word[i]);
    }
    for (int i = 0; i < word_count; ++i) {
        found = false;
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 5; ++y) {
                if(has_word(x,y,word[i], 0))
                {
                    cout<<word[i]<<" "<<"YES"<<endl;
                    x = 1818;
                    y = 1818;
                    found=true;
                }
            }
        }
        if(!found)
            cout<<word[i]<<" "<<"NO"<<endl;
    }
}
bool out_of_boundary(int x,int y)
{
    if(x<0 || y<0)
        return true;
    else if(x>4 || y>4)
        return true;
    return false;
}
bool has_word(int x,int y, string word, int count)
{
    if(count == 0)
    {
        if(board[x][y] == word.at(count))
            return has_word(x,y,word,count+1);
        else
            return false;
    }
    else
    {
        for (int i = 0; i < NUM_DIRECTIONS; ++i) {
            if(!out_of_boundary(x+adjacent_num[i][X], y+adjacent_num[i][Y]))
                if(board[x+adjacent_num[i][X]][y+adjacent_num[i][Y]] == word.at(count))
                {
                    if(word.length()-1 == count)
                        return true;
                    else
                        return has_word(x+adjacent_num[i][X],y+adjacent_num[i][Y], word, count+1);
                }
        }
        return false;
    }

}
