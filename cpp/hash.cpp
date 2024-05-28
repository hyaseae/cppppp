#include <stdio.h>
long long int cache[50] = {1};
long long int pow(int n)
{
    if (cache[n]!= 0)
    {
        return cache[n];
    }
    cache[n] = (pow(n-1)*31)%1234567891;
    return cache[n];
}
int hashing(char* c)
{
    int ans;
    for (int i = 0; c[i] != '\0'; i ++)
    {
        
    }
}
int main()
{
    long long int result = 0;
    int n;
    scanf("%d\n",&n);
    for (int i = 0; i < n; i ++)
    {
        char c;
        scanf("%c",&c);
        result += ((c - 'a' + 1) * pow(i))%1234567891;
    }
    printf("%lld\n",result);
    return 0;
}