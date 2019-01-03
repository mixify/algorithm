#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>

#define CLOCKS 16
#define SWITCHES 10
using namespace std;

int minimum;

const int switches[10][5] = {{0,1,2,-1,-1}, {3,7,9,11,-1}, {4,10,14,15,-1}, {0,4,5,6,7},
    {6,7,8,10,12}, {0,2,14,15,-1}, {3,14,15,-1,-1}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13}};

void solve_problem(int case_num);
void recursive_clock(vector <int> clock, vector <int> switch_count, int switch_index);
int main(int argc, char *argv[])
{
    srand(1823);
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void solve_problem(int case_num)
{
    vector<int> clock;
    minimum = 9999;
    for (int i = 0; i < CLOCKS ; ++i) {
        int time;
        scanf("%d", &time);
        if(time == 12)
            time = 0;
        clock.push_back(time);
    }
    vector <int> switch_count;
    for (int i = 0; i < 10; ++i) {
        switch_count.push_back(0);
    }
    recursive_clock(clock, switch_count, 0);
    if(minimum == 9999)
        minimum = -1;
    printf("%d\n", minimum);
}

void press_switch(vector <int>* clock, int switch_index, int count)
{
    for (int i = 0; i < 5; ++i) {
        if(switches[switch_index][i]!=-1)
            clock->at(switches[switch_index][i]) = (clock->at(switches[switch_index][i]) + 3 * count) % 12;
    }
}

void recursive_clock(vector <int> clock, vector <int> switch_count, int switch_index)
{
    bool comp = true;
    if(switch_index == SWITCHES)
        return;
    for (int i = 0; i < CLOCKS; ++i) {
        if(clock[i] != 0)
        {
            comp = false;
            break;
        }
    }
    if(comp)
    {
        int count = 0;
        for (int i = 0; i < SWITCHES; ++i)
            count += switch_count[i];
        if(count < minimum)
            minimum = count;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        vector <int> switch_clock(clock);
        switch_count[switch_index]=i;
        press_switch(&switch_clock, switch_index, i);
        recursive_clock(switch_clock, switch_count, switch_index + 1);//include
    }
}
