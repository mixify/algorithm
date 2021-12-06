#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void solve_problem(int case_num);
int max_size;
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void cut_rectangle(vector<int> fence);
void solve_problem(int case_num)
{
    int count;
    scanf("%d", &count);
    vector<int> fence;
    max_size = 0;
    // int max_height = 0;
    for (int i = 0; i < count; ++i) {
        int size;
        scanf("%d", &size);
        // if(size > max_height)
        //     max_height = size;
        fence.push_back(size);
    }
    int height;
    int width;
    // int max_width;
    // int cur_size;
    // int before_size;

    cut_rectangle(fence);
    // for (int height = 1; height <= max_height; ++height) {
    //     int width = 0;
    //     for (int j = 0; j < fence.size(); ++j) {
    //         if(fence[j] < height)
    //         {
    //             width=0;
    //         }
    //         else
    //         {
    //             width++;
    //             if(height * width > max_size)
    //                 max_size = height * width;
    //         }
    //     }
    // }



    printf("%d\n", max_size);
}
void cut_rectangle(vector<int> fence,int index, int height, int width)
{
    if(i == -1 || i == fence.size())
        return;
    // if(fence[index] > fence[index-1])
    if(height > fence[index])
        ;
    cut_rectangle(fence, index-1, );
    cut_rectangle(fence, index+1, );
}
