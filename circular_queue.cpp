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
int N, M;

int main(int argc, char *argv[])
{
    cin>>N>>M;
    vector<int> numbers;
    for (int i = 0; i < M; ++i) {
        int num; cin>>num; numbers.push_back(num);
    }
    int queue_size = N;
    int current = 1;
    int count = 0;
    for (int i = 0; i < M; ++i) {
        count += min(min(abs(numbers[i] - current), current + queue_size - numbers[i]), queue_size-current + numbers[i]);
        for (int j = i+1; j < M; ++j)
            if(numbers[j] > numbers[i])
                numbers[j]--;
        current = numbers[i];
        if(current==queue_size)
            current = 1;
        queue_size--;
    }
    cout<<count<<endl;
    return 0;
}
