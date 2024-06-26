#include <stdio.h>
short person[33];
void test()
{
    int p;
    scanf("%d", &p);
    if (p > 32)
    {
        printf("0");
        for (int i = 0; i < p; i++)
        {
            char k[5];
            scanf("%s", k);
        }
    }
    if (p > 16)
    {
        for (int i = 0; i < p; i++)
        {
            char k[5];
            scanf("%s", k);
            short num = 0;
            num += k[0] == 'E';
            num <<= 1;
            num += k[1] == 'S';
            num <<= 1;
            num += k[2] == 'F';
            num <<= 1;
            num += k[3] == 'P';
            num <<= 1;
            person[i] = num;
        }
        
    }
    for (int i = 0; i < p; i++)
    {
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        test();
    }
}