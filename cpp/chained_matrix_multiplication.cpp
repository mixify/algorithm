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
vector<pair<int,int> > matrix;
int cache[501][501];

int chained_matrix_multiplication(int x, int y)
{
    int &ret = cache[x][y];
    if(x==y) return ret = 0;
    if(ret!=-1) return ret;

    int mm = INT_MAX;
    for (int k = x; k < y; ++k) {
        printf("(%d,%d)=%d + (%d,%d)=%d + value = %d * %d * %d\n", x,k,chained_matrix_multiplication(x,k),k+1,y,chained_matrix_multiplication(k+1,y),matrix[x].first,matrix[k].second,matrix[y].second);
        mm = min(mm,chained_matrix_multiplication(x,k) + chained_matrix_multiplication(k+1,y)
                + matrix[x].first * matrix[k].second * matrix[y].second);
    }

    printf("%d %d = %d\n", x,y,mm);
    return ret = mm;
}
int main(int argc, char *argv[])
{
    cin>>N;
    for (int i = 0; i < N; ++i) {
        int row,col; cin>>row>>col; matrix.push_back(make_pair(row,col));
    }


    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; i+j < N; ++j) {
    //         int k = i+j;
    //         if(j==k)
    //             cache[j][k] = 0;
    //         else
    //         {
    //             cache[j][k] = min(cache[k][k], + matrix[j].first * matrix[j].second * matrix[k].second);
    //         }
    //         // printf("(%d,%d) ",j,k );
    //     }
    //     // printf("\n");
    // }
    memset(cache,-1,sizeof(cache));
    printf("%d\n", chained_matrix_multiplication(0,N-1));
    return 0;
}
// 0,0 1,1 2,2 3,3 4,4
// 0,1 1,2 2,3 3,4
// 0,2 1,3 3,4
// 0,3 1,4
// 0,4
