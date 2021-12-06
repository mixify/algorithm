#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> number;
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int in; cin>>in; number.push_back(in);
    }

    sort(number.begin(),number.end());
    printf("%d\n", N%2==0?number[N/2-1]:number[N/2]);
    // memset(cache,-1,sizeof(cache));
    // best_natural(0,N-1);

    return 0;
}
