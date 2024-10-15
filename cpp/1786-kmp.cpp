#include <stdio.h>
int k[1000000];
char T[1000000];
char P[1000000];
void calc_kmp()
{
    k[0] = 0;
    int i = 0;
    int j = 1;
    while (P[j] != '\0')
    {
        if (P[i] == P[j])
        {
            //abcabcabc
            //a b c a b c 
            if ((j + 1) < (i + 1) * 2)
            {
                j++;
                continue;
            }
            k[j] = k[j - 1] + 1;
        }
        else
        {
            i = 0;
        }
        i++;
        j++;
    }
    i = 0;
    while (P[i] != '\0')
    {
        printf("%d ", k[i]);
        i++;
    }
}
int main()
{
    scanf("%s\n", T); // 원본
    scanf("%s", P);   // 찾는거
    calc_kmp();
    return 1;
}