#include <stdio.h>
int a[100000];
void what()
{
    for (auto i :a)
    {
        printf("%d ",i);
    }
}
int main()
{
    int n;;
    scanf("%d",&n);
    for (int i = 0 ; i < n; i ++)
    {
        scanf("%d",&a[i]);
    }
}