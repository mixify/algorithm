#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int num_student;
int num_pair;
int count_case;
void solve_problem(int case_num);
void get_pairs(vector< pair<int,int> > friends, vector<int>  v, int num);
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
    vector< pair<int,int> > friends;
    cin>>num_student;
    cin>>num_pair;
    for (int i = 0; i < num_pair; ++i) {
        pair<int,int> p;
        int a,b;
        cin>>a>>b;
        p.first = a;
        p.second= b;
        friends.push_back(p);
    }
    vector<int> v;
    count_case = 0;
    get_pairs(friends,v,0);
    cout<<count_case<<endl;
}
void get_pairs(vector< pair<int,int> > friends, vector<int>  v, int num)
{
    if(v.size() == num_student)
    {
        count_case++;
        return;
    }
    else if(num == num_pair)
        return;
    //don't include
    get_pairs(friends, v, num+1);
    //include
    // cout<<"including "<<num<<endl;
    // cout<<"cur_size = "<<friends.size()<<endl;
    int first,second;
    first = friends.at(num).first;
    second = friends.at(num).second;
    for (int st : v) {
        if(first == st || second == st)
            return;
    }
    v.push_back(first);
    v.push_back(second);
    // cout<<"pushing "<<first<<" "<<second<<endl;
    // vector<pair<int,int> >::iterator p = friends.begin();
    // while (p != friends.end())
    // {
    //     if(p->first == first || p->first == second)
    //         p = friends.erase(p);
    //     else if(p->second == first || p->second == second)
    //         p = friends.erase(p);
    //     else
    //         ++p;
    // }
    // cout<<"after_size = "<<friends.size()<<endl;
    get_pairs(friends, v, num+1);
}
