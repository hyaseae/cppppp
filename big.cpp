#include <stdio.h>
short person[50][2];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%hd %hd",&person[i][0],&person[i][1]);
    }
    for (int i = 0; i < n; i ++)
    {
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (person[i][0] < person[j][0] && person[i][1] < person[j][1]) cnt++;
        }
        printf("%d ",cnt);
    }
    return 0;
}