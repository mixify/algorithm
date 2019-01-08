#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>

#define NUM_QUADRANT 4
using namespace std;

class QuadTree;
typedef union SQU{
    int color;
    QuadTree *divided;
}square;
const int reversed_iterate[4] = {2,3,0,1};
class QuadTree{
    private:
        int quadrant_count;

    public:
        square quadrant[NUM_QUADRANT];
        QuadTree()
        {
            for (int i = 0; i < NUM_QUADRANT; ++i) {
                quadrant[i].color = -1;
            }
            quadrant_count = 0;
        }
        void set_quadrant(int color)
        {
            quadrant[quadrant_count++].color = color;
        }
        void set_quadrant(QuadTree* divided)
        {
            quadrant[quadrant_count++].divided = divided;
        }
        void set_quadrant(square squ)
        {
            if(squ.color == 'w' || squ.color == 'b')
                quadrant[quadrant_count++].color = squ.color;
            else
                quadrant[quadrant_count++].divided = squ.divided;
        }
        int get_quadrant_count()
        {
            return quadrant_count;
        }
        void get_reverse_quadrant()
        {
            for (int i = 0; i < NUM_QUADRANT; ++i) {
                if(quadrant[reversed_iterate[i]].color == 'w' || quadrant[reversed_iterate[i]].color == 'b')
                    printf("%c",quadrant[reversed_iterate[i]].color);
                else
                {
                    printf("x");
                    // if(quadrant[reversed_iterate[i]].color!=-1)
                        quadrant[reversed_iterate[i]].divided->get_reverse_quadrant();
                }
            }
        }
};

void solve_problem(int case_num);
void free_tree(QuadTree *qt);
QuadTree* reverse_tree(QuadTree *qt);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void solve_problem(int case_num)
{
    char quadtree[1001] = {0,};

    // getline(cin,quadtree);
    scanf("%s",quadtree);

    int divide_count = 0;
    stack<QuadTree *> trees;
    QuadTree *qt, *first_qt;
    if(quadtree[0] != 'x')
    {
        cout<<quadtree<<endl;
        return;
    }
    for (int i = 0; quadtree[i] != 0; ++i)
    {
        if(quadtree[i] == 'w')//its white
            qt->set_quadrant('w');
        else if(quadtree[i] == 'b')//its black
            qt->set_quadrant('b');
        else if(quadtree[i] == 'x')//its divided
        {
            QuadTree *new_qt = new QuadTree();
            if(i == 0)
                first_qt = new_qt;
            else
                qt->set_quadrant(new_qt);
            trees.push(qt);
            qt = new_qt;
        }
        while(qt->get_quadrant_count() == NUM_QUADRANT)
        {
            qt = trees.top();
            trees.pop();
        }
    }


    printf("x");
    first_qt->get_reverse_quadrant();
    free_tree(first_qt);
    printf("\n");
}

void free_tree(QuadTree *qt)
{
    for (int i = 0; i < NUM_QUADRANT; ++i) {
        if(qt->quadrant[i].color == 'w' || qt->quadrant[i].color == 'b')
            ;
        else
            free_tree(qt->quadrant[i].divided);
    }
    delete[] qt;
}
