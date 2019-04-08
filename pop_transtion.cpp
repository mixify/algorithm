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
int L,R;
int country[51][51];

int main(int argc, char *argv[])
{
    cin>>N;
    cin>>L>>R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>country[i][j];
        }
    }
    int open_count;
    do{
        open_count = 0;
        for (int i = 0; i < N-1; ++i) {
            for (int j = 0; j < N-1; ++j) {
                if(abs(country[i][j] - country[i+1][j]) >= L && abs(country[i][j] - country[i+1][j]) <= R)
                {
                    open_count++;
                }
                if(abs(country[i][j] - country[i][j+1]) >= L && abs(country[i][j] - country[i][j+1]) <= R)
                {
                    open_count++;
                }
            }
        }

    }while(open_count > 0);
    return 0;
}

