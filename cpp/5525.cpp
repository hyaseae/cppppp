#include <stdio.h>
int cnt,mode,last;
char before;
int main()
{
    int n;
    int cnts[10001];
    scanf("%d", &n);
    int t;
    scanf("%d\n",&t);
    char c = '\0';
    for (int i = 0; i < t; i ++)
    {
        before = c;
        scanf("%c",&c);
        if (mode)
        {
            if (before == 'I')
            {
                if (c == 'O')
                {
                }
                else {
                    cnts[last] = cnt;
                    cnt = 0;
                    mode = 1;
                    last++;
                }
            }
            else {
                if (c=='I')
                {
                    cnt++;
                }
                else {
                    
                    cnts[last] = cnt;
                    cnt = 0;
                    mode = 0;
                    last++;
                }
            }
        }
        else
        {
            if (c == 'I')
            {
                mode = 1;
                continue;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < last; i ++)
    {
        if (cnts[i] - n >= 0)
        {
            ans += cnts[i] - n + 1;
        }
    }
    printf("%d",ans);
    return 0;
}