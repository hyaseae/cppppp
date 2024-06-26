#include <stdio.h>
const int P = 1000000007;
int val[P + 1] = {0, 1, 1};
int fibo(long long int n)
{
    if (n % P == 0)
    {
        return 0;
    }
    if (val[n % P] != 0)
        return val[n % P];
    val[n % P] = fibo(n % P - 1) + fibo(n % P - 2);
    return val[n % P];
}

int main()
{
    printf("%d", fibo(1));
    return 0;
}