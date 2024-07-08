#include <stdio.h>
int min, max, n, i;
short nums[100000][3];
// 뭐야 이거 어카지
int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%hd", &nums[i][j]);
        }
    }

    return 0;

} // 대체 이거 왜 그 밑줄 안뜸
