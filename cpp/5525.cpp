#include <stdio.h>
int cnt, mode, last;
int main()
{
    char before = '\0';
    int n;
    int cnts[100001];
    scanf("%d", &n);
    int t;
    scanf("%d\n", &t);
    char c = '\0';
    for (int i = 0; i < t; i++)
    {
        before = c;
        scanf("%c", &c);
        if (mode)
        {
            if (c != 'O' && c != 'I')
            {
                i--;
                continue;
            }
            if (before == 'I')
            {
                if (c == 'O')
                {
                }
                else
                {
                    cnts[last] = cnt;
                    cnt = 0;
                    mode = 1;
                    last++;
                }
            }
            else
            {
                if (c == 'I')
                {
                    cnt++;
                }
                else
                {

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
    if (mode)
    {
        cnts[last] = cnt;
        cnt = 0;
        mode = 0;
        last++;
    }
    int ans = 0;
    for (int i = 0; i < last; i++)
    {
        if (cnts[i] - n >= 0)
        {
            ans += cnts[i] - n + 1;
        }
    }
    printf("%d", ans);
    return 0;
}