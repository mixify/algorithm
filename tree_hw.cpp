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

int widest = 1;
int widest_d = 1;
class Node
{
public:
    int left;
    int right;
    int num;
    int depth;
    int parent;
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
        parent = -1;
    }
    void set_parent(int p)
    {
        parent = p;
    }
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
    vector <int> node_idx;
    int node_num, left_child, right_child;
    for (int i = 0; i < N; ++i) {
        cin>>node_num>>left_child>>right_child;
        node_idx.push_back(node_num);
        node[node_num].set_Node(node_num,left_child,right_child);
        if(left_child!=-1)
            node[left_child].set_parent(node_num);
        if(right_child!=-1)
            node[right_child].set_parent(node_num);
    }
    while(node[node_num].parent!=-1)
        node_num=node[node_num].parent;
    root = node_num;
    // printf("%d\n", root);

    in_order(root,1,1);
    int calc[10001][2];
    memset(calc,0,sizeof(calc));
    for (int i = 0; i < node_idx.size(); ++i) {
        int idx = node_idx[i];
        if(calc[node[idx].depth][0] == 0)
        {
            calc[node[idx].depth][0] = node[idx].x;
            calc[node[idx].depth][1] = node[idx].x;
        }
        else
        {
            if(calc[node[idx].depth][0] > node[idx].x) calc[node[idx].depth][0] = node[idx].x;
            if(calc[node[idx].depth][1] < node[idx].x) calc[node[idx].depth][1] = node[idx].x;
            int wide = calc[node[idx].depth][1] - calc[node[idx].depth][0] + 1;
            if(wide > widest)
            {
                widest_d = node[idx].depth;
                widest = wide;
            }
        }
    }
    printf("%d %d\n", widest_d, widest);
    return 0;
}

