#include <stdio.h>
int tape[100000];
int now_index = 50000;
int min_index = now_index;
int temp[10000];
void init_tape()
{
    for (int i = 0; i < 100000; i++)
    {
        tape[i] = 0;
    }
    now_index = 50000;
    min_index = now_index;
}
void init_temp()
{
    for (int i = 0; i < 10000; i++)
    {
        temp[i] = 0;
    }
}
int get_temp(int j)
{
    int n = 0;
    int k = 1;
    for (int i = 1; i <= j; i++)
    {
        n += temp[j - i] * k;
        k *= 2;
    }
    return n;
}
void get_int()
{
    int i = min_index;
    int cnt = 0;
    int cnt1 = 0;
    int j = 0;
    init_temp();
    while (1)
    {
        i++;
        if (tape[i] == 0)
        {
            cnt++;
            if (cnt1 == 1)
            {
                temp[j] = 0;
                j++;
            }
            else if (cnt1 == 2)
            {
                temp[j] = 1;
                j++;
            }
            else if (cnt1 == 3)
            {
                int a = get_temp(j);
                printf("%d,", a);
                init_temp();
                j = 0;
            }
            cnt1 = 0;
            if (cnt >= 2)
            {
                break;
            }
        }
        else
        {
            cnt = 0;
            cnt1++;
        }
    }
}
void go_left()
{
    now_index--;
    if (now_index < min_index)
        min_index = now_index;
}
void go_right()
{
    now_index++;
}
void show_tape()
{
    int i = min_index;
    int cnt = 0;
    while (1)
    {
        printf("%d ", tape[i]);
        i++;
        if (tape[i] == 0)
        {
            cnt++;
            if (cnt >= 2)
            {
                break;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    printf("\n");
}
void show_num()
{
    int i = min_index;
    int cnt = 0;
    int cnt1 = 0;
    while (1)
    {
        i++;
        if (tape[i] == 0)
        {
            cnt++;
            if (cnt1 == 1)
            {
                printf("0");
            }
            else if (cnt1 == 2)
            {
                printf("1");
            }
            else if (cnt1 == 3)
            {
                printf(",");
            }
            else if (cnt1 == 4)
            {
                printf("+");
            }
            else if (cnt1 == 5)
            {
                printf("-");
            }
            cnt1 = 0;
            if (cnt >= 2)
            {
                break;
            }
        }
        else
        {
            cnt = 0;
            cnt1++;
        }
    }
}
void input_bit(int c)
{
    tape[now_index] = c;
    go_right();
}
void input_colon()
{
    input_bit(0);
    input_bit(1);
    input_bit(1);
    input_bit(1);
}
void input_zero_to_one(int c)
{
    if (c == 0)
    {
        input_bit(0);
        input_bit(1);
    }
    else if (c == 1)
    {
        input_bit(0);
        input_bit(1);
        input_bit(1);
    }
}
void input_plus_minus(int c)
{
    if (c == 1)
    {
        input_bit(0);
        input_bit(1);
        input_bit(1);
        input_bit(1);
        input_bit(1);
    }
    else if (c == -1)
    {
        input_bit(0);
        input_bit(1);
        input_bit(1);
        input_bit(1);
        input_bit(1);
        input_bit(1);
    }
}
void input_num(int decimal)
{
    int num = decimal;
    if (num >= 0)
    {
        input_plus_minus(1);
    }
    else
    {
        input_plus_minus(-1);
        num = -num;
    }

    short llong[32];
    int i = 31;
    for (i = 31; i >= 0; i--)
    {
        printf("%d\n", num);
        llong[31 - i] = num % 2;
        num /= 2;
        if (num == 0)
            break;
    }
    for (int j = 31 - i; j >= 0; j--)
    {
        // printf("%d", llong[j]);
        input_zero_to_one(llong[j]);
    }
    input_colon();
}
int main()
{
    char a;

    while (1)
    {
        scanf("%c", &a);
        a -= '0';
        if (a == 1)
        {
            show_tape();
        }
        else if (a == 0)
        {
            break;
        }
        else if (a == 2)
        {
            show_num();
        }
        else if (a == 3)
        {
            int c;
            scanf("%d", &c);
            input_zero_to_one(c);
        }
        else if (a == 4)
        {
            int c;
            scanf("%d", &c);
            input_num(c);
        }
        else if (a == 5)
        {
            input_colon();
        }
        else if (a == 6)
        {
            get_int();
        }
        else if (a == 7)
        {
            for (int i = 1; i < 10; i++)
            {
                input_num(i);
            }
        }
        else if (a + '0' == '+')
        {
            input_plus_minus(1);
        }
        else if (a + '0' == '-')
        {
            input_plus_minus(-1);
        }
        else if (a + '0' == 'f')
        {
            init_tape();
        }
    }
}