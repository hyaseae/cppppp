#include <stdio.h>
#include <time.h>
typedef long long int lld;
lld rnd = 0;
const lld p1 = 100000007;
const lld p2 = 100000009;
const lld p3 = 2147483647;
const int dim_max = 10;

lld a, b, c, d, e, f;
float end, start;

float more_power(float what, int how)
{
    if (how <= 0)
        return 1;
    if (what == 0)
    {
        return 0;
    }
    return more_power(what, how - 1) * what;
}
void init_rand(lld seed = 0)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    long long ms = ts.tv_nsec / 1000; // Convert nanoseconds to milliseconds
    if (seed == 0)
        seed = ms;
    rnd = seed;
}
lld rng()
{
    rnd += p1;
    rnd *= p2;
    rnd %= p3;
    return rnd;
}
double randfrom(double min, double max)
{
    double range = (max - min);
    double div = p3 / range;
    return min + (rng() / div);
}

double normal_function(double x, double y)
{
    return a * more_power(x, 2) + b * more_power(y, 2) + c * x * y + d * x + e * y + f;
}

int check_in(double x_cord, double y_cord)
{
    if (0 >= normal_function(x_cord, y_cord))
    {
        return 1;
    }
    return 0;
}
double monte_calro(int cnt = 1000, double height = 10.0)
{
    lld count;
    double range = end - start;
    double field = 2 * height * range;
    for (int i = 0; i < cnt; i++)
    { // cnt 개 점에서 성립 확인
        double x_cord = randfrom(start, end);
        double y_cord = randfrom(-height, height);
        if (check_in(x_cord, y_cord))
        {
            count += 1;
        }
    }
    return (float)count * field / (float)cnt;
}
void test_rand()
{
    for (int j = 0; j < 20; j++)
    {
        int less1 = 0;
        int more1 = 0;
        for (int i = 0; i < 10000; i++)
        {
            double d = randfrom(0, 1000);
            // printf("%f\n", d);
            if (d <= 1)
            {
                less1++;
            }
            else
            {
                more1++;
            }
        }
        printf("%d %d\n", less1, more1);
    }
}
int main()
{
    init_rand(0);
    printf("one function\nformat:(a b c d e f)for ax^2 + by^2 + cxy + dx + ey + f>");
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
    printf("where to where\n>");
    scanf("%f %f", &start, &end);
    double height1 = 0.0;
    printf("max?(if you don't know, then input 0\n>");
    scanf("%lf", &height1);
    if (height1 == 0)
    {
        height1 = 10.0;
    }
    printf("now monte carlo\n>'%f'\n", monte_calro(100000000, height1));
    return 0;
}
