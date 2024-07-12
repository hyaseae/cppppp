#include <stdio.h>
int d[100003];
int n;

int big(int a, int b)
{
    return a > b ? a : b;
}
int small(int a, int b)
{
    return a < b ? a : b;
}
void show(int from = 1, int to1 = 0)
{
    int to = to1 == 0 ? n : to1;
    for (int i = from; i <= to; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
}
void swap(int a, int b)
{
    int t = d[a];
    d[a] = d[b];
    d[b] = t;
}

void Qsort(int from, int to)
{
    //printf("from:%d to:%d\n", from, to);
    if (to - from < 1)
        return;
    if (to - from == 1)
    {
        if (d[to] < d[from])
        {
            swap(from, to);
            return;
        }
    }
    int a = 0, b = 0, c = 0;
    int pivot = 0;
    int pivot_index = 0;
    a = d[from];
    b = d[to];
    c = d[(from + to) / 2];
    if (a > small(b, c) && big(b, c) > a) // a 중앙
    {
        ;
    }
    else if (b > small(a, c) && big(a, c) > b) // b 중앙
    {
        swap(from, to);
    }
    else
    {
        swap((from + to) / 2, from);
    }
    // c 중앙
    pivot = d[from];
    int low = from;
    int high = to;
    pivot_index = from;
    int out = 0;
    while (out == 0)
    {
        while (1)
        {
            // show(from,to);
            // printf("low:%d d:%d\n",low,d[low]);
            if (d[low] > pivot)
            {
                break;
            }
            if (low > high)
                break;
            low++;
        }
        // low 찾음
        while (1)
        {
            // show(from,to);
            // printf("high:%d d:%d\n",high,d[high]);
            if (d[high] < pivot)
            {
                break;
            }
            if (low > high)
                break;
            high--;
        }
        if (low > high)
            break;

        swap(low, high);
        // printf("swaped:");
        // show();
    }
    swap(high, pivot_index);
    pivot_index = high;
    // 왼 작 오 큼

    Qsort(from, pivot_index - 1);
    Qsort(pivot_index + 1, to);

    return;
}

int main()
{
    freopen("../in2.txt", "r", stdin);

    while (1)
    {
        n++;
        scanf("%d", &d[n]);
        if (d[n] == 0)
            break;
    }
    Qsort(1, n - 1);
    printf("r:");
    show(1, n - 1);
}
//  14 10 6 3 9 5 7 8 4
// 10 5 6 2 9 8 1 7 3 4
/*
 */