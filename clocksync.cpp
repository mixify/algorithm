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
// int walkSAT(vector <int> clock);
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
    printf("%d\n", minimum);
}

void press_switch(vector <int>* clock, int switch_index)
{
    for (int i = 0; i < 5; ++i) {
        if(switches[switch_index][i]!=-1)
            clock->at(switches[switch_index][i]) = (clock->at(switches[switch_index][i]) + 3) % 12;
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

    for (int i = 0; i < 4; ++i) {
        vector <int> switch_clock(clock);
        switch_count[switch_index]=i;
        for (int j = 0; j < i; ++j) {
            press_switch(&switch_clock, switch_index);
        }
        recursive_clock(switch_clock, switch_count, switch_index + 1);//include
    }
}

// int walkSAT(vector <int> clock)
// {
//     int maxflips = 100;
//     double p = 0.5;
//     for (int i = 0; i < maxflips; ++i) {
//         // printf("before : ");
//         // for (int j = 0; j < clock.size(); ++j) {
//         //     printf("%d ", clock[j]);
//         // }
//         // printf("\n");
//         vector <int> violated;
//         for (int j = 0; j < clock.size(); ++j) {
//             if(clock.at(j) != 12)
//                 violated.push_back(clock.at(j));
//         }
//         if(violated.size() == 0)//solved
//             return i;
//         // retmin;
//         int random_unsat_clock = rand()%violated.size();
//         double f = (double)rand() / RAND_MAX;
//         int selected;
//         if(f>p)
//         {
//             vector <int> random_including_switch; for (int j = 0; j < SWITCHES; ++j) {
//                 for (int k = 0; k < 5; ++k) {
//                     if(switches[j][k] == random_unsat_clock)
//                     {
//                         random_including_switch.push_back(j);
//                         break;
//                     }
//                 }
//             }
//             selected = random_including_switch.at(rand()%random_including_switch.size());
//             press_switch(&clock, selected);
//         }
//         else
//         {
//             int max= -1;
//             int max_index;
//             for (int j = 0; j < SWITCHES; ++j) {
//                 int count = 0;
//                 for (int k = 0; k < 5; ++k) {
//                     if(switches[j][k] != -1)
//                         if(clock.at(switches[j][k])+3 == 12)
//                             count++;
//                 }
//                 if(count > max)
//                 {
//                     max_index = j;
//                     max = count;
//                 }
//             }
//             selected = max_index;
//             // printf("p < 50 : %d selected\n", selected);
//             press_switch(&clock, max_index);
//         }
//         printf("after :  ");
//         for (int j = 0; j < clock.size(); ++j) {
//             printf("%d ", clock[j]);
//         }
//         printf("\n");
//         printf("------------------------------\n");
//     }
//     return -1;
//
// }
