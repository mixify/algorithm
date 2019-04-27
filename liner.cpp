#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n;
int q;

double quan[100];
double price[100];

vector<pair<double,double> > sets;

double predict(double val, pair<double,double> p1, pair<double,double> p2)
{
    if(p1.first==p2.first)
    {
        return p1.first;
    }
    else
    {
        double slope = ((p2.second-p1.second)/(p2.first-p1.first));
        double intercept = p1.second;
        return slope*(val-p1.first) + intercept;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int val;
    cin>>val>>q;
    for(int i = 0 ; i < q ; i++)
        cin>>quan[i];
    cin>>q;
    for(int i = 0 ; i < q ; i++)
        cin>>price[i];

    for(int i = 0 ; i < q ; i++)
    {
        if(price[i] > 0)
        {
            sets.push_back(make_pair(quan[i],price[i]));
        }
    }

    if(sets.size()==1) printf("%.2f\n", sets[0].second);
    // cout<<val;
    for(int j = 0 ; j < sets.size()-1 ; j++)
    {
        pair<double,double> p1;
        pair<double,double> p2;
        if(val<sets[0].first)
        {
            p1 = sets[0];
            p2 = sets[1];
            printf("%.2f\n", predict(val,p1,p2));
            break;
        }
        else if(val>=sets[j].first && val<=sets[j+1].first)
        {
            p1 = sets[j];
            p2 = sets[j+1];
            printf("%.2f\n", predict(val,p1,p2));
            break;
        }
        if(val > sets[sets.size()-1].first)
        {
            p1 = sets[sets.size()-2];
            p2 = sets[sets.size()-1];
            printf("%.2f\n", predict(val,p1,p2));
            break;
        }

    }

    return 0;
}


