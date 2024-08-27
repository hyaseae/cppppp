#include <queue>
#include <stdio.h>
const int NO_CHILD = 100001;
typedef struct nodedata
{
    int value;
    int parent;
    int c1 = NO_CHILD, c2 = NO_CHILD;
    int not_empty = 0;
} node;
node a[100002];
int end = 0;
int max(int c, int b)
{
    return c > b ? c : b;
}
int absolute(int k)
{
    return k > 0 ? k : -k;
}
void swap_node_for_print(int a1, int a2)
{
    node t = a[a1];
    a[a1] = a[a2];
    a[a2] = t;
}
int get_height(int pos)
{
    int h1 = 0, h2 = 0;
    if (a[pos].not_empty == 0)
    {
        return -1;
    }
    if (a[pos].c1 != NO_CHILD)
    {
        h1 = get_height(a[pos].c1) + 1;
    }
    if (a[pos].c2 != NO_CHILD)
    {
        h2 = get_height(a[pos].c2) + 1;
    }
    return max(h1, h2);
}
int get_BF(int index)
{
    int h1, h2;
    h1 = get_height(a[index].c1);
    h2 = get_height(a[index].c2);
    return h1 - h2;
}
void print_node()
{
    std::queue<int> Q_now;
    std::queue<int> Q_later;
    Q_now.push(0);
    while (1)
    {
        if (Q_now.empty() && Q_later.empty())
        {
            printf("\n");
            break;
        }
        else if (Q_now.empty())
        {
            for (int i = 0; i < Q_later.size(); i++)
            {
                Q_now.push(Q_later.front());
                Q_later.pop();
            }
            printf("\n");
        }
        else
        {
            int now = Q_now.front();
            printf("%d-%d ", a[now].value, get_BF(now));
            if (a[now].c1 != NO_CHILD)
                Q_later.push(a[now].c1);
            if (a[now].c2 != NO_CHILD)
                Q_later.push(a[now].c2);
            Q_now.pop();
        }
    }
    if (end == -1)
    {
        return;
    }
    for (int i = 0; i < end; i++)
    {
        printf("%d %d\n", a[i].value, get_BF(i));
    }
}
int find_parent(int from = 0)
{
    if (end == 0)
    {
        return -1;
    }
    if (a[from].c1 != NO_CHILD)
    {
        return find_parent(a[from].c1);
    }
    else if (a[from].c2 != NO_CHILD)
    {
        return find_parent(a[from].c2);
    }
    else
    {
        return from;
    }
}
void LL(int where)
{
    int child = a[where].c1;
    if (a[child].c2 != NO_CHILD)
    {
        a[a[child].c2].parent = where;
    }
    a[child].c2 = where;
    a[child].parent = a[where].parent;
    a[where].parent = child;
}
void RR(int where)
{
    int child = a[where].c2;
    if (a[child].c1 != NO_CHILD)
    {
        a[a[child].c1].parent = where;
    }
    a[child].c1 = where;
    a[child].parent = a[where].parent;
    a[where].parent = child;
}
void LR(int where)
{
    RR(a[where].c1);
    LL(where);
}
void RL(int where)
{
    LL(a[where].c2);
    RR(where);
}
void check(int where)
{
    if (a[where].parent == -1)
    {
        return;
    }
    int p = a[where].parent;
    if (a[p].parent == -1)
    {
        return;
    }
    int grandparent = a[p].parent;
    if (get_BF(grandparent))
        return;
}
void put(int value)
{
    int p = find_parent();
    a[end] = {value, p};
    a[end].not_empty = 1;
    if (p == -1)
    {
        ;
    }
    else if (a[p].c1 == NO_CHILD)
    {
        a[p].c1 = end;
    }
    else if (a[p].c2 == NO_CHILD)
    {
        a[p].c2 = end;
    }
    else
    {
        printf("ERERRRRERRR");
        return;
    }
    check(end);
    end++;
    print_node();
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        put(k);
    }
}