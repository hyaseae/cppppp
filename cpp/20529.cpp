#include <stdio.h>
short person[33];
int distance(short a, short b)
{
    short t = a ^ b;
    unsigned int r = 0;
    r += t & 1 ? 1 : 0;
    r += t & 2 ? 1 : 0;
    r += t & 4 ? 1 : 0;
    r += t & 8 ? 1 : 0;
    return r;
}
void tutturudutdututtuttutu(short n)
{
    int min = 333;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == j || j == k || k == i)
                    continue;
                cnt = distance(person[i], person[j]) + distance(person[i], person[k]) + distance(person[k], person[j]);
                if (min > cnt)
                {
                    min = cnt;
                }
            }
        }
    }
    printf("%d\n", min);
    return;
}
void test()
{
    int p;
    scanf("%d", &p);
    if (p > 32)
    {
        for (int i = 0; i < p; i++)
        {
            char k[5];
            scanf("%s", k);
        }
        printf("0\n");
    }
    else
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
        tutturudutdututtuttutu(p);
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