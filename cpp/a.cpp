#include <stdio.h>
int main()
{
    int n;
    char name[20];
    scanf("%d",&n);
    scanf("%s",name);
    fflush(stdin);
    char ans[26] = {0};
    int length = 0;
    int throwed = 0;
    for (int i = 0; i < 20; i ++)
    {
        if (name[i] == '\0') break;
        char now = name[i];
        bool ok = 1;
        for (int j = 0; j < length; j ++)
        {
            if (now == ans[j])
            {
                ok = 0;
                throwed ++;
                break;
            }
        }
        if (ok) 
        {
            ans[length] = now;
            length ++;
        }
    }
    
    throwed += 4;
    
    printf("smupc_");
    for (int i = 1 - (throwed >= 10); i < 2; i ++)
    {
        printf("%d",throwed % 10);
        throwed/=10;
    }
    for (int i = length - 1; i >= 0; i ++)
    {
        printf("%c",ans[i]);
    }
    int a = 1906 + n;
    for (int i = 0; i < 4; i ++)
    {
        printf("%d",a%10);
        a/=10;
    }
}