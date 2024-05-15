#include <stdio.h>
int not_fun_heap[100001];
int main()
{
    int n,a;
    bool yes_zero = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
    {
        
        scanf("%d",&a);
        if (a == 0)
        {
            yes_zero = 1;
        }
        int now = a;
        int index_now = 1;
        while (1)
        {
            if (a == 0) break;
            if (not_fun_heap[index_now] == 0) 
            {
                not_fun_heap[index_now] = now;
                break;
            }

        }
    }

    int m;
    scanf("%d",&m);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d",&a);
        if (a == 0) printf("%d",yes_zero);
    }

    return 0;
}