#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M, K;
int A[11][11];// 1부터 시작하는거는 헤깔리지 말게 이렇게 풀자 앞으로...
int nut[11][11];

int dy[8] = {-1,0,1,-1,0,1,1,-1};
int dx[8] = {-1,-1,-1,1,1,1,0,0};
set<pair<int,int> > tree;
deque<int> tree_on_land[11][11];
vector<pair<pair<int,int>,int> > dead_tree;
vector<pair<int,int> > added_tree;
// 자료구조가 루프를 돌면서 변형되는 거라면 잘 고려하자 복사를 하던

void solve_problem(int case_num);
int main(int argc, char *argv[])
{
    solve_problem(0);
    return 0;
}

void solve_problem(int case_num)
{
    cin>>N>>M>>K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin>>A[i][j];
            nut[i][j] = 5;
        }
    }
    for (int i = 0; i < M; ++i) {
        int y,x;
        int age;
        cin>>y>>x>>age;
        tree.insert(make_pair(y,x));
        tree_on_land[y][x].push_back(age);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            sort(tree_on_land[i][j].begin(),tree_on_land[i][j].end());
        }
    }
    int cnt = M;
    for (int i = 0; i < K; ++i)
    {
        // printf("-----------------------\n");
        //spring
        auto idx_itr = set<pair<int,int> >::iterator();
        for (idx_itr = tree.begin(); idx_itr != tree.end();)//set 은 !=로 순회 검사
        {

            auto tree_itr = deque<int>::iterator();
            bool over = false;
            for (tree_itr = tree_on_land[idx_itr->first][idx_itr->second].begin(); tree_itr != tree_on_land[idx_itr->first][idx_itr->second].end();)
            {
                // printf("tree_on = %d\n", tree_on_land[3][1].size());
                // printf("at %d %d : nut = %d age = %d\n",idx_itr->first,idx_itr->second,nut[idx_itr->first][idx_itr->second],*tree_itr);
                if(*tree_itr > nut[idx_itr->first][idx_itr->second])
                {
                    // printf("die\n");
                    tree_itr = tree_on_land[idx_itr->first][idx_itr->second].erase(tree_itr);
                    // erase 리턴값으로 꼭 가야한다 까먹지 말자 시벌
                    dead_tree.push_back(make_pair(make_pair(idx_itr->first,idx_itr->second),*tree_itr));
                    if(tree_on_land[idx_itr->first][idx_itr->second].size()==0)
                    {
                        // printf("itsover\n");
                        over = true;
                        idx_itr = tree.erase(idx_itr);
                        break;
                    }
                }
                else
                {
                    // printf("alive\n");
                    nut[idx_itr->first][idx_itr->second]-=*tree_itr;
                    ++(*tree_itr);
                    ++tree_itr;
                }
            }
            if(!over)
                idx_itr++;
        }
        //summer
        for (int j = 0; j < dead_tree.size(); ++j) {
            int a,b;
            a = dead_tree[j].first.first;
            b = dead_tree[j].first.second;

            nut[a][b] += dead_tree[j].second/2;
        }
        // printf("cnt = %d\n", cnt);
        cnt-=dead_tree.size();
        dead_tree.clear();

        //fall;
        for (idx_itr = tree.begin(); idx_itr != tree.end();idx_itr++)//set 은 !=로 순회 검사
        {
            auto tree_itr = deque<int>::iterator();
            // bool over = false;
            for (tree_itr = tree_on_land[idx_itr->first][idx_itr->second].begin(); tree_itr != tree_on_land[idx_itr->first][idx_itr->second].end();tree_itr++) {
                if(*tree_itr % 5 == 0)
                {
                    for (int j = 0; j < 8; ++j) {
                        int a = idx_itr->first+dy[j];
                        int b = idx_itr->second+dx[j];
                        if(a>=1 && a<=N && b>=1 && b<=N)
                        {
                            // printf("new kids : %d %d\n",a,b);
                            added_tree.push_back(make_pair(a,b));
                        }
                    }

                }
            }
        }
        // printf("%d + %d\n", cnt, added_tree.size());
        cnt+=added_tree.size();
        for (int j = 0; j < added_tree.size(); ++j) {
            int y = added_tree[j].first;
            int x = added_tree[j].second;
            tree.insert(make_pair(y,x));
            tree_on_land[y][x].push_front(1);
        }
        added_tree.clear();

        //winter
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                nut[j][k]+=A[j][k];
            }
        }

    }
    printf("%d\n", cnt);
}
