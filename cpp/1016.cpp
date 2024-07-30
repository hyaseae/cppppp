#include <stdio.h>
#include <math.h>
short prime[1000002] = {0,0,1};
short is_ok[1000001];
int last_p_index = 2;
void fill_p_list(int n)
{
    for (int i = 2; i < n; i ++)
    {
        if (prime[i] == 1)
            for (int j = i; j < n; j += i)
            {
                prime[j] = 0;
            }
        
    }
}
int main()
{
    long long min,max;
    scanf("%lld %lld",&min,&max);
    fill_p_list(int(sqrt(max)));
    for (int i = 2; i < (int)sqrt(max); i ++)
    {
        
    }

    return 0;
}