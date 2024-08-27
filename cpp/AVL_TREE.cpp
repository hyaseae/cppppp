#include <stdio.h>
typedef struct nodedata {
    int value;
    int parent;
    int c1,c2;
    int height = 0;
    short BF = 0;
} node;
node a[100000];
int end = 1;
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
    for (int i = 0; i < end; i ++)
    {
        printf("%d %d",a[i].value,a[i].BF);
    }
}
int main()
{
    int n;;
    scanf("%d",&n);
    for (int i = 0 ; i < n; i ++)
    {
        scanf("%d",&a[i].value);
    }
}