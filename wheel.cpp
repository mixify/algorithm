#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <deque>
#include <utility>
#include <set>
#include <map>

int K;

using namespace std;
class Wheel
{

    public:
        int vals[8];
        int *right;
        int *left;
        int *top;

        Wheel(){}
        void init(int val[8])
        {
            for (int i = 0; i < 8; ++i) {
                vals[i] = val[i];
            }
            top = vals;
            right = vals+2;
            left = vals+6;
        }

        void clock(int ori)
        {
            if(ori==1)
            {
                int tmp = vals[7];
                memcpy(vals+1,vals,sizeof(int)*7);
                vals[0] = tmp;
            }
            else if(ori == -1)
            {
                int tmp = vals[0];
                memcpy(vals,vals+1,sizeof(int)*7);
                vals[7] = tmp;
            }
            else
                return;
        }
        void print()
        {
            for (int i = 0; i < 8; ++i) {
                printf("%d ",vals[i]);
            }
            printf("\n");
            printf("head = %d right = %d left = %d\n", *top,*right,*left);
        }
};

class Wheel_group
{
    friend Wheel;
    private:

    Wheel wheels[4];

    public:
    Wheel_group(int val[4][8])
    {
        for (int i = 0; i < 4; ++i) {
            wheels[i].init(val[i]);
        }

        // for (int i = 0; i < 4; ++i) {
        //     wheels[i].print();
        // j
    }
    void rotate(int idx, int ori)
    {
        idx--;
        int rt[4] = {0,0,0,0};
        int cur_ori = ori;
        rt[idx] = ori;
        for (int i = idx+1; i < 4; ++i) {
            if(*(wheels[i-1].right) != *(wheels[i].left))
            {
                cur_ori = -cur_ori;
                rt[i] = cur_ori;
            }
            else
                break;
        }
        cur_ori = ori;
        for (int i = idx-1; i >= 0; --i) {
            if(*(wheels[i+1].left) != *(wheels[i].right))
            {
                cur_ori = -cur_ori;
                rt[i] = cur_ori;
            }
            else
                break;
        }
        for (int i = 0; i < 4; ++i) {
            wheels[i].clock(rt[i]);
        }
    }
    void test()
    {
        for (int i = 0; i < 4; ++i) {
            wheels[i].print();
        }
        // wheels[0].clock_wise();
        // wheels[0].print();
        // wheels[0].clock_wise();
        // wheels[0].print();
        // wheels[0].clock_reverse();
        // wheels[0].print();
    }
    int calc()
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i) {
            if(*(wheels[i].top) == 1)
                sum+=pow(2,i);
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    int val[4][8];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf(" %1d",&val[i][j]);
        }
    }
    Wheel_group wheel_group = Wheel_group(val);

    scanf("%d",&K);
    // wheel_group.test();
    // printf("------------\n");
    for (int i = 0; i < K; ++i) {
        int idx, ori;
        scanf("%d %d",&idx, &ori);
        wheel_group.rotate(idx,ori);
        // wheel_group.test();
        // printf("-------------\n");
    }
    printf("%d",wheel_group.calc());
    return 0;
}

