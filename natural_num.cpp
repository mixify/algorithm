#include <iostream>
#include <vector>
using namespace std;

int N;
int min_n,max_n;
vector<int> number;

// int cache[20001];

// int best_natural(int x, int y)
// {
//
// }
int main(int argc, char *argv[])
{
    cin>>N;
    min_n = 20000; max_n = 0;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; number.push_back(in);
        if(in<min_n) min_n = in;
        if(in>max_n) max_n = in;
    }
    int best = 99999999;
    int best_num = 0;
    for (int i = min_n; i < max_n; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) sum+=abs(number[j]-i);
        if(sum<best)
        {
            best = sum;
            best_num = i;
        }
    }
    printf("%d\n", best_num);
    // memset(cache,-1,sizeof(cache));
    // best_natural(0,N-1);

    return 0;
}
