#include <stdio.h>
int n, k;
int nums[(1 << 20) + 1];
void swap(int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = nums[i];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &k);
    int now = 2;
    int step = 0;
    for (int i = 0; i < k && step < k; i++, step++)
    {
        if (i * now >= n)
        {
            i = 0;
            now *= 2;
        }
        if (now <= 2)
        {
            if (nums[i * now] > nums[i * now + 1])
            {
                swap(i * now, i * now + 1);
            }
        }
        else
        {
            //now / 2 is sorted
            int p1=i*now, p2=i*now + now/2;
            for (int j = 0; p1 + j <i*now + now/2;j++)
            {
                
            }
        }
    }
}