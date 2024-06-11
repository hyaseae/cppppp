#include <stdio.h>
int prime = 100000007;
long long int cache[50] = {1};
int pow(int n)
{
    if (cache[n]!= 0)
    {
        return (int)cache[n];
    }
    cache[n] = (pow(n-1)*31)%prime;
    return (int) cache[n];
}
int hashing(char* c)
{
    long long int ans = 0;
    for (int i = 0; c[i] != '\0'; i ++)
    {
        int k =((c[i] - 'a' + 1) * pow(i)); 
        ans += k;
        ans %= prime;
        printf("%lld %d %c\n",ans,k,c[i]);
    }
    return (int) ans;
}
int main()
{
    int result = 0;
    char str[50];
    scanf("%s",str);
    result = hashing(str);
    printf("%d\n",result);
    return 0;
}