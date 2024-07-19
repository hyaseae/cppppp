#include <stdio.h>
int first, second, streak=1, cnt=1,max_cnt=1;
int main()
{
    int n = 0;
    scanf("%d",&n);
    int t;
    scanf("%d",&t);
    second = t;
    for (int i = 1; i < n; i ++)
    {
        scanf("%d",&t);
        if (t==second)
        {
            cnt++;
            streak++;
        }
        else if (t == first)
        {
            first = second;
            second = t;
            cnt++;
            streak = 1;
        }
        else
        {
            if (cnt > max_cnt)
            {
                max_cnt = cnt;
            }
            first = second;
            second = t;
            cnt = streak + 1;
            streak = 1;
        }
    }
    if (cnt > max_cnt)
    {
        max_cnt = cnt;
    }
    printf("%d\n",max_cnt);
    return 0;
}