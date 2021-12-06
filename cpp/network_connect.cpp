#include <stdio.h>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;

struct node{
    int height;
    int val;
    int parent;
};

struct line{
    int n1;
    int n2;
    int val;
};

node comp[1001];

void create_set(int num)
{
    comp[num].parent = num;
    comp[num].height = 1;
}

int find(int num)
{
    while(comp[num].parent != num)
        num = comp[num].parent;
    return num;
}
void merge(int n1, int n2)
{
    int idx1 = find(n1);
    int idx2 = find(n2);

    if(comp[idx1].height >= comp[idx2].height)
    {
        if(comp[idx1].height == comp[idx2].height)
            comp[idx1].height++;
        comp[idx2].parent = idx1;
    }
    else
        comp[idx1].parent = idx2;
}

int compare(line l1, line l2)
{
    return l1.val < l2.val;
}
int main(int argc, char *argv[])
{
    cin>>N>>M;

    vector<line> lines;

    for (int i = 0; i < M; ++i) {
        int from, to, val;
        cin>>from>>to>>val;
        lines.push_back({from,to,val});
    }

    for (int i = 1; i <= N; ++i)
        create_set(i);

    sort(lines.begin(), lines.end(), compare);

    int j = 0;
    int cost = 0;

    for (int i = 0; i < N-1; ++i)
    {
        while(find(lines[j].n1) == find(lines[j].n2))
            j++;
        merge(lines[j].n1,lines[j].n2);
        cost += lines[j].val;
    }

    printf("%d\n", cost);

    return 0;
}
