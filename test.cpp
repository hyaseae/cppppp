#include <stdio.h>
int queue[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    //n = 4;
    for (int i = 0; i < n; i ++)
    {
        queue[i] = i+1;
    }
    int last_index = n;
    for (int i = 0; i < 2*n-2; i +=2)
    {
        queue[i] = 0;
        queue[last_index] = queue[i+1];
        queue[i+1]=0;
        last_index++;
    }
    printf("%d",queue[last_index-1]);
}