#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

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

int diff(int a,int b)
{
    return a>b?a-b:b-a;
}
void solve_problem(int case_num)
{
    int count;
    scanf("%d", &count);
    vector<int> fence;
    int max_height = 0;
    int max_size = 0;
    for (int i = 0; i < count; ++i) {
        int size;
        scanf("%d", &size);
        if(size > max_height)
            max_height = size;
        fence.push_back(size);
    }
    // int height;
    // int width;
    // int max_width;
    // int cur_size;
    // int before_size;
    for (int height = 1; height <= max_height; ++height) {
        int width = 0;
        for (int j = 0; j < fence.size(); ++j) {
            if(fence[j] < height)
            {
                width=0;
            }
            else
            {
                width++;
                if(height * width > max_size)
                    max_size = height * width;
            }
        }
    }
    printf("%d\n", max_size);
        // if(i==0)
        // {
        //     height = max_size = fence[i];
        //     before_size = cur_size = fence[i];
        // }
        // else
        // {
        //     width++;
        //     height = min(height, fence[i]);
        //     cur_size = width*height;
        //     if(before_size < cur_size)// shrinking
        //     {
        //
        //     }
        //     else
        //     {
        //         if(cur_size > max_size)
        //             max_size= cur_size;
        //     }
        //     before_size = cur_size;
        // }
}
