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

#define NOCHILD -1

using namespace std;
int N, M;

int widest = 0;
int widest_d = 0;
class Node
{
public:
    int left;
    int right;
    int num;
    int depth;
    int x;
    bool root;
    void set_Node(int n, int l, int r)
    {
        num = n;
        left = l;
        right = r;
        if(root!=false)
            root = true;
    }
    Node()
    {
        root = true;
    }
    void not_root() {root = false;}
};

Node node[10001];

int in_order(int idx, int depth, int x)// L root R
{
    node[idx].depth = depth;
    int lc_count = 0;
    int rc_count = 0;
    if(node[idx].left!=NOCHILD)
        lc_count = in_order(node[idx].left, depth+1,x);

    x+=lc_count;
    // printf("%d : %d %d\n",idx,depth,x );
    if(node[idx].right!=NOCHILD)
        rc_count = in_order(node[idx].right, depth+1,x+1);

    node[idx].x = x;

    return lc_count + rc_count + 1;
}
int main(int argc, char *argv[])
{
    cin>>N;
    int root;
    vector<int> node_idx;
    for (int i = 0; i < N; ++i) {
        int node_num, left_child, right_child;
        cin>>node_num>>left_child>>right_child;
        node_idx.push_back(node_num);
        node[node_num].set_Node(node_num,left_child,right_child);
        if(left_child!=-1)
            node[left_child].not_root();
        if(right_child!=-1)
            node[right_child].not_root();
    }
    for (int i = 0; i < node_idx.size(); ++i) {
        if(node[node_idx[i]].root)
        {
            // printf("%d is root\n", node_idx[i]);
            root = node_idx[i];
        }
    }

    in_order(root,1,0);
    int calc[10001][2];
    memset(calc,0,sizeof(calc));
    for (int i = 1; i <= N; ++i) {
        if(calc[node[i].depth][0] == 0)
        {
            calc[node[i].depth][0] = node[i].x;
            calc[node[i].depth][1] = node[i].x;
        }
        else
        {
            if(calc[node[i].depth][0] > node[i].x) calc[node[i].depth][0] = node[i].x;
            if(calc[node[i].depth][1] < node[i].x) calc[node[i].depth][1] = node[i].x;
        }
    }
    for (int i = 1; i <= 10000; ++i) {
        int wide = calc[i][1] - calc[i][0] + 1;
        if(wide>widest)
        {
            widest_d = i;
            widest = wide;
        }
    }
    printf("%d %d\n", widest_d, widest);
    return 0;
}

