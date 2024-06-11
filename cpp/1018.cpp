#include <stdio.h>
short board[50][50];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j<m; j++)
        {
            char c;
            scanf("%c",&c);
            if (c == 'B') board[i][j] = 1;
            else if (c == 'W') board[i][j] = 0;
            else {
                j--;
                continue;
            }
        }
    }
    /*
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j<m; j++)
        {
            printf("%d,",board[i][j]);
        }
        printf("\n");
    }
    */
    int cnt = 65;
    for (int i = 0; i <= n-8; i ++)
    {
        for (int j = 0; j <= m-8; j++)
        {
            int cntnow1=0,cntnow2 = 0;
            for (int k = i; k < i + 8; k ++)
            {
                for (int l = j; l < j + 8; l ++)
                {
                    if (board[k][l]==(k+l)%2) cntnow1 ++;
                    else cntnow2 ++;
                    //printf("%d %d,",cntnow1,cntnow2);
                }
            }
            if (cntnow1 < cnt) 
            {
                cnt = cntnow1;
            }
            if (cntnow2 < cnt) 
            {
                cnt = cntnow2;
            }
        }
    }
    printf("%d",cnt);
}