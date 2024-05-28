#include <stdio.h>
int value[10];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d",&value[i]);
    }
    int scope = n-1;
    int cnt=0;
    for (int i = 0; i<n; i ++)
    {
        for (int j = scope; j >= 0; j --)
        {
            if (value[j] <= k) 
            {
                scope = j;
                k-=value[j];
                cnt++;
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}