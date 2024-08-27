#include <cstddef>
#include <stdio.h>
typedef struct nodedata
{
    int value;
    int parent;
    int c1, c2;
    int height = 0;
} node;
node a[100000];
int end = 0;
int get_BF(int index)
{
    int h1, h2;
    if (a[index].height == 0)
    {
        return 0;
    }
    if (a[a[index].c1].height == 0)
    {
        h1 = 0;
    }
    else {
        h1 = a[a[index].c1].height;
    }
    if (a[a[index].c2].height == 0)
    {
        h2 = 0;
    }
    else {
        h2 = a[a[index].c2].height;
    }
    return h1 - h2;
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