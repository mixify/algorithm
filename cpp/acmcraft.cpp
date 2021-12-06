#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

int num_building;
int num_constarint;
int goal_building;

int cache[1001];
class building
{
private:

public:
    vector<int> constraint;
    int building_time;
    bool considered;
    building()
    {
        building_time= 0;
        considered = false;
    }
    building(int time)
    {
        building_time= time;
        considered = false;
    }
    void add_constraint(int num)
    {
        constraint.push_back(num);
    }
    void add_constraint_by(int num)
    {
        constraint.push_back(num);
    }
    // void resolution_constraint(int num)
    // {
    //
    // }
    bool is_independent()
    {
        return constraint.size()==0;
    }
};
void solve_problem(int case_num);
int build_solve(vector<building> &builds, int building_num);
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
    vector<building> builds;
    cin>>num_building>>num_constarint;
    builds.push_back(building());
    for (int i = 0; i < num_building; ++i) {
        int input; cin>>input;
        builds.push_back(building(input));
    }
    for (int i = 0; i < num_constarint; ++i) {
        int c1,c2; cin>>c1>>c2;
        builds[c2].add_constraint_by(c1);
    }
    cin>>goal_building;
    memset(cache, -1, sizeof(cache));
    // build_solve(builds,1,builds[1].building_time);
    build_solve(builds,goal_building);
    printf("%d\n", cache[goal_building]);
}

int build_solve(vector<building> &builds, int building_num)
{
    // builds[building_num].considered = true;
    int &ret = cache[building_num];
    // building_time+=builds[building_num].building_time;

    if(ret!= -1)
    {
        // if(ret < building_time)
        //     return ret = building_time;
        // else
        return ret;
    }

    // if(building_num == goal_building)
    //     return builds[building_num].building_time;
    if(builds[building_num].is_independent())
        return ret = builds[building_num].building_time;
    int total = -1;
    for (int i = 0; i < builds[building_num].constraint.size(); ++i) {
        int &cons = builds[building_num].constraint[i];
        total = max(build_solve(builds,cons), total);
        // printf("%d %d\n", total, build_solve(builds,cons, building_time));
    }

    return ret = builds[building_num].building_time + total;
}
// int build_solve(vector<building> builds, int building_num, int building_time)
// {
//     builds[building_num].considered = true;
//     // if(building_num == goal_building)
//     //     return builds[building_num].building_time;
//     if(cache[building_num] < building_time)
//         cache[building_num] = building_time;
//     else
//         return cache[building_num];
//     for (int i = 0; i < builds[building_num].constraint.size(); ++i) {
//         int &cons = builds[building_num].constraint[i];
//         build_solve(builds,cons, building_time + builds[cons].building_time);
//     }
//     // for (int i = 1; i <= num_building; ++i) {
//     //     if(!builds[i].considered)
//     //         build_solve(builds,i,builds[i].building_time);
//     // }
// }
