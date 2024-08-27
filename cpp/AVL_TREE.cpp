#include <cstddef>
#include <stdio.h>
const int NO_CHILD = 100001;
typedef struct nodedata
{
    int value;
    int parent;
    int c1 = NO_CHILD, c2 = NO_CHILD;
    int is_empty = 1;
} node;
node a[100000];
int end = 0;
int max(int a, int b)
{
    return a > b ? a : b;
}
int get_height(int pos)
{
    int h1 = -1, h2 = -1;
    if (a[pos].is_empty == 1)
    {
        return -1;
    }
    if (a[a[pos].c1].is_empty == 0)
    {
        h1 = get_height(a[pos].c1) + 1;
    }
    else if (a[a[pos].c2].is_empty == 0)
    {
        h2 = get_height(a[pos].c2) + 1;
    }
    return max(h1, h2);
}
int get_BF(int index)
{
    int h1, h2;
    if (get_height(index) <= 0)
    {
        return 0;
    }
    h1 = get_height(a[index].c1);
    h2 = get_height(a[index].c2);
    return h1 - h2;
}
int find_parent(int from = 0)
{
    if (end == 0)
    {
        return -1;
    }
    if (a[a[from].c1].is_it_leaf == 0)
    {
        return find_parent(a[from].c1);
    }
    else
    {
        return a[from].c1;
    }
}
void swap_node_for_print(int a1, int a2)
{
    node t = a[a1];
    a[a1] = a[a2];
    a[a2] = t;
}
void print_node()
{
    if (end == -1)
    {
        return;
    }
    for (int i = 0; i < end; i++)
    {
        printf("%d %d", a[i].value, get_BF(i));
    }
}
void put(int value)
{
    a[end] = {value, find_parent(), 100001, 100001, 0, 1};
    end++;
    return;
}
int main()
{
    int n;
    ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].value);
    }
}