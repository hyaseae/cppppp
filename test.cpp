#include <stdio.h>
long long int cache[50] = {1,31};
long long int pow(int n)
{
    if (cache[n]!= 0)
    {
        return cache[n];
    }
    else
    {
        cache[n] = (pow(n-1)*31)%1234567891;
        return cache[n];

    }
}
int main()
{
    printf("%lld\n",pow(10));
    printf("cache:%lld ",cache[0]);
    for (int i = 0; i < 10; i ++)
    {
        printf("%lld\n",cache[i]);
    }
}