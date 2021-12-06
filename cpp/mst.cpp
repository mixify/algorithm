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

struct node{
    int parent;
    int height;
};

node group[10001];

void create_set(int i)
{
    group[i].parent = i;
    group[i].height = 0;
}

int find(int i)
{
    while(group[i].parent != i)
        i = group[i].parent;
    return i;
}

void merge(int a, int b)
{
    int n1 = find(a);
    int n2 = find(b);
    if(group[n1].height > group[n2].height)
    {
        if(group[n1].height == group[n2].height)
            group[n1].height++;
        group[n2].parent = n1;
    }
    else
        group[n1].parent = n2;
}
struct line{
    int n1;
    int n2;
    int p;
};

int compare(line l1, line l2)
{
    return l1.p < l2.p;
}

int main(int argc, char *argv[])
{
    cin>>N>>M;
    vector<line> lines;
    for (int i = 0; i < M; ++i) {
        int n1,n2,p;
        cin>>n1>>n2>>p;
        lines.push_back({n1,n2,p});
    }

    sort(lines.begin(), lines.end(), compare);

    for (int i = 1; i <= N; ++i)
        create_set(i);

    int j = 0;
    int cost = 0;
    for (int i = 0; i < N-1; ++i) {
        while(find(lines[j].n1) == find(lines[j].n2))
            j++;
        cost += lines[j].p;
        merge(lines[j].n1, lines[j].n2);
    }
    printf("%d\n", cost);
    return 0;
}
