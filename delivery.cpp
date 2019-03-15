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
int N;
vector<int> product;
int pay_truck, pay_helicopter;

int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i)
    {
        int in; cin>>in; product.push_back(in);
    }
    cin>>pay_truck>>pay_helicopter;
    return 0;
}
