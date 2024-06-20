#include <math.h>
#include <stdio.h>
#include <time.h>
typedef long long int lld;
lld rnd = 0;
const lld p1 = 100000007;
const lld p2 = 100000009;
const lld p3 = 2147483647;
const int dim_max = 10;

lld dim[dim_max];

int mode = 0;
lld now_front_num = 0;
int dim_maybe = 0;
int plus = 1;
float start, end;

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
    long long ms = ts.tv_nsec / 1000; 
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
void push_(lld num, int dim_now)
{
    dim[dim_now] += num;
}
void show_dim()
{
    for (int i = 0; i < dim_max; i++)
    {
        printf("%lld ", dim[i]);
    }
    printf("\n");
}
void what()
{
    push_(now_front_num * plus, dim_maybe);
    // show_dim();
    now_front_num = 0;
    dim_maybe = 0;
    mode = 0;
}
double normal_function(double x)
{
    double ans = 0;
    // printf("%f %f", start, end);
    for (int i = 0; i < dim_max; i++)
    {
        if (dim[i] == 0)
            continue;

        ans += std::pow(x, i) * dim[i];
        // printf("%f\n", ans);
    }
    return ans;
}
double normal_integral(float start, float end)
{
    double ans = 0;
    // printf("%f %f", start, end);
    for (int i = 0; i < dim_max; i++)
    {
        if (dim[i] == 0)
            continue;

        ans -= std::pow(start, i + 1) * dim[i] / (i + 1);
        // printf("%f\n", ans);
    }
    for (int i = 0; i < dim_max; i++)
    {
        if (dim[i] == 0)
            continue;
        ans += std::pow(end, i + 1) * dim[i] * 1 / (i + 1);
        // printf("%f\n", ans);
    }

    return ans;
}

int check_in(double x_cord, double y_cord)
{
    if (y_cord <= normal_function(x_cord))
    {
        return 1;
    }
    return 0;
}
double monte_calro(int cnt = 10000, double height = 10000.0)
{
    lld count;
    double range = end - start;
    double field = height * range;
    for (int i = 0; i < cnt; i++)
    { // cnt 개 점에서 성립 확인
        double x_cord = randfrom(start, end);
        double y_cord = randfrom(0, height);
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
    printf("one function\nformat:(2x^2+5)>");
    char c = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            continue;
        if (c == 'x')
        {
            mode = 1;
            continue;
        }
        if (c == '^')
        {
            continue;
        }
        if (c == '+' || c == '-')
        {
            if (now_front_num == 0)
                continue;
            if (dim_maybe == 0)
            {
                dim_maybe = 1;
                // what();
                // printf("F");
            }
            what();
        }
        if (c == '+')
        {
            plus = 1;
            continue;
        }
        if (c == '-')
        {
            plus = -1;
            continue;
        }

        if (mode == 0)
        {
            now_front_num *= 10;
            now_front_num += c - '0';
        }
        else if (mode == 1)
        {
            dim_maybe *= 10;
            dim_maybe += c - '0';
        }
    }
    if (mode == 1 && dim_maybe == 0)
    {
        dim_maybe = 1;
    }
    else if (mode == 0 && dim_maybe == 0)
    {
        dim_maybe = 0;
    }
    what();

    show_dim();
    printf("where to where\n>");
    scanf("%f %f", &start, &end);
    printf("this is your integral haha\n>'%f'\n", normal_integral(start, end));
    printf("now monte carlo\n>'%f'\n", monte_calro(10000000));
    return 0;
}
