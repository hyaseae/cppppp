#include <stdio.h>
#include <math.h>
const double epsilon = 0.0000000001;
typedef double llu;
llu cache[1000] = {1.0, 1.0};
llu d_cache[1000] = {1.0, 1.0, 2.0, 3.0};
double double_fac(int n)
{
    if (n <= 1)
        return 1.0;
    if (cache[n] != 0)
        return cache[n];
    return cache[n] = double_fac(n - 2) * n;
}
double fac(int n)
{
    if (n <= 1)
        return 1.0;
    if (cache[n] != 0)
        return cache[n];
    return cache[n] = fac(n - 1) * n;
}
double dis(double k)
{
    if (k >= 0)
        return k;
    else
        return -1.0 * k;
}
int main()
{
    printf("e:%.15lf\n", exp(1));
    printf("pi:%.15lf\n", M_PI);
    double e, pi = 0;
    for (int i = 0; i < 20; i++)
    {
        e += 1.0 / fac(i);
        if (dis(e - exp(1)) <= epsilon)
        {
            printf("%.10lf\n", dis(e - exp(1)));
            printf("times to plausible number:%d\n", i);
            break;
        }
    }
    printf("%.15lf\n", e);

    for (int i = 0; i < 120; i += 2)
    {
        // what?
        pi += double_fac(2 * i - 1) / double_fac(2 * i) / (2 * i + 1);
        if (dis(pi - M_PI / 2) <= epsilon)
        {
            printf("%.10lf\n", dis(pi - M_PI / 2));
            printf("times to plausible number:%d\n", i);
            break;
        }
    }
    printf("%.10lf\n", pi * 2);
    printf("err for e: %.15lf\n err for pi:%.10lf",(exp(1)-e)/e,(M_PI-pi)/M_PI);

    return 0;
}