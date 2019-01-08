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
        void set_quadrant(QuadTree* divided, int count)
        {
            quadrant[count].divided = divided;
        }
        int get_quadrant_count()
        {
            return quadrant_count;
        }
        void get_reverse_quadrant()
        {
            // QuadTree* qt = new QuadTree();
            // QuadTree* qt = new QuadTree();
            // qt->set_quadrant(quadrant[2]);
            // qt->set_quadrant(quadrant[3]);
            // qt->set_quadrant(quadrant[0]);
            // qt->set_quadrant(quadrant[1]);
            for (int i = 0; i < NUM_QUADRANT; ++i) {
                if(quadrant[reversed_iterate[i]].color == 'w' || quadrant[reversed_iterate[i]].color == 'b')
                    printf("%c",quadrant[reversed_iterate[i]].color);
                else
                {
                    printf("x");
                    quadrant[reversed_iterate[i]].divided->get_reverse_quadrant();
                }
            }
        }
};

// square qtree[20][4];

void solve_problem(int case_num);
void print_tree(QuadTree *qt);
QuadTree* reverse_tree(QuadTree *qt);
int main(int argc, char *argv[])
{
    int cases;
    cin>>cases;
    getchar();
    for (int i = 0; i < cases; ++i) {
        solve_problem(i);
    }
    return 0;
}

void solve_problem(int case_num)
{
    string quadtree;
    getline(cin,quadtree);

    int divide_count = 0;
    stack<QuadTree *> trees;
    QuadTree *qt, *first_qt;
    if(quadtree.length() <= 1)
    {
        cout<<quadtree<<endl;
        return;
    }
    // printf("------------------\n");
    int quadrant_count = 0;
    int max_depth = 0;
    for (int i = 0; i < quadtree.length(); ++i)
    {
        if(quadtree.at(i) == 'w')//its white
            qt->set_quadrant('w');
        else if(quadtree.at(i) == 'b')//its black
            qt->set_quadrant('b');
        else if(quadtree.at(i) == 'x')//its divided
        {
            QuadTree *new_qt = new QuadTree();
            if(i == 0)
                first_qt = new_qt;
            else
                qt->set_quadrant(new_qt);
            trees.push(qt);
            int size = trees.size();
            if(size > max_depth)
                max_depth = size;
            qt = new_qt;
        }
        if(qt->get_quadrant_count() == NUM_QUADRANT)
        {
            qt = trees.top();
            trees.pop();
        }
    }

    // printf("%d\n", max_depth);//2^n * 2^n is data's size
    // printf("x");
    // print_tree(first_qt);
    // printf("\n");

    printf("x");
    first_qt->get_reverse_quadrant();
    // print_tree(reverse_qt);
    printf("\n");

    // for (int i = 0; i < NUM_QUADRANT; ++i) {
    //     if(reverse_qt->quadrant[i].color != 'w' && reverse_qt->quadrant[i].color != 'b')
    //     {
    //
    //     }
    // }
    // for (int i = 0; i < NUM_QUADRANT; ++i) {
    //     if(first_qt->quadrant[i].color == 'w' || first_qt->quadrant[i].color == 'b')
    //         printf("%c\n", first_qt->quadrant[i].color);
    //     else
    //         printf("divided\n");
    // }
}

void print_tree(QuadTree *qt)
{
    for (int i = 0; i < NUM_QUADRANT; ++i) {
        if(qt->quadrant[i].color == 'w' || qt->quadrant[i].color == 'b')
            printf("%c", qt->quadrant[i].color);
        else
        {
            printf("x");
            print_tree(qt->quadrant[i].divided);
        }
    }
}
// void parseTree(QuadTree *qt,string str)
// {
//     if(i==str.length())
//         return;
//     if(str.at(i) == 'w')//its white
//         qt->set_quadrant('w');
//     else if(str.at(i) == 'b')//its black
//         qt->set_quadrant('b');
//     else if(str.at(i) == 'x');//its divided
//     {
//         QuadTree *new_qt= new QuadTree();
//
//         qt->set_quadrant(new_qt);
//         trees.push(qt);
//         qt = new_qt;
//         // ++i;
//         parseTree(qt, str);
//     }
//     if(qt->get_quadrant_count() == 4)
//     {
//         qt = trees.top();
//         trees.pop();
//     }
//     ++i;
//     parseTree(qt, str);
// }
