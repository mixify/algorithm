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

using namespace std;
int N, D, prison;
int T;

pair<vector<int>,vector<double> > cache[51][101][101];
void solve_problem(int case_num);

class village
{
private:
public:
    int road_count;
    double possibility;
    double res;
    vector<int> dest;
    village()
    {
        road_count = 0;
        possibility = 0;
        res = 0;
    }
    void add_road(int num)
    {
        dest.push_back(num);
        road_count++;
        possibility = (double)1/(double)road_count;
    }
    void set_res(double p)
    {
        res += p;
    }
};

int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}
void check_all_village(vector<village> &villages,int village_num, int day, double p, vector<int> &trace)
{
    village &current_village = villages[village_num];
    pair<vector<int>,vector<double> > &ret = cache[village_num][day][trace.size()];
    if(ret.first.size() > 0) {//not ended guys could just end here
        // printf("at %d, %d\n", village_num, day);
        for (int i = 0; i < ret.first.size(); ++i) {
            // printf("add %d p %lf\n",ret.first[i], ret.second[i]);
            villages[ret.first[i]].set_res(ret.second[i]);
        }
        // printf("sibal\n");
        return;
    }
    // if(ret>= 0)
    // {
    //     printf("sibal\n");
    //     current_village.set_res(ret);//should set
    //     return;
    // }

    if(day == D)
    {
        // printf("at %d, %d\n", village_num, day);
        for (int i = 0; i < day; ++i) {
            cache[trace[i]][i][trace.size()].first.push_back(village_num);
            cache[trace[i]][i][trace.size()].second.push_back(p);
            // printf("setting %d , %d\n",trace[i], i);
        }
        current_village.set_res(p);//should set
        return;
    }
    double go_p;
    if(p!=0)
        go_p = p*current_village.possibility;
    else
        go_p = current_village.possibility;


    for (int i = 0; i < current_village.road_count; ++i) {
        trace.push_back(current_village.dest[i]);
        check_all_village(villages,current_village.dest[i],day+1, go_p,trace);
        trace.pop_back();
        // trace.pop_back();
    }

    // if(ret>=0) return ret;
}
void solve_problem(int case_num)
{
    vector<village> villages;
    cin>>N>>D>>prison;
    for (int i = 0; i < N; ++i) {
        villages.push_back(village());
        for (int j = 0; j < N; ++j) {
            int in; cin>>in;
            if(in==1)
                villages[i].add_road(j);
        }
    }
    cin>>T;
    vector<int> suspect;
    for (int i = 0; i < T; ++i) {
        int in; cin>>in; suspect.push_back(in);
    }
    // memset(cache, -1, sizeof(cache));
    vector<int> v;
    v.push_back(prison);
    check_all_village(villages, prison, 0,0,v);
    v.pop_back();
    for (int i = 0; i < T; ++i)
        printf("%lf ", villages[suspect[i]].res);
    printf("\n");
}
