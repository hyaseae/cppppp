#include <stdio.h>
int n,m,i,t,s,c;
int main()
{
    long long time = 1<<33;
    scanf("%d %d",&n,&t);
    for (i = 0; i < n; i ++)
    {
        scanf("%d %d %d",&s,&m,&c);
        for (int k = 0; k < c; k++)
        {
            int now = s + k*m;
            if (now - t> 0)
            {
                if (now - t < time)
                {
                    time = now - t;
                }
            }
        }
    }
    printf("%lld",time);
    return 0;
}