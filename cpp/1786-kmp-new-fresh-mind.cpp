#include <stdio.h>
int k[1000000];
char T[1000000];
char P[1000000];
int cnt[1000000];
int i, j, check;
int num;
void calc_kmp()
{
    check = 1;
    int streak = 0;
    int streak_checking = 1;
    i = 0;
    j = 1;
    while (check)
    {
        if (i != 0)
        {
            if (streak_checking)
            {
                if (P[i - 1] == P[i])
                {
                    streak++;
                }
                else
                {
                    streak_checking = 0;
                }
            }
        }

        if (P[i] == P[j])
        {
            if ((i + 1) * 2 > (j + 1))
            {
                if (streak == i)
                {
                    streak--;
                    // aaaa
                    k[j] = k[j - 1] - 1;
                }
                else
                {
                    i = 0;
                    if (P[i] == P[j])
                    {
                        k[j] = 1;
                    }
                    // ababa
                }
            }
            else
            {
                k[j] = k[j - 1] + 1;
                i++;
            }
        }
        else
        {
            i = 0;
        }
        j++;
        if (P[j] == 0)
        {
            check = 0;
        }
    }
}
void print_ki()
{
    for (int a = 0; P[a] != 0; a++)
    {
        printf("%d ", k[a]);
    }
}
int kmp()
{
    int a = 0;
    int matched = 0;
    // 뜌땨땨뜌땨뜌
    // 뜌땨뜌

    // 뜌땨야
    // 뜌땨야

    // 뜌땨야 뜌땨야우뜌땨 뜌땨야우뜌땨야우뜌땨우아
    // 뜌땨야우뜌땨우
    for (a = 0; T[a] != 0; a++)
    {
        if (T[a] == P[matched])
        {
            matched++;
        }
        else
        {
            if (matched != 0)
            {
                matched = k[matched - 1];
                a--;
            }
        }
        if (P[matched] == 0)
        {
            break;
        }
    }
    return a - matched + 2;
}
int main()
{
    char c;
    int k = 0;
    while (1)
    {
        scanf("%c", &c);
        if (c == '\n')
            break;
        T[k] = c;
        k++;
    }
    k = 0;
    while (1)
    {
        scanf("%c", &c);
        if (c == '\n')
            break;
        P[k] = c;
        k++;
    }
    // printf("\n\n%s\n", T);
    calc_kmp();
    // print_ki();
    printf("%d", kmp());
    return 1;
    // aabaaabaaabaaabaaaba <- 반례
    // 01012001200120012001?
    // aabaabaabaabaabaabaab
    // 010123120123456789120
    // 오 해치웠나?
}